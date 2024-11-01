#pragma once
#include "vector2.h"


#define sizeX 8
#define sizeY 8

class Sprite
{
public:
	Vector2 size;

	bool sprite[sizeX][sizeY];

	Sprite(bool image[sizeX][sizeY] = nullptr)
	{
		size.x = sizeX;
		size.y = sizeY;

		for (unsigned short int i = 0; i < size.y; i++)
		{
			for (unsigned short int j = 0; j < size.x; j++)
			{
				sprite[i][j] = image[i][j];
			}
		}
	}


private:


};

