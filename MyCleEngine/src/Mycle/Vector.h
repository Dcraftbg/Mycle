#pragma once
#include "Utils.h"
namespace Mycle {
	class MCLAPI Vector2f {
	public:
		float x;
		float y;
	};
	class MCLAPI Vector2i {
	public:
		union{
			int x;
			int width;
		};
		union {
			int y;
			int height;
		};
	};
	class MCLAPI Vector3f {
	public:
		Vector3f(float v1, float v2, float v3);
		Vector3f(const Vector2f& v1, float v3);
		union {
			float x;
			float r;
		};
		union {
			float y;
			float g;
		};
		union {
			float z;
			float b;
		};
	};
	class MCLAPI Vector4f {
	public:
		Vector4f(float v1, float v2, float v3, float v4);
		Vector4f(const Vector3f& v1, float v4);
		Vector4f(const Vector2f& v1, float v3, float v4);
	public:
		union {
			float x;
			float r;
		};
		union {
			float y;
			float g;
		};
		union {
			float z;
			float b;
		};
		union
		{
			float w;
			float a;
		};

		Vector4f operator-(const Vector4f& other);
		Vector4f operator-(float f);
		Vector4f operator+(const Vector4f& other);
		Vector4f operator+(float f);
		Vector4f operator*(const Vector4f& other);
		Vector4f operator*(float f);
	};
	
}