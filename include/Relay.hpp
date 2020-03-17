#ifndef _RELAY_H_P_P_
#define _RELAY_H_P_P_

#include "Serial_Device.hpp"

class Relay
{
	unsigned const adr;
public:
	Relay(unsigned adress);
	void set(bool);
	
	static int fd;
};

#endif /* _RELAY_H_P_P_ */
