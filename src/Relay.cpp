#include "Relay.hpp"
#include <wiringSerial.h>

struct Relay_msg
{
	constexpr operator unsigned char() { return *this; }
	
	unsigned port : 4;
	bool state : 1;
};

Relay::Relay(unsigned address):
	adr { address }
{
	
}

void Relay::set(bool val)
{
	Relay_msg const msg { adr, val };
	
	serialPutchar(fd, *(unsigned char*)&msg);
}
