#include "Serial_Device.hpp"

Serial_Device::Serial_Device(char const * device_id, std::uint32_t baud):
    fd { serialOpen(device_id, baud) }
{}

void Serial_Device::send_msg_8(uint8_t data)
{
    serialPutchar(fd, data);
}

uint8_t Serial_Device::read_msg_8() const
{
    return serialGetchar(fd);
}

void Serial_Device::send_msg(std::string_view str)
{
    for(auto c : str)
	send_msg_8(c);
}
