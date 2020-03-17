#ifndef __MIXER_H_P_P__
#define __MIXER_H_P_P__

#include "Constants.hpp"
#include "Servo.hpp"
#include "Relay.hpp"

class Mixer
{
    Servo dispenser;
    Relay mixer { Mixer_Info::mix_pin };
public:
    Mixer(int disp_pin, int mix_pin);

    void mix(bool);
    void dispense(bool); 
};

#endif /* __MIXER_H_P_P__ */
