#include "Mixer.hpp"
#include <wiringPi.h>

Mixer::Mixer()
{
    wiringPiSetupPhys();
    
    pinMode(Mixer_Info::mix_pin, OUTPUT);
    pinMode(Mixer_Info::dispence_pin, OUTPUT);
    
    digitalWrite(Mixer_Info::mix_pin, LOW);
    analogWrite(Mixer_Info::dispence_pin, 0);
}

void Mixer::mix(bool val)
{
    digitalWrite(Mixer_Info::mix_pin, val);
}

void Mixer::dispense(double val)
{
    constexpr auto scaler = Mixer_Info::dispence_max_val - Mixer_Info::dispence_min_val;
    analogWrite(Mixer_Info::dispence_pin, Mixer_Info::dispence_min_val + scaler * val);
}
