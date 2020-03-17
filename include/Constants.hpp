#ifndef __CONSTANTS_H_P_P__
#define __CONSTANTS_H_P_P__

#include <inttypes.h>
#include <string_view>
#include <chrono>
#include <cmath>

constexpr double pi = acos(-1);
static_assert(3.14-pi < .01);

namespace Serial
{
    constexpr char const * dir = "/dev/ttyACM1";
    constexpr uint32_t baud = 115200;
    constexpr bool debug = false;
} /* Serial */

namespace Servo_Info
{
    constexpr int PIN_BASE = 300;
    constexpr int MAX_PWM = 4096;
    constexpr int freq = 50;
}

namespace Water_Pump_Info
{
    using namespace std;
    
    constexpr int pump_pin = 8;
    constexpr auto pump_time = 5s;
}

namespace Hopper_Info
{
    using namespace std;
    
    constexpr int vibrator_pin = 9;
    constexpr int dispenser_pin = 2;
    constexpr auto dispense_time = 6s;
}

namespace Mixer_Info
{
    constexpr int mix_pin = 10; 
    constexpr int dispense_pin = 0;
    
    constexpr double dispense_min_val = 2.082;//0.79;
    constexpr double dispense_max_val = 1.4;
} /* Mixer_Info */

namespace Flipper_Info
{
    using namespace std;
    
    constexpr int flip_pin = 1;
    constexpr double flip_min = 0.75;
    constexpr double flip_max = 2.225;
    
    
    constexpr auto flip_pickup_time = 7.0s;
    constexpr auto flip_time = 2.0s;
    
    constexpr auto serve_pickup_time = 12.0s;
    constexpr auto serve_time = 2.0s;

}

namespace Cooking_Times
{
    using namespace std;
    constexpr auto mix_time = 2.0s;//20.0s;
    constexpr auto mix_dispence_time = 1.0s;//5.0s;
    constexpr auto side_1_cook_time = 5.0s;//2.25min;
    constexpr auto side_2_cook_time = 10.0s;//2.0min;
} /* Cooking_Times */

#endif /* __CONSTANTS_H_P_P__ */
