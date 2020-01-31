#ifndef __FLIPPER_H_P_P__
#define __FLIPPER_H_P_P__

#include "Serial_Device.hpp"
#include "Constants.hpp"
#include <string>
#include <string_view>

class Flipper : public Serial_Device
{
    typedef enum { X, Y, Z, A } Joint_Name;
    struct Joint
    {
        std::string id;
        double position;
        
        operator std::string() const;

        auto operator = (Joint const&) = delete;
        double operator = (double d) {
            return position = d;
        }
    };
    Joint joint_[] = { [X] = {"X", 0}, 
                       [Y] = {"Y", 0},
                       [Z] = {"Z", 0}, 
                       [A] = {"A", 0} };
public:
    Flipper();

    /**
     * setJoint updates the setpoint for the joint, but does not transmit the change
     * you must use the update() function to send the command to the flipper system
     */
    void setJoint(Joint_Name joint, double position);

    /**
     * Transmits joint commants to flipper subsystem
     */
    int update() const;
};

#endif /* __FLIPPER_H_P_P__ */