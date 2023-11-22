#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"


Vector3 Normalize(const Vector3& v1);

Matrix4x4 MakeIdentity4x4();

Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle);

Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);