#include"Vector.h"


Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Vector2::print()
{
	std::cout << this->x << "," << this->y << std::endl;
}

Vector2 operator+(const Vector2& v1, const Vector2& v2)
{
	return Vector2{ v1.x + v2.x, v1.y + v2.y };
}

int operator*(const Vector2& v1, const Vector2& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y);
}

