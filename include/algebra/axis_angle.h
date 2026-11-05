/**
 * algebra
 * Copyright (C) 2007-2026  Hagen Möbius
 * SPDX-License-Identifier: MIT
**/

#ifndef ALGEBRA__AXIS_ANGLE_H
#define ALGEBRA__AXIS_ANGLE_H

class Quaternion;
class Vector3f;

namespace Algebra
{
    class AxisAngle
    {
        friend Quaternion;
        
    public:
        AxisAngle()
        {
        }
        
        static auto CreateZero() -> Algebra::AxisAngle;
        
        static auto CreateFromComponents(float X, float Y, float Z, float Angle) -> Algebra::AxisAngle;
        
        static auto CreateFromAxisAndAngle(Vector3f const & Axis, float Angle) -> Algebra::AxisAngle;
        
        static auto CreateNormalisedFromAxisAndAngle(Vector3f const & Axis, float Angle) -> Algebra::AxisAngle;
        
        void Set(float X, float Y, float Z, float Angle)
        {
            m_Components[0] = X;
            m_Components[1] = Y;
            m_Components[2] = Z;
            m_Components[3] = Angle;
        }
        
        const float & operator[](int Index) const
        {
            return m_Components[Index];
        }
        
        float & operator[](int Index)
        {
            return m_Components[Index];
        }
        
    private:
        float m_Components[4];
    };
}

/**
 * IMPLEMENTATION
 **/

#include <algebra/vector3f.h>

inline auto Algebra::AxisAngle::CreateZero() -> Algebra::AxisAngle
{
    auto Result = Algebra::AxisAngle{};
    
    Result.m_Components[0] = 0.0f;
    Result.m_Components[1] = 0.0f;
    Result.m_Components[2] = 0.0f;
    Result.m_Components[3] = 0.0f;
    
    return Result;
}

inline auto Algebra::AxisAngle::CreateFromComponents(float X, float Y, float Z, float Angle) -> Algebra::AxisAngle
{
    auto Result = Algebra::AxisAngle{};
    
    Result.m_Components[0] = X;
    Result.m_Components[1] = Y;
    Result.m_Components[2] = Z;
    Result.m_Components[3] = Angle;
    
    return Result;
}

inline auto Algebra::AxisAngle::CreateFromAxisAndAngle(Vector3f const & Axis, float Angle) -> Algebra::AxisAngle
{
    auto Result = Algebra::AxisAngle{};
    
    Result.m_Components[0] = Axis.m_Components[0];
    Result.m_Components[1] = Axis.m_Components[1];
    Result.m_Components[2] = Axis.m_Components[2];
    Result.m_Components[3] = Angle;
    
    return Result;
}

inline auto Algebra::AxisAngle::CreateNormalisedFromAxisAndAngle(Vector3f const & Axis, float Angle) -> Algebra::AxisAngle
{
    auto Result = Algebra::AxisAngle{};
    auto Length = Axis.Length();
    
    Result.m_Components[0] = Axis.m_Components[0] / Length;
    Result.m_Components[1] = Axis.m_Components[1] / Length;
    Result.m_Components[2] = Axis.m_Components[2] / Length;
    Result.m_Components[3] = Angle;
    
    return Result;
}

#endif
