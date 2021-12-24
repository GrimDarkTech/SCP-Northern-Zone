#pragma once

#include <Math.h>

class Vector2
{
	public:	double x;
	public:	double y;
	public:
		Vector2()
		{
			x = 0;
			y = 0;
		}
		Vector2(double x) : Vector2()
		{
			this->x = x;
		}
		Vector2(double x, double y) : Vector2(x)
		{
			this->y = y;
		}
	public: double magnitude()
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	public: Vector2 normalize()
	{
		double* magnitude = new double;
		*magnitude = this->magnitude();
		Vector2 newVector(this->x/ *magnitude, this->y/ *magnitude);
		delete magnitude;
		return newVector;
	}

	public: static double dot(const Vector2& vectorA, const Vector2& vectorB)
	{
		return (vectorA.x * vectorB.x + vectorA.y * vectorB.y);
	}

};