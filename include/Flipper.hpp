#ifndef __FLIPPER_H_P_P__
#define __FLIPPER_H_P_P__

#include "Serial_Device.hpp"
#include "Constants.hpp"
#include <string>
#include <string_view>

typedef enum { F, X, Y, Z } Joint_Name;
class Flipper : public Serial_Device
{
public:
    Flipper();
    
    class Joint
    {
    public:
        std::string id;
        double position;
        bool updated = true;
        
        operator double() const;
        operator std::string() const;

        auto operator = (Joint const&) = delete;
        double operator = (double d) {
            updated = true;
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
     * Transmits joint commands to flipper subsystem
     */
    void update();
    
    void flip(bool b);

private:
    Joint joint_[4] = { [F] = {"F", 15000},
                        [X] = {"X", 0}, 
                        [Y] = {"Y", 0},
                        [Z] = {"Z", 0}
                        };
};

#endif /* __FLIPPER_H_P_P__ */
