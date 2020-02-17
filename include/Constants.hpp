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

namespace Mixer_Info
{
    constexpr uint8_t mix_pin = 28;
    constexpr uint8_t dispense_pin = 1;
    
    constexpr int dispense_min_val = 5000;
    constexpr int dispense_max_val = 8000;
} /* Mixer_Info */

namespace Cooking_Times
{
    using namespace std;
    constexpr auto mix_time = 7s;//20s;  
    constexpr auto mix_dispence_time = 5s;
    constexpr auto side_1_cook_time = 5s;
    constexpr auto side_2_cook_time = 13s;
} /* Cooking_Times */

#endif /* __CONSTANTS_H_P_P__ */
