#ifndef __FLIPPER_H_P_P__
#define __FLIPPER_H_P_P__

#include "I2C_Device.hpp"
#include "Constants.hpp"
#include <string>

class Flipper : public I2C_Device
{
    struct msg
    {
        double joint[4];

        operator std::string() const;
    };
public:
    Flipper();

    int setJoint(uint8_t joint_num, double position);
};

#endif /* __FLIPPER_H_P_P__ */