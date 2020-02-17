#include "Serial_Device.hpp"
#include "Constants.hpp"
#include <wiringSerial.h>
#include <iostream>


#include "global.hpp"

Serial_Device::Serial_Device(char const * device_id, std::uint32_t baud):
    fd { serialOpen(device_id, baud) }
{
    setFD(fd);
    }

void Serial_Device::send_msg_8(uint8_t data)
{
    if constexpr (Serial::debug)
        std::cout << (char)data << std::flush;
    else
        serialPutchar(fd, data);
}

uint8_t Serial_Device::read_msg_8() const
{
    if constexpr (Serial::debug)
        return 0;//serialGetchar(fd);
    else 
    {
        char c;
        std::cin >> c;
        return c;
    }
}

void Serial_Device::send_msg(std::string_view str)
{
    //while(1)
    for(auto c : str)
        send_msg_8(c);
}

std::string Serial_Device::readLine()
{
    int exitcode;
    char read_val = 0;
    std::string msg;
    while(1)
    {
        if(exitcode = serialDataAvail(fd); exitcode > 0) 
        {
            msg += read_val = serialGetchar(fd);
        }
        if(read_val == '\n') return msg;
    }
// else error
}
