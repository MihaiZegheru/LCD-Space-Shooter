#pragma once
#include "transform.h"
#include "sprite.h"
#include "vector2.h"
#include "map.h"

class Meteorite
{
public:
	Vector2 speed;

	Meteorite()
	{
		pinMode(100, INPUT);
		randomSeed(analogRead(100));

		sprite = new Sprite(meteoriteImage);
		transform = new Transform;
		Map::UpdateMap(*sprite, *transform);

		speed.x = random(1, 5);
		speed.y = random(0, 2);

		Serial.print(speed.x);
		Serial.print(' ');
		Serial.print(speed.y);
		Serial.print(' ');

	}
	~Meteorite()
	{
		delete transform;
		delete sprite;
	}

	void Update()
	{
		transform->position -= speed;
		Map::UpdateMap(*sprite, *transform);

		// TODO: Fix
		if (transform->position.x > 88 && transform->position.x < 0)
			delete this;

		if (transform->position.y > 52 && transform->position.y < -4)
			delete this;
	}

	Sprite* GetSprite()
	{
		return sprite;
	}
	Transform* GetTransform()
	{
		return transform;
	}

private:
	bool meteoriteImage[8][8] =
	{
		{0, 0, 1, 1, 1, 1, 0, 0},
		{0, 1, 1, 1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{0, 1, 1, 1, 1, 1, 1, 0},
		{0, 0, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
	};

	Transform* transform = nullptr;
	Sprite* sprite = nullptr;
};

