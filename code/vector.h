#ifndef _VECTOR_H_
#define _VECTOR_H_

struct Vector2 {
    Vector2() : x(0), y(0) {}
    Vector2(float ax, float ay) : x(ax), y(ay) {}
    Vector2 operator+(const Vector2& rhs)
    {
        Vector2 sum(x + rhs.x, y + rhs.y);
        return sum;
    }
    Vector2 operator-(const Vector2& rhs)
    {
        Vector2 sum(x - rhs.x, y - rhs.y);
        return sum;
    }
    Vector2 operator/(float rhs) {
        Vector2 r(x/rhs, y/rhs);
        return r;
    }
    Vector2 operator*(float rhs) {
        Vector2 r(x*rhs, y*rhs);
        return r;
    }
    Vector2& operator+=(const Vector2& rhs) {
          x += rhs.x;
          y += rhs.y;
          return *this;
    }
    Vector2& operator-=(const Vector2& rhs) {
          x -= rhs.x;
          y -= rhs.y;
          return *this;
    }
    int xInt() { return static_cast<int>(x); }
    int yInt() { return static_cast<int>(y); }

    float x;
    float y;
};

#endif
