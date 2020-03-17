#include "Servo.hpp"
#include <wiringPi.h>
#include "Constants.hpp"


Servo::Servo(int address) :
	adr { address }
{	
	pca9685PWMReset(Servo::fd); 
}


constexpr int Servo::calculateTicks(double ms) const
{
	float cycleMs = 1000.0f / Servo_Info::freq;
	return (int)(Servo_Info::MAX_PWM * ms / cycleMs + 0.5f);
}

void Servo::set_ms(double ms)
{
	pwmWrite(Servo_Info::PIN_BASE + adr, calculateTicks(ms));
}
