#pragma once
#include <iostream>

class Vector2
{

private:

public:
	int x;
	int y;

	Vector2();
	Vector2(int x, int y);
	void print();

	friend Vector2 operator+(const Vector2& v1, const Vector2& v2);
	friend int operator*(const Vector2& v1, const Vector2& v2);




};