#ifndef __SERIAL_DEVICE_H_P_P__
#define __SERIAL_DEVICE_H_P_P__

#include <inttypes.h>
#include <errno.h>
#include <string_view>
#include <string>
#include <mutex>

class Serial_Device
{
    static inline std::recursive_mutex writing_mutex;
protected:
    int const fd;

    explicit Serial_Device(char const * dir, std::uint32_t baud);

    void send_msg_8(uint8_t msg);
    uint8_t read_msg_8() const;

    void send_msg(std::string_view msg);
    std::string readLine();
};

#endif /* __SERIAL_DEVICE_H_P_P__ */
