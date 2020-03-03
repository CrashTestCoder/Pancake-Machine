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
    constexpr char const * dir = "/dev/ttyAMA0";
    constexpr uint32_t baud = 115200;
    constexpr bool debug = false;
} /* Serial */

namespace Servo_Info
{
    constexpr int PIN_BASE = 300;
    constexpr int MAX_PWM = 4096;
    constexpr int freq = 50;
}

namespace Mixer_Info
{
    constexpr uint8_t mix_pin = 28; 
    constexpr uint8_t dispense_pin = 0;
    
    constexpr double dispense_min_val = 1;//0.79;
    constexpr double dispense_max_val = 2;
} /* Mixer_Info */

namespace Flipper_Info
{
    using namespace std;
    
    constexpr int flip_pin = 2;
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
    constexpr auto mix_time = 20.0s;
    constexpr auto mix_dispence_time = 5.0s;
    constexpr auto side_1_cook_time = 2.25min;
    constexpr auto side_2_cook_time = 2.0min;
} /* Cooking_Times */

#endif /* __CONSTANTS_H_P_P__ */
