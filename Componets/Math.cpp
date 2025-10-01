#include "Math.h"
#include <cmath>

namespace Math {
	// Vector2 Add(+) Vector2
	Vector2 Vector2::operator+(const Vector2& other) const {
		return { x + other.x, y + other.y };
	}
	Vector2& Vector2::operator+=(const Vector2& other) {
		return *this = *this + other;
	}
	// Vector2 Subtract(-) Vector2
	Vector2 Vector2::operator-(const Vector2& other) const {
		return { x - other.x, y - other.y };
	}
	Vector2& Vector2::operator-=(const Vector2& other) {
		return *this = *this - other;
	}
	// Vector2 Multiply(*) float
	Vector2 Vector2::operator*(const float& other) const {
		return { x * other, y * other };
	}
	Vector2& Vector2::operator*=(const float& other) {
		return *this = *this * other;
	}
	Vector2 Vector2::operator/(const float& other) const {
		return { x / other, y / other };
	}
	Vector2& Vector2::operator/=(const float& other) {
		return *this = *this / other;
	}

	float Vector2::Length() {
		return sqrtf(x * x + y * y);
	}
	Vector2 Vector2::Normalize() {
		Vector2 norm = { x,y };
		float length = Length();
		if (length != 0.0f) {
			norm.x /= length;
			norm.y /= length;
		}
		return norm;
	}
	Vector2 Vector2::Rotate(float radian) {
		Vector2 result;
		result.x = x * cosf(radian) - y * sinf(radian);
		result.y = y * cosf(radian) + x * sinf(radian);
		return result;
	}
}