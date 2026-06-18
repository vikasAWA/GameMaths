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

// dot product 
float Vector::dotProduct(const Vector& v) const
{
    return (x * v.x + y * v.y);
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

Point Point::operator+(const Vector& v) const
{
    return Point(x+v.x, y+v.y);
}

float Point::Distance(const Point& other) const
{
    Vector v{other - (*this)};
    return v.Length();
}

//
// Free function
float Lerp(float start, float end, float t)
{
    return start + (end - start) * t;
}

float Approach(float current, float goal, float dt){
    if (current < goal)
    {
        current += dt;
        if (current > goal) current = goal;
    }
    else if (current > goal)
    {
        current -= dt;
        if (current < goal) current = goal;
    }
    return current;
}

Vector operator-(Point a, Point b)
{
    return Vector(
        a.x - b.x,
        a.y - b.y
    );
}