#include <iostream>
#include <fstream>
#include <future>
#include <wiringPi.h>

#include "global.hpp"

void flip()
{
    flipper.goToStartPosition();

    /**********************************/
    /**         Flip Pancake          */
    /**********************************/
    flipper.setJoint(X,200.2);      // slide under pancake
    flipper.update();

    flipper.setJoint(Y,100);        // lift
    flipper.update();               // maybe can remove this
    flipper.setJoint(A,pi);

    flipper.goToStartPosition();
}

int main()
{
    flip();
}
