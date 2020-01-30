#ifndef __MIXER_H_P_P__
#define __MIXER_H_P_P__

#include "I2C_Device.hpp"
#include "Constants.hpp"

class Mixer : public I2C_Device
{
public:
    Mixer();

    int mix(bool);
    int dispence(uint8_t); // value range 0 - 100(%)
};

#endif /* __MIXER_H_P_P__ */