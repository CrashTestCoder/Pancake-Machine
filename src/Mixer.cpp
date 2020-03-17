#include "Mixer.hpp"
#include <wiringPi.h>

#include <iostream>
Mixer::Mixer(int disp_pin, int mix_pin):
    dispenser { disp_pin },
    mixer { mix_pin }
{
    //pinMode(Mixer_Info::mix_pin, OUTPUT);
    
    mix(0);
    dispense(0);
}

void Mixer::mix(bool val)
{
    mixer.set(val);
}

void Mixer::dispense(bool val)
{
    constexpr double scaler = Mixer_Info::dispense_max_val - Mixer_Info::dispense_min_val;
    dispenser.set_ms(val?Mixer_Info::dispense_max_val:Mixer_Info::dispense_min_val);
}
