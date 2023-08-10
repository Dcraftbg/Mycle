#include "Vector.h"

MCLAPI Mycle::Vector4f::Vector4f(float v1, float v2, float v3, float v4) : x(v1), y(v2), z(v3), w(v4) {
}

MCLAPI Mycle::Vector4f::Vector4f(const Vector3f& v1, float v4)  : x(v1.x), y(v1.y), z(v1.z), w(v4) {
}

MCLAPI Mycle::Vector4f::Vector4f(const Vector2f& v1, float v3, float v4) : x(v1.x), y(v1.y), z(v3), w(v4) {}

MCLAPI Mycle::Vector4f Mycle::Vector4f::operator-(const Vector4f& other)
{
	return Vector4f(x-other.x, y-other.y, z-other.z, w-other.w);
}

MCLAPI Mycle::Vector4f Mycle::Vector4f::operator-(float f)
{
	return Vector4f(x-f,y-f,z-f,w-f);
}

MCLAPI Mycle::Vector4f Mycle::Vector4f::operator+(const Vector4f& other)
{
	return Vector4f(x + other.x, y + other.y, z + other.z, w + other.w);
}

MCLAPI Mycle::Vector4f Mycle::Vector4f::operator+(float f)
{
	return Vector4f(x + f, y + f, z + f, w + f);
}

MCLAPI Mycle::Vector4f Mycle::Vector4f::operator*(const Vector4f& other)
{
	return Vector4f(x * other.x, y * other.y, z * other.z, w * other.w);
}

MCLAPI Mycle::Vector4f Mycle::Vector4f::operator*(float f)
{
	return Vector4f(x * f, y * f, z * f, w * f);
}

Mycle::Vector3f::Vector3f(float v1, float v2, float v3) : x(v1), y(v2), z(v3) {}
Mycle::Vector3f::Vector3f(const Vector2f& v1, float v3) : x(v1.x), y(v1.y), z(v3) {}
