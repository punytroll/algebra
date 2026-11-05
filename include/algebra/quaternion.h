/**
 * algebra
 * Copyright (C) 2007-2026  Hagen Möbius
 * SPDX-License-Identifier: MIT
**/

#ifndef ALGEBRA__QUATERNION_H
#define ALGEBRA__QUATERNION_H

#include <cmath>

#include <algebra/axis_angle.h>

class Matrix4f;
class Vector3f;
class Vector4f;

class Quaternion
{
    friend Matrix4f;
    friend Vector3f;
    friend Vector4f;
private:
    float _[4];
public:
    Quaternion()
    {
    }
    
    static auto CreateIdentity() -> Quaternion;
    
    Quaternion(float W, float X, float Y, float Z)
    {
        _[0] = W;
        _[1] = X;
        _[2] = Y;
        _[3] = Z;
    }
    
    static auto CreateFromAxisAngle(Algebra::AxisAngle const & AxisAngle) -> Quaternion
    {
        return CreateIdentity().Rotation(AxisAngle);
    }
    
    static Quaternion CreateFromAxisAndAngle(const Vector3f & Axis, float AngleInRadians);
    
    static Quaternion CreateFromAxisComponentsAndAngle(float X, float Y, float Z, float AngleInRadians)
    {
        return Quaternion().Rotation(X, Y, Z, AngleInRadians);
    }
    
    static Quaternion CreateAsRotationX(float AngleInRadians)
    {
        return Quaternion().RotationX(AngleInRadians);
    }
    
    static Quaternion CreateAsRotationY(float AngleInRadians)
    {
        return Quaternion().RotationY(AngleInRadians);
    }
    
    static Quaternion CreateAsRotationZ(float AngleInRadians)
    {
        return Quaternion().RotationZ(AngleInRadians);
    }
    
    Quaternion & Identity(void)
    {
        _[0] = 1.0f;
        _[1] = 0.0f;
        _[2] = 0.0f;
        _[3] = 0.0f;
        
        return *this;
    }
    
    Quaternion & Conjugate(void)
    {
        _[1] = -_[1];
        _[2] = -_[2];
        _[3] = -_[3];
        
        return *this;
    }
    
    Quaternion Conjugated(void) const
    {
        return Quaternion(_[0], -_[1], -_[2], -_[3]);
    }
    
    Quaternion & RotationX(float Radians)
    {
        Radians /= 2.0f;
        _[0] = std::cos(Radians);
        _[1] = std::sin(Radians);
        _[2] = 0.0f;
        _[3] = 0.0f;
        
        return *this;
    }
    
    Quaternion & RotationY(float Radians)
    {
        Radians /= 2.0f;
        _[0] = std::cos(Radians);
        _[1] = 0.0f;
        _[2] = std::sin(Radians);
        _[3] = 0.0f;
        
        return *this;
    }
    
    Quaternion & RotationZ(float Radians)
    {
        Radians /= 2.0f;
        _[0] = std::cos(Radians);
        _[1] = 0.0f;
        _[2] = 0.0f;
        _[3] = std::sin(Radians);
        
        return *this;
    }
    
    auto Rotation(Algebra::AxisAngle const & AxisAngle) -> Quaternion &
    {
        auto AngleInRadians = AxisAngle.m_Components[3] / 2.0f;
        auto SinusRadians = std::sin(AngleInRadians);
        
        _[0] = std::cos(AngleInRadians);
        _[1] = AxisAngle.m_Components[0] * SinusRadians;
        _[2] = AxisAngle.m_Components[1] * SinusRadians;
        _[3] = AxisAngle.m_Components[2] * SinusRadians;
        
        return *this;
    }
    
    Quaternion & Rotation(float X, float Y, float Z, float AngleInRadians)
    {
        AngleInRadians /= 2.0f;
        
        float SinusRadians(std::sin(AngleInRadians));
        
        _[0] = std::cos(AngleInRadians);
        _[1] = X * SinusRadians;
        _[2] = Y * SinusRadians;
        _[3] = Z * SinusRadians;
        
        return *this;
    }
    
    Quaternion Rotated(float X, float Y, float Z, float AngleInRadians)
    {
        AngleInRadians /= 2.0f;
        
        float Sinus(std::sin(AngleInRadians));
        float SinusX(Sinus * X);
        float SinusY(Sinus * Y);
        float SinusZ(Sinus * Z);
        float Cosinus(std::cos(AngleInRadians));
        
        return Quaternion(_[0] * Cosinus - _[1] * SinusX - _[2] * SinusY - _[3] * SinusZ, _[1] * Cosinus + _[0] * SinusX - _[3] * SinusY + _[2] * SinusZ, _[2] * Cosinus + _[3] * SinusX + _[0] * SinusY - _[1] * SinusZ, _[3] * Cosinus - _[2] * SinusX + _[1] * SinusY + _[0] * SinusZ);
    }
    
    Quaternion RotatedX(float AngleInRadians) const
    {
        AngleInRadians /= 2.0f;
        
        float Sinus(std::sin(AngleInRadians));
        float Cosinus(std::cos(AngleInRadians));
        
        return Quaternion(_[0] * Cosinus - _[1] * Sinus, _[1] * Cosinus + _[0] * Sinus, _[2] * Cosinus + _[3] * Sinus, _[3] * Cosinus - _[2] * Sinus);
    }
    
    Quaternion RotatedY(float AngleInRadians) const
    {
        AngleInRadians /= 2.0f;
        
        float Sinus(std::sin(AngleInRadians));
        float Cosinus(std::cos(AngleInRadians));
        
        return Quaternion(_[0] * Cosinus - _[2] * Sinus, _[1] * Cosinus - _[3] * Sinus, _[2] * Cosinus + _[0] * Sinus, _[3] * Cosinus + _[1] * Sinus);
    }
    
    Quaternion RotatedZ(float AngleInRadians) const
    {
        AngleInRadians /= 2.0f;
        
        float Sinus(std::sin(AngleInRadians));
        float Cosinus(std::cos(AngleInRadians));
        
        return Quaternion(_[0] * Cosinus - _[3] * Sinus, _[1] * Cosinus + _[2] * Sinus, _[2] * Cosinus - _[1] * Sinus, _[3] * Cosinus + _[0] * Sinus);
    }
    
    Quaternion & Rotate(const Quaternion & Quaternion);
    
    Quaternion & RotateX(float Radians)
    {
        return Rotate(Quaternion::CreateAsRotationX(Radians));
    }
    
    Quaternion & RotateY(float Radians)
    {
        return Rotate(Quaternion::CreateAsRotationY(Radians));
    }
    
    Quaternion & RotateZ(float Radians)
    {
        return Rotate(Quaternion::CreateAsRotationZ(Radians));
    }
    
    Quaternion operator*(const Quaternion & Other) const
    {
        return Quaternion(
            _[0] * Other._[0] - _[1] * Other._[1] - _[2] * Other._[2] - _[3] * Other._[3],
            _[1] * Other._[0] + _[0] * Other._[1] - _[3] * Other._[2] + _[2] * Other._[3],
            _[2] * Other._[0] + _[3] * Other._[1] + _[0] * Other._[2] - _[1] * Other._[3],
            _[3] * Other._[0] - _[2] * Other._[1] + _[1] * Other._[2] + _[0] * Other._[3]
        );
    }
    
    Quaternion & Set(float W, float X, float Y, float Z)
    {
        _[0] = W;
        _[1] = X;
        _[2] = Y;
        _[3] = Z;
        
        return *this;
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

/**
 * IMPLEMENTATION
 **/

#include <algebra/vector3f.h>

inline Quaternion Quaternion::CreateFromAxisAndAngle(const Vector3f & Axis, float AngleInRadians)
{
    return Quaternion().Rotation(Axis._[0], Axis._[1], Axis._[2], AngleInRadians);
}

inline Quaternion Quaternion::CreateIdentity(void)
{
    Quaternion Result;
    
    Result._[0] = 1.0f;
    Result._[1] = 0.0f;
    Result._[2] = 0.0f;
    Result._[3] = 0.0f;
    
    return Result;
}

inline Quaternion & Quaternion::Rotate(const Quaternion & Quaternion)
{
    auto W(_[0] * Quaternion._[0] - _[1] * Quaternion._[1] - _[2] * Quaternion._[2] - _[3] * Quaternion._[3]);
    auto X(_[1] * Quaternion._[0] + _[0] * Quaternion._[1] - _[3] * Quaternion._[2] + _[2] * Quaternion._[3]);
    auto Y(_[2] * Quaternion._[0] + _[3] * Quaternion._[1] + _[0] * Quaternion._[2] - _[1] * Quaternion._[3]);
    auto Z(_[3] * Quaternion._[0] - _[2] * Quaternion._[1] + _[1] * Quaternion._[2] + _[0] * Quaternion._[3]);
    
    _[0] = W;
    _[1] = X;
    _[2] = Y;
    _[3] = Z;
    
    return *this;
}

#endif
