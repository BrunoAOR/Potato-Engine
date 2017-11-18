#include "Vector2.h"

#define _USE_MATH_DEFINES
#include <cmath>


Vector2::Vector2() : x(0), y(0)
{
}


Vector2::Vector2(double x, double y) : x(x), y(y)
{
}


double Vector2::getLength() const
{
	return sqrt(getLengthSquared());
}


double Vector2::getLengthSquared() const
{
	return x * x + y * y;
}


Vector2 Vector2::normalized() const
{
	double length = getLength();
	if (length == 0)
	{
		return *this;
	}
	return *this / length;
}


void Vector2::normalize()
{
	double length = getLength();
	if (length == 0)
	{
		return;
	}
	x /= length;
	y /= length;
}


void Vector2::rotateCCWDegrees(double degrees)
{
	// To rotate a vector counter-clockwise (CCW) by an angle
	// the following theorem is applied (for CCW rotation):
	// x2 = x1 * cos(theta) - y1 * sin(theta)
	// y2 = x1 * sin(theta) + y1 * cos(theta)
	rotateCCWRadians(M_PI / 180 * degrees);
}


void Vector2::rotateCCWRadians(double radians)
{
	// To rotate a vector counter-clockwise (CCW) by an angle
	// the following theorem is applied (for CCW rotation):
	// x2 = x1 * cos(theta) - y1 * sin(theta)
	// y2 = x1 * sin(theta) + y1 * cos(theta)
	double sinRot = sin(radians);
	double cosRot = cos(radians);

	double oldX = x;
	double oldY = y;

	x = oldX * cosRot - oldY * sinRot;
	y = oldX * sinRot + oldY * cosRot;
}


Vector2 & Vector2::operator+=(const Vector2 & rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}


Vector2 & Vector2::operator-=(const Vector2 & rhs)
{
	this->x -= x;
	this->y -= y;
	return *this;
}


Vector2 & Vector2::operator*=(double num)
{
	this->x *= num;
	this->y *= num;
	return *this;
}


Vector2 & Vector2::operator/=(double num)
{
	this->x /= num;
	this->y /= num;
	return *this;
}


double Vector2::distance(const Vector2 & lhs, const Vector2 & rhs)
{
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y).getLength();
}


double Vector2::dot(const Vector2 & lhs, const Vector2 & rhs)
{
	return (lhs.x * rhs.x + lhs.y * rhs.y);
}


Vector2 operator-(const Vector2 & v2)
{
	return Vector2(-v2.x, -v2.y);
}


Vector2 operator+(Vector2 lhs, const Vector2 & rhs)
{
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}


Vector2 operator-(Vector2 lhs, const Vector2 & rhs)
{
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}


Vector2 operator*(double num, const Vector2 & v2)
{
	return Vector2(v2.x * num, v2.y * num);
}


Vector2 operator/(double num, const Vector2 & v2)
{
	return Vector2(v2.x / num, v2.y / num);
}


Vector2 operator*(Vector2 v2, double num)
{
	return operator*(num, v2);
}


Vector2 operator/(Vector2 v2, double num)
{
	return operator/(num, v2);
}


bool operator==(const Vector2 & v1, const Vector2 & v2)
{
	return (v1.x == v2.x && v1.y == v2.y);
}


bool operator!=(const Vector2 & v1, const Vector2 & v2)
{
	return !(v1 == v2);
}
