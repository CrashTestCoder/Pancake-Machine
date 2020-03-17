#include <iostream>
#include <fstream>
#include <future>
#include <wiringPi.h>
#include <thread>
#include <chrono>
#include <wiringSerial.h>
#include <string_view>
#include <sstream>
#include <iomanip>
#include <vector>

#include "pca9685.h"
#include "Flipper.hpp"
#include "Mixer.hpp"

class WiringPiSetupBeforeOtherStuff
{
public:
    WiringPiSetupBeforeOtherStuff() { wiringPiSetupGpio(); }
} _setup;

int Servo::fd = pca9685Setup(Servo_Info::PIN_BASE, 0x40, Servo_Info::freq);
int Relay::fd = serialOpen("/dev/ttyACM0", 115200);

Mixer mixer { Mixer_Info::dispense_pin, Mixer_Info::mix_pin };
Mixer hopper { Hopper_Info::dispenser_pin, Hopper_Info::vibrator_pin };
Flipper flipper;
Relay water_pump { Water_Pump_Info::pump_pin };

using namespace std;

std::string dispTime(auto time)
{
    auto const hours = std::chrono::duration_cast<std::chrono::hours>(time);
    auto const minutes = std::chrono::duration_cast<std::chrono::minutes>(time -= hours);
    auto const seconds = std::chrono::duration_cast<std::chrono::seconds>(time -= minutes);
    
    std::vector const times { 
        hours.count(),
        minutes.count(),
        seconds.count() 
    };
    
    std::stringstream outs;
    for(auto t : times)
    {
        if(t || !outs.str().empty()) 
        {
            if(!outs.str().empty())
                outs << setw(2) << setfill('0');
            outs << t << ':';
        }
    }
    std::string out = outs.str();
    if(!out.empty())
        out.pop_back();

    return out;
}

void countdown(auto t, std::string_view cnt = "", std::string_view postmsg = "")
{
    std::cout << ' ';
    for(auto time = t; time > 0.0s; time-=1.0s)
    {
        std::cout << "\r                                                                \r" << cnt << dispTime(time) << std::flush;
        std::this_thread::sleep_for(1s);
    }
    std::cout << "\r                                                                    \r" << postmsg << '\n';
}

void flip()
{
    //flipper.goToStartPosition();

    /**********************************/
    /**         Flip Pancake          */
    /**********************************/
    flipper.setJoint(Z,30);
    flipper.update();
    
    flipper.setJoint(X,200);      // slide under pancake
    flipper.update();

    flipper.setJoint(X, 250);
    flipper.setJoint(Y, 20);
    flipper.setJoint(Z,180);        // lift
    flipper.update();              // maybe can remove this
    
    countdown(Flipper_Info::flip_pickup_time, "Picking up Pancake: ", "Picked up Pancake");
    flipper.flip(1);
    countdown(Flipper_Info::flip_time, "Flipping: ", "Flipped Pancake");
    flipper.flip(0);
    
    flipper.setJoint(X, 0);
    flipper.setJoint(Y, 0);
    flipper.update();
}

void serve()
{
    flipper.setJoint(Z, 30);
    flipper.update();
    
    flipper.setJoint(X,200);      // slide under pancake
    flipper.update();

    flipper.setJoint(Z,180);        // lift
    flipper.update();               // maybe can remove this
    
    flipper.setJoint(X,230);
    flipper.setJoint(Y, 300);
    flipper.update();

    countdown(Flipper_Info::serve_pickup_time, "Serving: ", "Served");
    flipper.flip(1);
    std::this_thread::sleep_for(Flipper_Info::serve_time);
    flipper.flip(0);
    
    flipper.setJoint(X, 0);
    flipper.setJoint(Y, 0);
    flipper.update();
    
}

int main()
{
    if(Servo::fd < 0)
        std::cout << Servo::fd;
    
    auto add_water = std::thread([]{
        water_pump.set(1);
        std::this_thread::sleep_for(Water_Pump_Info::pump_time);
        water_pump.set(0);
    });
    
    auto add_mix = std::thread([]{
        hopper.mix(1);
        hopper.dispense(1);
        std::this_thread::sleep_for(Hopper_Info::dispense_time);
        hopper.mix(0);
        hopper.dispense(0);
    });
    
    add_water.join();
    add_mix.join();
    
    /******************************/
    /**          Mixing           */
    /******************************/
    mixer.mix(true);
    //while(1);
    countdown(Cooking_Times::mix_time, "Mixing: ", "Mixed");

    /******************************/
    /**        Dispencing         */
    /******************************/
    mixer.dispense(1);
    //while(1);
    countdown(Cooking_Times::mix_dispence_time, "Dispencing: ", "Dispenced");

    mixer.mix(false);
    mixer.dispense(0);

    /******************************/
    /**          Cooking          */
    /******************************/
    countdown(Cooking_Times::side_1_cook_time, "Cooking Side 1: ", "Side 1 Cooked");

    flip();
    countdown(Cooking_Times::side_2_cook_time, "Cooking Side 2: ", "Side 2 Cooked");

    /******************************/
    /**          Serving          */
    /******************************/
    serve();
    std::cout << "done\n";
    
    //serialListener.join();
}
