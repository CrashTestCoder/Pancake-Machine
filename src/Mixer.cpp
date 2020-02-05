#include "Mixer.hpp"
#include <wiringPi.h>

Mixer::Mixer()
{
    wiringPiSetupGpio();
    
    pinMode(Mixer_Info::mix_pin, OUTPUT);
    pinMode(Mixer_Info::dispense_pin, OUTPUT);
    
    digitalWrite(Mixer_Info::mix_pin, LOW);
    analogWrite(Mixer_Info::dispense_pin, 0);
}

void Mixer::mix(bool val)
{
    digitalWrite(Mixer_Info::mix_pin, val);
}

void Mixer::dispense(double val)
{
    constexpr auto scaler = Mixer_Info::dispense_max_val - Mixer_Info::dispense_min_val;
    analogWrite(Mixer_Info::dispense_pin, Mixer_Info::dispense_min_val + scaler * val);
}
