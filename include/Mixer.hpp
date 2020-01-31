#ifndef __MIXER_H_P_P__
#define __MIXER_H_P_P__

#include "Constants.hpp"

class Mixer
{
public:
    // Mixer();

    int mix(bool);
    int dispence(uint8_t); // value range 0 - 100(%)
};

#endif /* __MIXER_H_P_P__ */