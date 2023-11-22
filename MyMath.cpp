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
