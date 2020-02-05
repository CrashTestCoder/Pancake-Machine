#include "Flipper.hpp"
#include <iostream>

Flipper::Flipper():
    Serial_Device(Serial::dir, Serial::baud)
{}

void Flipper::setJoint(Joint_Name joint_num, double position)
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
        gcode += static_cast<std::string>(" ") + static_cast<std::string>(j);
    send_msg(gcode + '\n');
    if(auto err = readLine(); err[0] !='o') 
        std::cerr << "gcode error: " << err << '\n';
}


void Flipper::goToStartPosition()
{
    setJoint(X,0);
    setJoint(Y,0);
    setJoint(Z,0);
    setJoint(A,0);
    update();
}
