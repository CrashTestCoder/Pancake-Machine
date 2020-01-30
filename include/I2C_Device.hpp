#ifndef __I2C_DEVICE_H_P_P__
#define __I2C_DEVICE_H_P_P__

#include <inttypes.h>
#include <wiringPiI2C.h>
#include <errno.h>
#include <string>

class I2C_Device
{
protected:
    uint8_t const id;

    explicit I2C_Device(uint8_t device_id);

    int send_msg_8(uint8_t msg) const;
    uint8_t read_msg_8() const;

    int send_msg(std::string msg);
};

#endif /* __I2C_DEVICE_H_P_P__ */