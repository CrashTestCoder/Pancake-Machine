#include "Flipper.hpp"

Flipper::Flipper():
    I2C_Device(I2C_ADDR::flipper)
{}

int Flipper::setJoint(uint8_t joint_num, double position)
{

}

Flipper::msg::operator std::string() const
{
    std::string out;
    char prefix = 'a';
    for(auto j : joint)
    {
        out += prefix++;
        out += std::to_string(j);
    }
    return out;
}