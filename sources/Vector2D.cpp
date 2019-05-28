#include "Vector2D.hpp"

Vector2D::Vector2D() {
    x = 0.0f;
    y = 0.0f;
}

Vector2D::Vector2D(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2D&   Vector2D::operator+(const Vector2D& vec) {
    this->x += vec.x;
    this->y += vec.y;
    return *this;
}

Vector2D&   Vector2D::operator-(const Vector2D& vec) {
    this->x -= vec.x;
    this->y -= vec.y;
    return *this;
}

Vector2D&   Vector2D::operator*(const Vector2D& vec) {
    this->x *= vec.x;
    this->y *= vec.y;
    return *this;
}

Vector2D&   Vector2D::operator/(const Vector2D& vec) {
    this->x /= vec.x;
    this->y /= vec.y;
    return *this;
}

Vector2D&   Vector2D::operator+=(const Vector2D& vec) {   
    return (*this + vec);
}

Vector2D&   Vector2D::operator-=(const Vector2D& vec) {
    return (*this - vec);
}

Vector2D&   Vector2D::operator*=(const Vector2D& vec) {
    return (*this * vec);
}

Vector2D&   Vector2D::operator/=(const Vector2D& vec) {
    return (*this / vec);
}

Vector2D&   Vector2D::operator*(const float& val) {
    this->x *= val;
    this->y *= val;
    return *this;
}

Vector2D&   Vector2D::operator/(const float& val) {
    this->x /= val;
    this->y /= val;
    return *this;
}

Vector2D&   Vector2D::Zero() {
    this->x = 0.0f;
    this->y = 0.0f;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& vec) {
    stream << "( " << vec.x << " , " << vec.y << " )" << std::endl;
    return stream;
}

