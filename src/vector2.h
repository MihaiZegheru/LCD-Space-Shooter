#pragma once
class Vector2
{
public:
	int x;
	int y;

	Vector2(short int _x = 0, short int _y = 0)
	{
		x = _x;
		y = _y;
	}

	friend Vector2 operator +(Vector2 a, const Vector2& b)
	{
		a.x += b.x;
		a.y += b.y;
		return a;
	}

	friend Vector2 operator -(Vector2 a, const Vector2& b)
	{
		a.x -= b.x;
		a.y -= b.y;
		return a;
	}

	friend Vector2 operator *(Vector2 a, const Vector2& b)
	{
		a.x *= b.x;
		a.y *= b.y;
		return a;
	}

	friend Vector2 operator *(Vector2 a, const int& b)
	{
		a.x *= b;
		a.y *= b;
		return a;
	}

	Vector2& operator +=(const Vector2& v)
	{
		x += v.x;
		y += v.y;
		return* this;
	}

	Vector2& operator -=(const Vector2& v)
	{
		x -= v.x;
		y -= v.y;
		return* this;
	}

	/*friend Vector2 operator *(Vector2 a, const Vector2& b)
	{
		a.x *= b;
		a.y *= b;
		return a;
	}*/
};



