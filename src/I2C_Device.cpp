#include "I2C_Device.hpp"

I2C_Device::I2C_Device(uint8_t device_id):
    id { wiringPiI2CSetup(device_id) }
{}

int I2C_Device::send_msg_8(uint8_t data) const
{
    return wiringPiI2CWrite(id, data);
}

uint8_t I2C_Device::read_msg_8() const
{
    return wiringPiI2CRead(id);
}
