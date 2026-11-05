/**
 * algebra
 * Copyright 2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
**/

#ifndef ALGEBRA__TESTING__COMMON_H
#define ALGEBRA__TESTING__COMMON_H

#include <array>
#include <cmath>
#include <numbers>

namespace Algebra::Testing
{
    template<class SizingType>
    auto GetUninitializedBytes() -> std::array<std::byte, sizeof(SizingType)>
    {
        auto Result = std::array<std::byte, sizeof(SizingType)>{};
        
        for(auto & Byte : Result)
        {
            Byte = static_cast<std::byte>(0xa5);
        }
        
        return Result;
    }

    inline constexpr auto PI = std::numbers::pi_v<float>;
    inline constexpr auto PI_2 = std::numbers::pi_v<float> / 2.0f;

    auto Equals(float One, float Two, float Delta = 0.0001f) -> bool
    {
        return std::abs(One - Two) < Delta;
    }

    auto NotEquals(float One, float Two, float Delta = 0.0001f) -> bool
    {
        return std::abs(One - Two) > Delta;
    }
}

#endif
