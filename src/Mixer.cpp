#include "Mixer.hpp"

Mixer::Mixer():
    I2C_Device(I2C_ADDR::mixer)
{}

int Mixer::mix(bool m)
{
    return send_msg_8(m?'m':'s');
}

int Mixer::dispence(uint8_t amt)
{
    return send_msg_8(amt);
}