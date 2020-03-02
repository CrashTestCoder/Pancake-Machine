#include <iostream>
#include <fstream>
#include <future>
#include <wiringPi.h>
#include <thread>
#include <chrono>
#include <wiringSerial.h>
#include <string_view>

#include "Flipper.hpp"
#include "Mixer.hpp"

Mixer mixer;
Flipper flipper;

using namespace std;

template<typename T>
void countdown(auto t, std::string_view cnt = "", std::string_view postmsg = "")
{
    std::cout << ' ';
    for(auto time = std::chrono::duration_cast<T>(t); time > 0s; time--)
    {
        std::cout << "\r                                                                \r" << cnt << time.count() << std::flush;
        std::this_thread::sleep_for(T { 1 });
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
    
    countdown<std::chrono::seconds>(Flipper_Info::flip_pickup_time, "Picking up Pancake: ", "Picked up Pancake");
    flipper.flip(1);
    countdown<std::chrono::seconds>(Flipper_Info::flip_time, "Flipping: ", "Flipped Pancake");
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

    countdown<std::chrono::seconds>(Flipper_Info::serve_pickup_time, "Serving: ", "Served");
    flipper.flip(1);
    std::this_thread::sleep_for(Flipper_Info::serve_time);
    flipper.flip(0);
    
    flipper.setJoint(X, 0);
    flipper.setJoint(Y, 0);
    flipper.update();
    
}

int main()
{
    bool running = 1;
    /*auto serialListener = std::thread([&,running]{
        while(running)
            if(serialDataAvail(fd) > 0)
                std::cout << static_cast<char>(serialGetchar(fd));
    });*/
    /******************************/
    /**          Mixing           */
    /******************************/
    mixer.mix(true);
    //while(1);
    countdown<std::chrono::seconds>(Cooking_Times::mix_time, "Mixing: ", "Mixed");

    /******************************/
    /**        Dispencing         */
    /******************************/
    mixer.dispense(1);
    //while(1);
    countdown<std::chrono::seconds>(Cooking_Times::mix_dispence_time, "Dispencing: ", "Dispenced");

    mixer.mix(false);
    mixer.dispense(0);

    /******************************/
    /**          Cooking          */
    /******************************/
    countdown<std::chrono::seconds>(Cooking_Times::side_1_cook_time, "Cooking Side 1: ", "Side 1 Cooked");

    flip();
    countdown<std::chrono::seconds>(Cooking_Times::side_2_cook_time, "Cooking Side 2: ", "Side 2 Cooked");

    /******************************/
    /**          Serving          */
    /******************************/
    serve();
    std::cout << "done\n";
    running = 0;
    //serialListener.join();
}
