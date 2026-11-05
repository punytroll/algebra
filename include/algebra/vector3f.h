/**
 * algebra
 * Copyright (C) 2007-2026  Hagen Möbius
 * SPDX-License-Identifier: MIT
**/

#ifndef ALGEBRA__VECTOR3F_H
#define ALGEBRA__VECTOR3F_H

#include <cmath>

class Matrix3f;
class Matrix4f;
class Quaternion;
class Vector4f;

namespace Algebra
{
    class AxisAngle;
}

class Vector3f
{
    friend Algebra::AxisAngle;
    friend Matrix4f;
    friend Quaternion;
    
public:
    Vector3f()
    {
    }
    
    Vector3f(Vector3f const & Other)
    {
        m_Components[0] = Other.m_Components[0];
        m_Components[1] = Other.m_Components[1];
        m_Components[2] = Other.m_Components[2];
    }
    
    static Vector3f CreateFromComponents(float Value1, float Value2, float Value3);
    
    static Vector3f CreateFromVector4f(const Vector4f & Vector);
    
    static Vector3f CreateTranslationX(float X);
    
    static Vector3f CreateTranslationY(float Y);
    
    static Vector3f CreateTranslationZ(float Z);
    
    static Vector3f CreateZero();
    
    Vector3f & Set(float Value1, float Value2, float Value3)
    {
        m_Components[0] = Value1;
        m_Components[1] = Value2;
        m_Components[2] = Value3;
        
        return *this;
    }
    
    float Length(void) const
    {
        return std::sqrt(m_Components[0] * m_Components[0] + m_Components[1] * m_Components[1] + m_Components[2] * m_Components[2]);
    }
    
    float SquaredLength(void) const
    {
        return m_Components[0] * m_Components[0] + m_Components[1] * m_Components[1] + m_Components[2] * m_Components[2];
    }
    
    Vector3f & Negate(void);
    
    Vector3f Negated(void) const;
    
    Vector3f & Normalize(void)
    {
        return operator/=(Length());
    }
    
    Vector3f Normalized(void) const
    {
        return *this / Length();
    }
    
    Vector3f operator+(const Vector3f & Other) const
    {
        return CreateFromComponents(m_Components[0] + Other.m_Components[0], m_Components[1] + Other.m_Components[1], m_Components[2] + Other.m_Components[2]);
    }
    
    Vector3f operator-(const Vector3f & Other) const
    {
        return CreateFromComponents(m_Components[0] - Other.m_Components[0], m_Components[1] - Other.m_Components[1], m_Components[2] - Other.m_Components[2]);
    }

    Vector3f operator+(void) const
    {
        return *this;
    }
    
    Vector3f operator-(void) const
    {
        return CreateFromComponents(-m_Components[0], -m_Components[1], -m_Components[2]);
    }
    
    Vector3f operator*(float Scalar) const
    {
        return CreateFromComponents(m_Components[0] * Scalar, m_Components[1] * Scalar, m_Components[2] * Scalar);
    }
    
    Vector3f operator/(float Scalar) const
    {
        return CreateFromComponents(m_Components[0] / Scalar, m_Components[1] / Scalar, m_Components[2] / Scalar);
    }
    
    Vector3f operator%(const Vector3f & Other)
    {
        return Cross(Other);
    }
    
    Vector3f & operator=(const Vector3f & Other)
    {
        m_Components[0] = Other.m_Components[0];
        m_Components[1] = Other.m_Components[1];
        m_Components[2] = Other.m_Components[2];
        
        return *this;
    }
    
    Vector3f & operator-=(const Vector3f & Other)
    {
        m_Components[0] -= Other.m_Components[0];
        m_Components[1] -= Other.m_Components[1];
        m_Components[2] -= Other.m_Components[2];
        
        return *this;
    }
    
    Vector3f & operator*=(float Scalar)
    {
        m_Components[0] *= Scalar;
        m_Components[1] *= Scalar;
        m_Components[2] *= Scalar;
        
        return *this;
    }
    
    Vector3f & operator/=(float Scalar)
    {
        m_Components[0] /= Scalar;
        m_Components[1] /= Scalar;
        m_Components[2] /= Scalar;
        
        return *this;
    }
    
    float Dot(const Vector3f & Other) const
    {
        return m_Components[0] * Other.m_Components[0] + m_Components[1] * Other.m_Components[1] + m_Components[2] * Other.m_Components[2];
    }
    
    Vector3f Cross(const Vector3f & Other) const
    {
        return CreateFromComponents(m_Components[1] * Other.m_Components[2] - m_Components[2] * Other.m_Components[1], m_Components[2] * Other.m_Components[0] - m_Components[0] * Other.m_Components[2], m_Components[0] * Other.m_Components[1] - m_Components[1] * Other.m_Components[0]);
    }
    
    Vector3f & operator*=(const Matrix3f & Matrix);
    
    Vector3f & Transform(const Matrix4f & Matrix);
    
    Vector3f & Translate(const Vector3f & Vector);
    
    Vector3f & Rotate(const Quaternion & Quaternion);
    
    Vector3f & Scale(float Scale);
    
    Vector3f Scaled(float Scale) const;
    
    const float & operator[](int Index) const
    {
        return m_Components[Index];
    }
    
    float & operator[](int Index)
    {
        return m_Components[Index];
    }
    
    float const * GetPointer(void) const
    {
        return m_Components;
    }
    
private:
    float m_Components[3];
};

/**
 * IMPLEMENTATION
 **/

#include <algebra/matrix3f.h>
#include <algebra/matrix4f.h>
#include <algebra/quaternion.h>
#include <algebra/vector4f.h>
    
inline Vector3f Vector3f::CreateFromComponents(float Value0, float Value1, float Value2)
{
    Vector3f Result;
    
    Result.m_Components[0] = Value0;
    Result.m_Components[1] = Value1;
    Result.m_Components[2] = Value2;
    
    return Result;
}

inline Vector3f Vector3f::CreateFromVector4f(const Vector4f & Vector)
{
    Vector3f Result;
    
    Result.m_Components[0] = Vector._[0];
    Result.m_Components[1] = Vector._[1];
    Result.m_Components[2] = Vector._[2];
    
    return Result;
}
    
inline Vector3f Vector3f::CreateTranslationX(float X)
{
    Vector3f Result;
    
    Result.m_Components[0] = X;
    Result.m_Components[1] = 0.0f;
    Result.m_Components[2] = 0.0f;
    
    return Result;
}

inline Vector3f Vector3f::CreateTranslationY(float Y)
{
    Vector3f Result;
    
    Result.m_Components[0] = 0.0f;
    Result.m_Components[1] = Y;
    Result.m_Components[2] = 0.0f;
    
    return Result;
}

inline Vector3f Vector3f::CreateTranslationZ(float Z)
{
    Vector3f Result;
    
    Result.m_Components[0] = 0.0f;
    Result.m_Components[1] = 0.0f;
    Result.m_Components[2] = Z;
    
    return Result;
}

inline Vector3f Vector3f::CreateZero(void)
{
    Vector3f Result;
    
    Result.m_Components[0] = 0.0f;
    Result.m_Components[1] = 0.0f;
    Result.m_Components[2] = 0.0f;
    
    return Result;
}

inline Vector3f & Vector3f::Negate(void)
{
    m_Components[0] = -m_Components[0];
    m_Components[1] = -m_Components[1];
    m_Components[2] = -m_Components[2];
    
    return *this;
}

inline Vector3f Vector3f::Negated(void) const
{
    Vector3f Result;
    
    Result.m_Components[0] = -m_Components[0];
    Result.m_Components[1] = -m_Components[1];
    Result.m_Components[2] = -m_Components[2];
    
    return Result;
}

inline Vector3f & Vector3f::operator*=(const Matrix3f & Matrix)
{
    float Value0((Matrix._[0] * m_Components[0]) + (Matrix._[3] * m_Components[1]) + (Matrix._[6] * m_Components[2]));
    float Value1((Matrix._[1] * m_Components[0]) + (Matrix._[4] * m_Components[1]) + (Matrix._[7] * m_Components[2]));
    float Value2((Matrix._[2] * m_Components[0]) + (Matrix._[5] * m_Components[1]) + (Matrix._[8] * m_Components[2]));
    
    m_Components[0] = Value0;
    m_Components[1] = Value1;
    m_Components[2] = Value2;
    
    return *this;
}

inline Vector3f & Vector3f::Transform(const Matrix4f & Matrix)
{
    float Value0((Matrix._[0] * m_Components[0]) + (Matrix._[4] * m_Components[1]) + (Matrix._[8] * m_Components[2]) + Matrix._[12]);
    float Value1((Matrix._[1] * m_Components[0]) + (Matrix._[5] * m_Components[1]) + (Matrix._[9] * m_Components[2]) + Matrix._[13]);
    float Value2((Matrix._[2] * m_Components[0]) + (Matrix._[6] * m_Components[1]) + (Matrix._[10] * m_Components[2]) + Matrix._[14]);
    
    m_Components[0] = Value0;
    m_Components[1] = Value1;
    m_Components[2] = Value2;
    
    return *this;
}

inline Vector3f & Vector3f::Translate(const Vector3f & Vector)
{
    m_Components[0] += Vector.m_Components[0];
    m_Components[1] += Vector.m_Components[1];
    m_Components[2] += Vector.m_Components[2];
    
    return *this;
}

inline Vector3f & Vector3f::Rotate(const Quaternion & Quaternion)
{
    auto Term1(Quaternion._[3] - m_Components[0] * Quaternion._[2] + m_Components[1] * Quaternion._[1] + m_Components[2] * Quaternion._[0]);
    auto Term2(Quaternion._[2] + m_Components[0] * Quaternion._[3] + m_Components[1] * Quaternion._[0] - m_Components[2] * Quaternion._[1]);
    auto Term3(Quaternion._[1] + m_Components[0] * Quaternion._[0] - m_Components[1] * Quaternion._[3] + m_Components[2] * Quaternion._[2]);
    auto Term4(Quaternion._[0] - m_Components[0] * Quaternion._[1] - m_Components[1] * Quaternion._[2] - m_Components[2] * Quaternion._[3]);
    
    m_Components[0] = Quaternion._[2] * Term1 - Quaternion._[3] * Term2 + Quaternion._[0] * Term3 - Quaternion._[1] * Term4;
    m_Components[1] = -Quaternion._[1] * Term1 + Quaternion._[0] * Term2 + Quaternion._[3] * Term3 - Quaternion._[2] * Term4;
    m_Components[2] = Quaternion._[0] * Term1 + Quaternion._[1] * Term2 - Quaternion._[2] * Term3 - Quaternion._[3] * Term4;
    
    return *this;
}

inline Vector3f & Vector3f::Scale(float Scale)
{
    m_Components[0] *= Scale;
    m_Components[1] *= Scale;
    m_Components[2] *= Scale;
    
    return *this;
}

inline Vector3f Vector3f::Scaled(float Scale) const
{
    Vector3f Result;
    
    Result.m_Components[0] = Scale * m_Components[0];
    Result.m_Components[1] = Scale * m_Components[1];
    Result.m_Components[2] = Scale * m_Components[2];
    
    return Result;
}

#endif
