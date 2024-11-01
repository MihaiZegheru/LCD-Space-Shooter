#pragma once
#include "vector2.h"

class Transform
{

#define defaultPositionX  42
#define defaultPositionY  24


public:
	Vector2 position;
	Transform()
	{
		position.x = defaultPositionX;
		position.y = defaultPositionY;
	}

	void SetPosition(int _positionX, int _positionY)
	{
		position.x = _positionX;
		position.y = _positionY;
	}

private:


};

