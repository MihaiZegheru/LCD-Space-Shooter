// display.h

#ifndef _DISPLAY_h
#define _DISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "map.h"
#include "vector2.h"

#define PIN_SCE   3
#define PIN_RESET 2
#define PIN_DC    4
#define PIN_SDIN  5
#define PIN_SCLK  6
#define PIN_LIGHT 7

#define LCD_C     LOW
#define LCD_D     HIGH

#define LCD_X     84
#define LCD_Y     6
#define blockSize 8


class DisplayClass
{
 protected:


 public:
	DisplayClass()
	{
		Initialise();
		Clear();
	}

	void UpdateDisplay(void)
	{
		//Daca am clear o sa apara si o sa dispara, daca nu am, o sa se vada blured
		for (int index = 0; index < LCD_X * LCD_Y; index++)
		{
			Write(LCD_D, Map::digitalMap[index]);
		}
	}

	void Light(float percentage = 100)
	{
		digitalWrite(PIN_LIGHT, LOW);
	}

	void Clear(void)
	{
		for (int index = 0; index < LCD_X * LCD_Y; index++)
		{
			Write(LCD_D, 0x0);
		}
	}


private:


	void Initialise(void)
	{
		pinMode(PIN_SCE, OUTPUT);
		pinMode(PIN_RESET, OUTPUT);
		pinMode(PIN_DC, OUTPUT);
		pinMode(PIN_SDIN, OUTPUT);
		pinMode(PIN_SCLK, OUTPUT);
		pinMode(PIN_LIGHT, OUTPUT);

		digitalWrite(PIN_RESET, LOW);
		digitalWrite(PIN_RESET, HIGH);
		Write(LCD_C, 0x21);  // LCD Extended Commands.
		Write(LCD_C, 0xB1);  // Set LCD Vop (Contrast).
		Write(LCD_C, 0x04);  // Set Temp coefficent. //0x04
		Write(LCD_C, 0x14);  // LCD bias mode 1:48. //0x13
		Write(LCD_C, 0x20);  // LCD Basic Commands
		Write(LCD_C, 0x0C);  // LCD in normal mode.
	}



	void Write(byte dc, byte data)
	{
		digitalWrite(PIN_DC, dc);
		digitalWrite(PIN_SCE, LOW);
		shiftOut(PIN_SDIN, PIN_SCLK, MSBFIRST, data);
		digitalWrite(PIN_SCE, HIGH);
	}

};

extern DisplayClass Display;

#endif

