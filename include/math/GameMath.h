#pragma once

class Vector
{
public:
    float x, y;

    Vector();
    Vector(float x, float y);

    float Length() const;
    float LengthSqr() const;

    Vector operator*(float s) const;
    Vector operator/(float s) const;
};

class Point
{
public:
    float x, y;

    Point();
    Point(float x, float y);

    Point addVector(Vector v);
};

Vector operator-(Point a, Point b);

