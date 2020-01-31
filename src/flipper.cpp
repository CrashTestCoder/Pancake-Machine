#include "Flipper.hpp"

Flipper::Flipper():
    Serial_Device(Serial::dir, Serial::baud)
{}

void Flipper::setJoint(Flipper::Joint_Name joint_num, double position)
{
    joint_[joint_num] = position;
}

Flipper::Joint::operator std::string() const
{
    return id + std::to_string(position);
}

void Flipper::update()
{
    std::string gcode = "G0";
    for(auto j : joint_)
    {
        gcode += static_cast<std::string>(" ") + static_cast<std::string>(j);
    }
    send_msg(gcode);
}
