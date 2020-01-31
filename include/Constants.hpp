#ifndef __CONSTANTS_H_P_P__
#define __CONSTANTS_H_P_P__

#include <inttypes.h>
#include <string_view>

namespace Serial
{
    constexpr std::string_view dir = "/dev/ttyAMA0";
    constexpr uint32_t baud = 9600;
} /* Serial */

#endif /* __CONSTANTS_H_P_P__ */