// joystick.h

#ifndef _JOYSTICK_h
#define _JOYSTICK_h

#include "vector2.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define PIN_ANALOG_X   A0
#define PIN_ANALOG_Y   A1
#define PIN_SW          9


class JoystickClass
{
 public:
	JoystickClass()
	{
		Initialise();
	}

	Vector2 Value()
	{
		Vector2 joystickValue;
		int xPosition = analogRead(PIN_ANALOG_X);
		int yPosition = analogRead(PIN_ANALOG_Y);
		int sw = digitalRead(PIN_SW);

		joystickValue.x = ComputeInput(map(xPosition, 0, 1023, -512, 512));
		joystickValue.y = ComputeInput(map(yPosition, 0, 1023, -512, 512));

		return joystickValue;
	}

private:
	void Initialise(void)
	{
		pinMode(PIN_ANALOG_X, INPUT);
		pinMode(PIN_ANALOG_Y, INPUT);
		pinMode(PIN_SW, INPUT_PULLUP);
	}

	int ComputeInput(int position)
	{
		if (position <= 100 && position >= -100)
		{
			return 0;
		}
		else if (position > 100)
		{
			return -1;
		}
		else return 1;
	}
};

extern JoystickClass Joystick;

#endif

