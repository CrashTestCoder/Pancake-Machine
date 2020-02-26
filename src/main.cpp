#include <iostream>
#include <fstream>
#include <future>
#include <wiringPi.h>
#include <thread>
#include <chrono>
#include <wiringSerial.h>

#include "Flipper.hpp"
#include "Mixer.hpp"

Mixer mixer;
Flipper flipper;

using namespace std;

void flip()
{
    //flipper.goToStartPosition();

    /**********************************/
    /**         Flip Pancake          */
    /**********************************/
    flipper.setJoint(X,200);      // slide under pancake
    flipper.update();

    flipper.setJoint(Z,180);        // lift
    flipper.update();              // maybe can remove this
    
    std::this_thread::sleep_for(Flipper_Info::flip_pickup_time);
    flipper.flip(1);
    std::this_thread::sleep_for(Flipper_Info::flip_time);
    flipper.flip(0);

    flipper.goToStartPosition();
}

void serve()
{
    flipper.setJoint(X,200);      // slide under pancake
    flipper.update();

    flipper.setJoint(Z,180);        // lift
    flipper.update();               // maybe can remove this
    flipper.setJoint(Y, 300);
    flipper.update();

    std::this_thread::sleep_for(Flipper_Info::serve_pickup_time);
    flipper.flip(1);
    std::this_thread::sleep_for(Flipper_Info::serve_time);
    flipper.flip(0);

    flipper.goToStartPosition();
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
    std::cout << "mixing\n";
    mixer.mix(true);
    //while(1);
    std::this_thread::sleep_for(Cooking_Times::mix_time);

    /******************************/
    /**        Dispencing         */
    /******************************/
    std::cout << "dispencing\n";

    mixer.dispense(1);
    //while(1);
    std::this_thread::sleep_for(Cooking_Times::mix_dispence_time);

    mixer.mix(false);
    mixer.dispense(0);

    /******************************/
    /**          Cooking          */
    /******************************/
    std::this_thread::sleep_for(Cooking_Times::side_1_cook_time);

    std::cout << "flip\n";
    flip();
    std::this_thread::sleep_for(Cooking_Times::side_2_cook_time);

    /******************************/
    /**          Serving          */
    /******************************/
    std::cout << "serve\n";
    serve();
    std::cout << "done\n";
    running = 0;
    //serialListener.join();
}
