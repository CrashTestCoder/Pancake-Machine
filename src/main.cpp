#include <iostream>
#include <fstream>
#include <future>
#include <wiringPi.h>
#include <thread>
#include <chrono>
#include <wiringSerial.h>

#include "global.hpp"

using namespace std;

void flip()
{
    //flipper.goToStartPosition();

    /**********************************/
    /**         Flip Pancake          */
    /**********************************/
    flipper.setJoint(X,200.2);      // slide under pancake
    flipper.update();

    flipper.setJoint(Z,80);        // lift
    flipper.update();               // maybe can remove this
    //flipper.setJoint(A,pi);
    //flipper.update();

    /**********************************/
    /**  Go To Serve Start Position   */
    /**********************************/
    flipper.setJoint(Y, 0);
    flipper.setJoint(Z, 0);
    flipper.setJoint(X, 0);
    flipper.update();
}

void serve()
{
    flipper.setJoint(X,200.2);      // slide under pancake
    flipper.update();

    flipper.setJoint(Z,80);        // lift
    //flipper.update();               // maybe can remove this
    flipper.setJoint(Y, -200);
    flipper.update();

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
