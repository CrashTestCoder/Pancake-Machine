#ifndef __MIXER_H_P_P__
#define __MIXER_H_P_P__

#include "Constants.hpp"

class Mixer
{
public:
    Mixer();

    void mix(bool);
    void dispence(double); // value range 0 - 1
};

#endif /* __MIXER_H_P_P__ */
