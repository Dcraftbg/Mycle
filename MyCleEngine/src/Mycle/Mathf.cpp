#include "Mathf.h"
MCLAPI float Mycle::Math::dot(const Vector4f& a, const Vector4f& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

MCLAPI float Mycle::Math::dot(const Vector3f& a, const Vector3f& b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

MCLAPI float Mycle::Math::dot(const Vector2f& a, const Vector2f& b)
{
    return a.x*b.x + a.y*b.y;
}

MCLAPI Mycle::Vector3f Mycle::Math::cross(const Vector3f& a, const Vector3f& b)
{
    return Vector3f(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}
