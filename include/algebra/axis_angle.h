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

#ifndef ALGEBRA__AXIS_ANGLE_H
#define ALGEBRA__AXIS_ANGLE_H

class Quaternion;

class AxisAngle
{
	friend Quaternion;
private:
	float _[4];
public:
	AxisAngle(void)
	{
	}
	
	AxisAngle(bool)
	{
		_[0] = 0.0f;
		_[1] = 0.0f;
		_[2] = 0.0f;
		_[3] = 0.0f;
	}
	
	AxisAngle(float X, float Y, float Z, float Angle)
	{
		_[0] = X;
		_[1] = Y;
		_[2] = Z;
		_[3] = Angle;
	}
	
	void Set(float X, float Y, float Z, float Angle)
	{
		_[0] = X;
		_[1] = Y;
		_[2] = Z;
		_[3] = Angle;
	}
	
	const float & operator[](int Index) const
	{
		return _[Index];
	}
	
	float & operator[](int Index)
	{
		return _[Index];
	}
};

#endif
