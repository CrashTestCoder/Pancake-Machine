#include "Mixer.hpp"
#include <wiringPi.h>

#include <iostream>
Mixer::Mixer()
{
    pinMode(Mixer_Info::mix_pin, OUTPUT);
    
    mix(0);
    dispense(0);
}

void Mixer::mix(bool val)
{
    digitalWrite(Mixer_Info::mix_pin, val);
}

void Mixer::dispense(double val)
{
    constexpr double scaler = Mixer_Info::dispense_max_val - Mixer_Info::dispense_min_val;
    dispenser.set_ms(Mixer_Info::dispense_min_val + scaler * (1 - val));
}
