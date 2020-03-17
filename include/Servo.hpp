#ifndef _SERVO_H_P_P_
#define _SERVO_H_P_P_

#include "pca9685.h"
#include "Constants.hpp"

class Servo
{
	int const adr;
	
	constexpr int calculateTicks(double ms) const;
public:
	Servo(int address);
	void set_ms(double ms);
	
	static int fd;
};


#endif /* _SERVO_H_P_P_ */
