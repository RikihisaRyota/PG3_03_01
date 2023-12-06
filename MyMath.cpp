#include "MyMath.h"

#include <assert.h>
#include <cmath>

Vector3 Normalize(const Vector3& v1) {
	Vector3 result = v1;
	float length = result.Length();
	result.x /= length;
	result.y /= length;
	result.z /= length;
	return result;
}

Matrix4x4 MakeIdentity4x4() {
	Matrix4x4 mat;
	mat.m[0][0] = 1.0f, mat.m[0][1] = 0.0f, mat.m[0][2] = 0.0f, mat.m[0][3] = 0.0f;
	mat.m[1][0] = 0.0f, mat.m[1][1] = 1.0f, mat.m[1][2] = 0.0f, mat.m[1][3] = 0.0f;
	mat.m[2][0] = 0.0f, mat.m[2][1] = 0.0f, mat.m[2][2] = 1.0f, mat.m[2][3] = 0.0f;
	mat.m[3][0] = 0.0f, mat.m[3][1] = 0.0f, mat.m[3][2] = 0.0f, mat.m[3][3] = 1.0f;
	return mat;
}

Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle) {
	Matrix4x4 mat{};
	mat = MakeIdentity4x4();
	mat.m[0][0] = axis.x * axis.x * (1 - std::cosf(angle)) + std::cosf(angle),
	mat.m[0][1] = axis.x * axis.y * (1 - std::cosf(angle)) + axis.z * std::sinf(angle),
	mat.m[0][2] = axis.x * axis.z * (1 - std::cosf(angle)) - axis.y * std::sinf(angle);
	mat.m[1][0] = axis.x * axis.y * (1 - std::cosf(angle)) - axis.x * std::sinf(angle),
	mat.m[1][1] = axis.y * axis.y * (1 - std::cosf(angle)) + std::cosf(angle),
	mat.m[1][2] = axis.y * axis.z * (1 - std::cosf(angle)) + axis.x * std::sinf(angle);
	mat.m[2][0] = axis.x * axis.z * (1 - std::cosf(angle)) + axis.y * std::sinf(angle),
	mat.m[2][1] = axis.y * axis.z * (1 - std::cosf(angle)) - axis.z * std::sinf(angle),
	mat.m[2][2] = axis.z * axis.z * (1 - std::cosf(angle)) + std::cosf(angle);
	return mat;
}

Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix) {
	Vector3 result{0.0f, 0.0f, 0.0f};
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] +
	           1.0f * matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] +
	           1.0f * matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] +
	           1.0f * matrix.m[3][2];
	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] +
	          1.0f * matrix.m[3][3];

	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;
	return result;
}

Matrix4x4 DirectionToDirection(const Vector3& from, const Vector3& to) {
	Vector3 cross = Cross(from, to);
	float sin = cross.Length();
	float cos = Dot(from, to);
	Vector3 n{};
	if (cross.Length() > 0) {
		n = Normalize(cross);
	} else if (from.x != 0.0f || from.z != 0.0f) {
		n.x = from.y;
		n.y = -from.x;
		n.z = 0.0f;
	} else if (from.x != 0.0f || from.y != 0.0f) {
		n.x = from.z;
		n.y = 0.0f;
		n.z = -from.x;
	}
	Matrix4x4 mat{};
	mat = MakeIdentity4x4();
	mat.m[0][0] = n.x * n.x * (1.0f - cos) + cos,
	mat.m[0][1] = n.x * n.y * (1.0f - cos) + n.z * sin,
	mat.m[0][2] = n.x * n.z * (1.0f - cos) - n.y * sin;
	mat.m[1][0] = n.x * n.y * (1.0f - cos) - n.z * sin,
	mat.m[1][1] = n.y * n.y * (1.0f - cos) + cos,
	mat.m[1][2] = n.y * n.z * (1.0f - cos) + n.x * sin;
	mat.m[2][0] = n.x * n.z * (1.0f - cos) + n.y * sin,
	mat.m[2][1] = n.y * n.z * (1.0f - cos) - n.x * sin,
	mat.m[2][2] = n.z * n.z * (1.0f - cos) + cos;
	return mat;
}

float Dot(const Vector3& a, const Vector3& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

Vector3 Cross(const Vector3& a, const Vector3& b) {
	return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

Quaternion IdentityQuaternion() { return Quaternion(0.0f, 0.0f, 0.0f, 1.0f); }

Quaternion Conjugation(const Quaternion& quaternion) {
	return Quaternion(-quaternion.x, -quaternion.y, -quaternion.z, quaternion.w);
}

Quaternion Normalize(const Quaternion& quaternion) {
	float length = std::sqrt(
	    quaternion.x * quaternion.x + quaternion.y * quaternion.y + quaternion.z * quaternion.z +
	    quaternion.w * quaternion.w);

	if (length != 0.0f) {
		float inversLength = 1.0f / length;
		return Quaternion(
		    quaternion.x * inversLength, quaternion.y * inversLength, quaternion.z * inversLength,
		    quaternion.w * inversLength);
	} else {
		return quaternion;
	}
}

Quaternion Inverse(const Quaternion& quaternion) {
	float length = Norm(quaternion);
	length *= length;
	Quaternion conjugate = Conjugation(quaternion);
	Quaternion result{};
	result.x = conjugate.x / length;
	result.y = conjugate.y / length;
	result.z = conjugate.z / length;
	result.w = conjugate.w / length;
	return result;
}

Quaternion Add(const Quaternion& p1, const Quaternion& p2) {
	return Quaternion(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z, p1.w + p2.w);
}

Quaternion Multiply(const Quaternion& p1, const Quaternion& p2) {
	Quaternion result;
	Vector3 qv = {p1.x, p1.y, p1.z};
	Vector3 rv = {p2.x, p2.y, p2.z};

	result.w = p1.w * p2.w - Dot(qv, rv);
	Vector3 t = Cross(qv, rv) + (qv * p2.w) + (rv * p1.w);
	result.x = t.x;
	result.y = t.y;
	result.z = t.z;
	return result;
}

Quaternion Multiply(const Quaternion& p1, float scalar) {
	return Quaternion(p1.x * scalar, p1.y * scalar, p1.z * scalar, p1.w * scalar);
}

float Norm(const Quaternion& quaternion) {
	return std::sqrt(
	    quaternion.x * quaternion.x + quaternion.y * quaternion.y + quaternion.z * quaternion.z +
	    quaternion.w * quaternion.w);
}
