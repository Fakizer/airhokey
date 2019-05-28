#pragma once
#include <iostream>

class Vector2D {
public:
    float x;
    float y;

    
    Vector2D();
    Vector2D(float x, float y);

    Vector2D& Zero();

    Vector2D& operator+(const Vector2D& vec);
    Vector2D& operator-(const Vector2D& vec);
    Vector2D& operator*(const Vector2D& vec);
    Vector2D& operator/(const Vector2D& vec);

    Vector2D& operator+=(const Vector2D& vec);
    Vector2D& operator-=(const Vector2D& vec);
    Vector2D& operator*=(const Vector2D& vec);
    Vector2D& operator/=(const Vector2D& vec);

    // Vector2D& operator+(const int val);
    // Vector2D& operator-(const int val);
    Vector2D& operator*(const float& val);
    Vector2D& operator/(const float& val);

    friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);
};