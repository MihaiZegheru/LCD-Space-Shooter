#pragma once
#include "transform.h"
#include "sprite.h"
#include "map.h"
#include "vector2.h"
#include "joystick.h"

class Spaceship
{
public:
    Vector2 speed;
    JoystickClass leftJoystick;

    Spaceship()
    {
        sprite = new Sprite(spaceshipImage);
        transform = new Transform;
        Map::UpdateMap(*sprite, *transform);

        speed = *defaultSpeed;
    }
    ~Spaceship()
    {
        delete transform;
        delete sprite;
    }


    void Update()
    {
        Vector2 joystickMove = leftJoystick.Value();
        Vector2 move(joystickMove.x * speed.x, joystickMove.y * speed.y);

        transform->position.x += move.x;
        transform->position.y += move.y;

        transform->position.x = Clamp(transform->position.x, 0, 30);
        transform->position.y = Clamp(transform->position.y, 0, 48);

        Map::UpdateMap(*sprite, *transform);
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
    bool spaceshipImage[8][8] =
    {
     {1, 1, 1, 0, 0, 0, 0, 0},
     {1, 1, 1, 1, 1, 0, 0, 0},
     {1, 1, 1, 1, 0, 0, 0, 0},
     {1, 1, 1, 1, 1, 1, 1, 1},
     {1, 1, 1, 1, 1, 1, 1, 1},
     {1, 1, 1, 1, 0, 0, 0, 0},
     {1, 1, 1, 1, 1, 0, 0, 0},
     {1, 1, 1, 0, 0, 0, 0, 0}
    };

    Sprite* sprite = nullptr;
    Transform* transform = nullptr;

    const Vector2* defaultSpeed = new Vector2(2, 2);

    int Clamp(int value, int min, int max)
    {
        if (value < min)
            return min;
        else if (value > max)
            return max;

        return value;
    }

};

