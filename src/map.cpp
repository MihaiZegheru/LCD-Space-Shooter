#include "map.h"

#define DIGITALMAP_X     84
#define DIGITALMAP_Y     6
#define sizeX            84
#define sizeY            52

bool  Map::gameMap[sizeY][sizeX] = {};
byte  Map::digitalMap[DIGITALMAP_Y * DIGITALMAP_X] = {};

void Map::UpdateMap(Sprite& sprite, Transform& transform)
{
	Vector2 position = transform.position;
	Vector2 spriteSize = sprite.size;

	Vector2 startPosition(position.x, position.y - spriteSize.y / 2);

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (sprite.sprite[y][x])
				gameMap[startPosition.y + y][startPosition.x + x] = sprite.sprite[y][x];
		}
	}

	UpdateDigitalMap();
}

void Map::UpdateDigitalMap()
{
	for (int i = 0; i < DIGITALMAP_X * DIGITALMAP_Y; i++)
	{
		bool binary[8];
		for (int j = 8 * (i / DIGITALMAP_X + 1) - 1; j >= 8 * (i / DIGITALMAP_X); j--)
		{
			binary[j % 8] = Map::gameMap[j % sizeY][i % DIGITALMAP_X];
		}
		digitalMap[i] = byte(ToInt(binary));
	}
}

int Map::ToInt(bool binary[])
{
	int num = 0;
	for (int i = 7; i >= 0; i--)
	{
		if (binary[i] == 1)
		{
			num *= 2;
			num++;
		}
		else num *= 2;
	}

	return num;
}

void Map::ClearMap()
{
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			Map::gameMap[y][x] = 0;
		}
	}
}
