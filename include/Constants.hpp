#ifndef __CONSTANTS_H_P_P__
#define __CONSTANTS_H_P_P__

#include <inttypes.h>
#include <string_view>
#include <cmath>

constexpr double pi = acos(-1);
static_assert(3.14-pi < .01);

namespace Serial
{
    constexpr char const * dir = "/dev/ttyAMA0";
    constexpr uint32_t baud = 9600;
    constexpr bool debug = true;
} /* Serial */

namespace Mixer_Info
{
    constexpr uint8_t mix_pin = 1;
    constexpr uint8_t dispence_pin = 2;
    
    constexpr int dispence_min_val = 200;
    constexpr int dispence_max_val = 900;
}

#endif /* __CONSTANTS_H_P_P__ */
