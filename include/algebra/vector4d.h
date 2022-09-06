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

#ifndef ALGEBRA__VECTOR4D_H
#define ALGEBRA__VECTOR4D_H

class Vector4d
{
public:
	double m_V[4];
	
	Vector4d(void)
	{
	}
	
	Vector4d(bool)
	{
		m_V[0] = m_V[1] = m_V[2] = m_V[3] = 0.0;
	}
	
	Vector4d(const double & Value1, const double & Value2, const double & Value3, const double & Value4)
	{
		m_V[0] = Value1;
		m_V[1] = Value2;
		m_V[2] = Value3;
		m_V[3] = Value4;
	}
	
	void Set(const double & Value1, const double & Value2, const double & Value3, const double & Value4)
	{
		m_V[0] = Value1;
		m_V[1] = Value2;
		m_V[2] = Value3;
		m_V[3] = Value4;
	}
	
	double Length(void) const
	{
		return sqrt(m_V[0] * m_V[0] + m_V[1] * m_V[1] + m_V[2] * m_V[2] + m_V[3] * m_V[3]);
	}
	
	double SquaredLength(void) const
	{
		return m_V[0] * m_V[0] + m_V[1] * m_V[1] + m_V[2] * m_V[2] + m_V[3] * m_V[3];
	}
	
	const double & operator[](int Index) const
	{
		return m_V[Index];
	}
	
	double & operator[](int Index)
	{
		return m_V[Index];
	}
};

inline Vector4d operator*(double Scalar, const Vector4d & Vector)
{
	return Vector4d(Scalar * Vector[0], Scalar * Vector[1], Scalar * Vector[2], Scalar * Vector[3]);
}

#endif
