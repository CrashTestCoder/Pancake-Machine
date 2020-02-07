#include "Flipper.hpp"
#include <iostream>
#include <thread>

namespace util { 
    template <typename T> std::string to_string(const T& t) 
    { 
        std::string str{std::to_string (t)}; 
        int offset{1}; 
        if (str.find_last_not_of('0') == str.find('.')) 
        {
            offset = 0; 
        }
        str.erase(str.find_last_not_of('0') + offset, std::string::npos); 
        return str;
    }
    
 } /* util */


Flipper::Flipper():
    Serial_Device(Serial::dir, Serial::baud)
{
    update();
}

void Flipper::setJoint(Joint_Name joint_num, double position)
{
    joint_[joint_num] = position;
}

Flipper::Joint::operator std::string() const
{
    if(updated)
        return id + util::to_string(position);
    return "";
}

void Flipper::update()
{
    std::string gcode = "G0";
    for(auto& j : joint_)
    {
        if(j.updated) gcode += ' ';
        gcode += static_cast<std::string>(j);
        j.updated = false;
    }
    send_msg(gcode += "\r\n");
    //std::cout << gcode;
    //send_msg("G0 F9000 X100\n\r");
    if(auto err = readLine(); err[0] !='o' || Serial::debug == true) 
        std::cerr << "gcode error:" << err << '\n' << gcode;
    //t.join();
    //std::cout << '\n';
}


void Flipper::goToStartPosition()
{
    setJoint(X,0);
    setJoint(Y,0);
    setJoint(Z,0);
    setJoint(A,0);
    update();
}
