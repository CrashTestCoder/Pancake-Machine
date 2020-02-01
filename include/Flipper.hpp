#ifndef __FLIPPER_H_P_P__
#define __FLIPPER_H_P_P__

#include "Serial_Device.hpp"
#include "Constants.hpp"
#include <string>
#include <string_view>

typedef enum { X, Y, Z, A } Joint_Name;
class Flipper : public Serial_Device
{
public:
    Flipper();
    
    class Joint
    {
    public:
        std::string id;
        double position;
        
        operator std::string() const;

        auto operator = (Joint const&) = delete;
        double operator = (double d) {
            return position = d;
        }
    };

    /**
     * setJoint updates the setpoint for the joint, but does not transmit the change
     * you must use the update() function to send the command to the flipper system
     */
    void setJoint(Joint_Name joint, double position);

    void goToStartPosition();
    
    /**
     * Transmits joint commants to flipper subsystem
     */
    void update();

private:
    Joint joint_[4] = { [X] = {"X", 0}, 
                        [Y] = {"Y", 0},
                        [Z] = {"Z", 0}, 
                        [A] = {"A", 0} };
};

#endif /* __FLIPPER_H_P_P__ */
