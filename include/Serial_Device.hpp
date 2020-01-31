#ifndef __SERIAL_DEVICE_H_P_P__
#define __SERIAL_DEVICE_H_P_P__

#include <inttypes.h>
#include <wiringSerial.h>
#include <errno.h>
#include <string_view>
#include "Constants.hpp"

class Serial_Device
{
protected:
    int const fd;

    explicit Serial_Device(char const * dir, std::uint32_t baud);

    void send_msg_8(uint8_t msg);
    uint8_t read_msg_8() const;

    void send_msg(std::string_view msg);
};

#endif /* __SERIAL_DEVICE_H_P_P__ */
