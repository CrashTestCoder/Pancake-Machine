#ifndef __MIXER_H_P_P__
#define __MIXER_H_P_P__

#include "Constants.hpp"
#include "Servo.hpp"

class Mixer
{
    Servo dispenser { Mixer_Info::dispense_pin };
public:
    Mixer();

    void mix(bool);
    void dispense(double); // value range 0 - 1
};

#endif /* __MIXER_H_P_P__ */
