#pragma once
#include "Vector.h"
#include "Utils.h"
namespace Mycle {
	namespace Math {
		MCLAPI float dot(const Vector4f& a, const Vector4f& b);
		MCLAPI float dot(const Vector3f& a, const Vector3f& b);
		MCLAPI float dot(const Vector2f& a, const Vector2f& b);
		

		MCLAPI Vector3f cross(const Vector3f& a, const Vector3f& b);
	}
}
