#include "math/GameMath.h"
#include <cmath>

Vector::Vector()
    : x(0), y(0)
{
}

Vector::Vector(float x, float y)
    : x(x), y(y)
{
}

float Vector::Length() const
{
    return std::sqrt(x * x + y * y);
}

float Vector::LengthSqr() const
{
    return x * x + y * y;
}

Vector Vector::Normalize() const
{
    float len = Length();
    if (len == 0)
        return Vector();
    return (*this) / len;
}


// operations implementation 
Vector Vector::operator+(const Vector& v) const
{
    return Vector(x + v.x, y + v.y);
}

Vector Vector::operator-(const Vector& v) const
{
    return Vector(x - v.x, y - v.y);
}

Vector Vector::operator*(float s) const
{
    return Vector(x * s, y * s);
}

Vector Vector::operator/(float s) const
{
    return Vector(x / s, y / s);
}

// Point

Point::Point()
    : x(0), y(0)
{
}

Point::Point(float x, float y)
    : x(x), y(y)
{
}

Point Point::addVector(Vector v)
{
    return Point(x + v.x, y + v.y);
}

//
// Free function
//

Vector operator-(Point a, Point b)
{
    return Vector(
        a.x - b.x,
        a.y - b.y
    );
}