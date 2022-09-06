/**
 * algebra
 * Copyright (C) 2007-2022  Hagen Möbius
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
**/

#ifndef ALGEBRA__VECTOR4F_H
#define ALGEBRA__VECTOR4F_H

class Matrix4f;
class Quaternion;
class Vector3f;

class Vector4f
{
	friend Matrix4f;
	friend Vector3f;
	friend Vector4f operator*(float Scalar, const Vector4f & Vector);
private:
	float _[4];
public:
	Vector4f(void)
	{
	}
	
	Vector4f(bool)
	{
		_[0] = 0.0f;
		_[1] = 0.0f;
		_[2] = 0.0f;
		_[3] = 0.0f;
	}
	
	Vector4f(float Value1, float Value2, float Value3, float Value4)
	{
		_[0] = Value1;
		_[1] = Value2;
		_[2] = Value3;
		_[3] = Value4;
	}
	
	Vector4f & Set(float Value1, float Value2, float Value3, float Value4)
	{
		_[0] = Value1;
		_[1] = Value2;
		_[2] = Value3;
		_[3] = Value4;
		
		return *this;
	}
	
	float Length(void) const
	{
		return sqrtf(_[0] * _[0] + _[1] * _[1] + _[2] * _[2] + _[3] * _[3]);
	}
	
	float SquaredLength(void) const
	{
		return _[0] * _[0] + _[1] * _[1] + _[2] * _[2] + _[3] * _[3];
	}
	
	Vector4f & Normalize(void)
	{
		float L(sqrtf(_[0] * _[0] + _[1] * _[1] + _[2] * _[2] + _[3] * _[3]));
		
		_[0] /= L;
		_[1] /= L;
		_[2] /= L;
		_[3] /= L;
		
		return *this;
	}
	
	Vector4f Normalized(void) const
	{
		float L(sqrtf(_[0] * _[0] + _[1] * _[1] + _[2] * _[2] + _[3] * _[3]));
		
		return Vector4f(_[0] / L, _[1] / L, _[2] / L, _[3] / L);
	}
	
	Vector4f operator+(const Vector4f & Other) const
	{
		return Vector4f(_[0] + Other._[0], _[1] + Other._[1], _[2] + Other._[2], _[3] + Other._[3]);
	}
	
	Vector4f operator-(const Vector4f & Other) const
	{
		return Vector4f(_[0] - Other._[0], _[1] - Other._[1], _[2] - Other._[2], _[3] - Other._[3]);
	}
	
	Vector4f operator*(float Scalar) const
	{
		return Vector4f(_[0] * Scalar, _[1] * Scalar, _[2] * Scalar, _[3] * Scalar);
	}
	
	Vector4f operator/(float Scalar) const
	{
		return Vector4f(_[0] / Scalar, _[1] / Scalar, _[2] / Scalar, _[3] / Scalar);
	}
	
	Vector4f & operator=(const Vector4f & Other)
	{
		_[0] = Other._[0];
		_[1] = Other._[1];
		_[2] = Other._[2];
		_[3] = Other._[3];
		
		return *this;
	}
	
	Vector4f & operator+=(const Vector4f & Other)
	{
		_[0] += Other._[0];
		_[1] += Other._[1];
		_[2] += Other._[2];
		_[3] += Other._[3];
		
		return *this;
	}
	
	Vector4f & operator-=(const Vector4f & Other)
	{
		_[0] -= Other._[0];
		_[1] -= Other._[1];
		_[2] -= Other._[2];
		_[3] -= Other._[3];
		
		return *this;
	}
	
	Vector4f & operator*=(float Scalar)
	{
		_[0] *= Scalar;
		_[1] *= Scalar;
		_[2] *= Scalar;
		_[3] *= Scalar;
		
		return *this;
	}
	
	Vector4f & operator/=(float Scalar)
	{
		_[0] /= Scalar;
		_[1] /= Scalar;
		_[2] /= Scalar;
		_[3] /= Scalar;
		
		return *this;
	}

	Vector4f operator+(void) const
	{
		return *this;
	}
	
	Vector4f operator-(void) const
	{
		return Vector4f(-_[0], -_[1], -_[2], -_[3]);
	}
	
	float Dot(const Vector4f & Other) const
	{
		return _[0] * Other._[0] + _[1] * Other._[1] + _[2] * Other._[2] + _[3] * Other._[3];
	}
	
	Vector4f & operator*=(const Quaternion & Quaternion);
	
	const float & operator[](int Index) const
	{
		return _[Index];
	}
	
	float & operator[](int Index)
	{
		return _[Index];
	}
	
	const float * const GetPointer(void) const
	{
		return _;
	}
};

/**
 * IMPLEMENTATION
 **/

#include "quaternion.h"

inline Vector4f & Vector4f::operator*=(const Quaternion & AQuaternion)
{
	Quaternion Result(AQuaternion * Quaternion(_[3], _[0], _[1], _[2]) * AQuaternion.Conjugated());
	
	_[0] = Result._[1];
	_[1] = Result._[2];
	_[2] = Result._[3];
	_[3] = Result._[0];
	
	return *this;
}

inline Vector4f operator*(float Scalar, const Vector4f & Vector)
{
	return Vector4f(Scalar * Vector._[0], Scalar * Vector._[1], Scalar * Vector._[2], Scalar * Vector._[3]);
}

#endif
