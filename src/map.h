#pragma once
#include "sprite.h"
#include "transform.h"
#include "vector2.h"
#include <Arduino.h>


#define DIGITALMAP_X     84
#define DIGITALMAP_Y     6
#define sizeX            84
#define sizeY            52
#define blockSize        8


class Map
{
public:
	static Vector2 mapSize;

	static bool gameMap[sizeY][sizeX];
	static byte digitalMap[DIGITALMAP_Y * DIGITALMAP_X];


	static void UpdateMap(Sprite& sprite, Transform& transform);
	static void ClearMap();
	static int ToInt(bool binary[]);

private:
	static void UpdateDigitalMap();


};

