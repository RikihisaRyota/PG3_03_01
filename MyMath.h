#pragma once
#include "Quaternion.h"
#include "Matrix4x4.h"
#include "Vector3.h"

Vector3 Normalize(const Vector3& v1);

Matrix4x4 MakeIdentity4x4();

Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle);

Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);

Matrix4x4 DirectionToDirection(const Vector3& from, const Vector3& to);

float Dot(const Vector3& a, const Vector3& b);

Vector3 Cross(const Vector3& v1, const Vector3& v2);

Quaternion IdentityQuaternion();
Quaternion Conjugation(const Quaternion& quaternion);
Quaternion Normalize(const Quaternion& quaternion);
Quaternion Inverse(const Quaternion& quaternion);
Quaternion Add(const Quaternion& p1, const Quaternion& p2);
Quaternion Multiply(const Quaternion& p1, const Quaternion& p2);
Quaternion Multiply(const Quaternion& p1, float scalar);
float Norm(const Quaternion& quaternion);