/**
 * algebra
 * Copyright (C) 2007-2026  Hagen Möbius
 * SPDX-License-Identifier: MIT
**/

#ifndef ALGEBRA__AXIS_ANGLE_H
#define ALGEBRA__AXIS_ANGLE_H

class Quaternion;

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
        
        AxisAngle(float X, float Y, float Z, float Angle)
        {
            m_Components[0] = X;
            m_Components[1] = Y;
            m_Components[2] = Z;
            m_Components[3] = Angle;
        }
        
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

inline auto Algebra::AxisAngle::CreateZero() -> Algebra::AxisAngle
{
    auto Result = Algebra::AxisAngle{};
    
    Result.m_Components[0] = 0.0f;
    Result.m_Components[1] = 0.0f;
    Result.m_Components[2] = 0.0f;
    Result.m_Components[3] = 0.0f;
    
    return Result;
}

#endif
