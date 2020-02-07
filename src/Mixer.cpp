#include "Mixer.hpp"
#include <wiringPi.h>

Mixer::Mixer()
{
    wiringPiSetup();
    
    pinMode(Mixer_Info::mix_pin, OUTPUT);
    pinMode(Mixer_Info::dispense_pin, PWM_OUTPUT);
    
    pwmSetMode(PWM_MODE_MS);
    
    pwmSetClock(5); // 1.919MHz
    pwmSetRange(100000 / 1.3);
    
    
    mix(0);
    dispense(0);
}

void Mixer::mix(bool val)
{
    digitalWrite(Mixer_Info::mix_pin, val);
}

void Mixer::dispense(double val)
{
    constexpr auto scaler = Mixer_Info::dispense_max_val - Mixer_Info::dispense_min_val;
    pwmWrite(Mixer_Info::dispense_pin, Mixer_Info::dispense_min_val + scaler * (1 - val));
}
