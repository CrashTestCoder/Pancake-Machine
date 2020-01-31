#include "Serial_Device.hpp"

Serial_Device::Serial_Device(std::string_view device_id, std::uint32_t baud):
    fd { serialOpen(device_id, baud) }
{}

int Serial_Device::send_msg_8(uint8_t data) const
{
    return serialPutchar(id, data);
}

uint8_t Serial_Device::read_msg_8() const
{
    return serialGetchar(id);
}
