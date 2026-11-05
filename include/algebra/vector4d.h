/**
 * algebra
 * Copyright (C) 2007-2026  Hagen Möbius
 * SPDX-License-Identifier: MIT
**/

#ifndef ALGEBRA__VECTOR4D_H
#define ALGEBRA__VECTOR4D_H

#include <cmath>

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
        return std::sqrt(m_V[0] * m_V[0] + m_V[1] * m_V[1] + m_V[2] * m_V[2] + m_V[3] * m_V[3]);
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
