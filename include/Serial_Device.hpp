#ifndef __SERIAL_DEVICE_H_P_P__
#define __SERIAL_DEVICE_H_P_P__

#include <inttypes.h>
#include <wiringSerial.h>
#include <errno.h>
#include <string_view>

class Serial_Device
{
protected:
    uint8_t const fd;

    explicit Serial_Device(std::string_view dir, std::uint32_t baud);

    int send_msg_8(uint8_t msg) const;
    uint8_t read_msg_8() const;

    int send_msg(std::string_view msg) const;
};

#endif /* __SERIAL_DEVICE_H_P_P__ */