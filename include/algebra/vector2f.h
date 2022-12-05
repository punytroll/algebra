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

#ifndef ALGEBRA__VECTOR2F_H
#define ALGEBRA__VECTOR2F_H

#include <cmath>

class Vector2f
{
private:
	float _[2];
public:
	Vector2f(void)
	{
	}
	
	Vector2f(bool)
	{
		_[0] = 0.0f;
		_[1] = 0.0f;
	}
	
	Vector2f(Vector2f const & Other)
	{
		_[0] = Other._[0];
		_[1] = Other._[1];
	}
	
	Vector2f(float Value1, float Value2)
	{
		_[0] = Value1;
		_[1] = Value2;
	}
	
	static Vector2f CreateFromMagnitudeAndAngle(float Magnitude, float Angle)
	{
		return Vector2f(Magnitude * std::cos(Angle), Magnitude * std::sin(Angle));
	}
	
	Vector2f & Set(float Value1, float Value2)
	{
		_[0] = Value1;
		_[1] = Value2;
		
		return *this;
	}
	
	float Length(void) const
	{
		return std::sqrt(_[0] * _[0] + _[1] * _[1]);
	}
	
	float SquaredLength(void) const
	{
		return _[0] * _[0] + _[1] * _[1];
	}
	
	Vector2f & Normalize(void)
	{
		float L(std::sqrt(_[0] * _[0] + _[1] * _[1]));
		
		_[0] /= L;
		_[1] /= L;
		
		return *this;
	}
	
	Vector2f Normalized(void) const
	{
		float L(std::sqrt(_[0] * _[0] + _[1] * _[1]));
		
		return Vector2f(_[0] / L, _[1] / L);
	}
	
	Vector2f & Scale(float Scalar)
	{
		_[0] *= Scalar;
		_[1] *= Scalar;
		
		return *this;
	}
	
	Vector2f Scaled(float Scalar)
	{
		return Vector2f(_[0] * Scalar, _[1] * Scalar);
	}
	
	Vector2f operator+(const Vector2f & Other) const
	{
		return Vector2f(_[0] + Other._[0], _[1] + Other._[1]);
	}
	
	Vector2f operator-(const Vector2f & Other) const
	{
		return Vector2f(_[0] - Other._[0], _[1] - Other._[1]);
	}
	
	Vector2f operator*(float Scalar) const
	{
		return Vector2f(_[0] * Scalar, _[1] * Scalar);
	}
	
	Vector2f operator/(float Scalar) const
	{
		return Vector2f(_[0] / Scalar, _[1] / Scalar);
	}
	
	Vector2f & operator=(const Vector2f & Other)
	{
		_[0] = Other._[0];
		_[1] = Other._[1];
		
		return *this;
	}
	
	Vector2f & operator+=(const Vector2f & Other)
	{
		_[0] += Other._[0];
		_[1] += Other._[1];
		
		return *this;
	}
	
	Vector2f & operator-=(const Vector2f & Other)
	{
		_[0] -= Other._[0];
		_[1] -= Other._[1];
		
		return *this;
	}
	
	Vector2f & operator*=(float Scalar)
	{
		_[0] *= Scalar;
		_[1] *= Scalar;
		
		return *this;
	}
	
	Vector2f & operator/=(float Scalar)
	{
		_[0] /= Scalar;
		_[1] /= Scalar;
		
		return *this;
	}

	Vector2f operator+(void) const
	{
		return *this;
	}
	
	Vector2f operator-(void) const
	{
		return Vector2f(-_[0], -_[1]);
	}
	
	Vector2f & Negate(void)
	{
		_[0] = -_[0];
		_[1] = -_[1];
		
		return *this;
	}
	
	Vector2f Negated(void)
	{
		return Vector2f(-_[0], -_[1]);
	}
	
	float Dot(const Vector2f & Other) const
	{
		return _[0] * Other._[0] + _[1] * Other._[1];
	}
	
	Vector2f & Turn(float Angle)
	{
		float SinAngle(std::sin(Angle));
		float CosAngle(std::cos(Angle));
		float fX((CosAngle * _[0]) + (-SinAngle * _[1]));
		float fY((SinAngle * _[0]) + (CosAngle * _[1]));
		
		_[0] = fX;
		_[1] = fY;
		
		return *this;
	}
	
	Vector2f Turned(float Angle) const
	{
		float SinAngle(std::sin(Angle));
		float CosAngle(std::cos(Angle));
		
		return Vector2f((CosAngle * _[0]) + (-SinAngle * _[1]), (SinAngle * _[0]) + (CosAngle * _[1]));
	}
	
	const float & operator[](int Index) const
	{
		return _[Index];
	}
	
	float & operator[](int Index)
	{
		return _[Index];
	}
	
	bool operator==(const Vector2f & Other) const
	{
		return (_[0] == Other._[0]) && (_[1] == Other._[1]);
	}
	
	bool operator!=(const Vector2f & Other) const
	{
		return (_[0] != Other._[0]) || (_[1] != Other._[1]);
	}
};

inline Vector2f operator*(float Scalar, const Vector2f & Vector)
{
	return Vector2f(Scalar * Vector[0], Scalar * Vector[1]);
}

#endif
