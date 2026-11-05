/**
 * algebra
 * Copyright 2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
**/

#include <cassert>

#include <algebra/axis_angle.h>

#include "common.h"

auto main([[maybe_unused]] int argc, [[maybe_unused]] char * argv[]) -> int
{
    // testing default constructor doesn't initialize the components
    {
        auto Data = Algebra::Testing::GetUninitializedBytes<Algebra::AxisAngle>();
        auto Value = new (Data.data()) Algebra::AxisAngle{};
        
        assert((*Value)[0] != 0.0f);
        assert((*Value)[1] != 0.0f);
        assert((*Value)[2] != 0.0f);
        assert((*Value)[3] != 0.0f);
    }
    // testing static CreateFromComponents constructor
    {
        auto Value = Algebra::AxisAngle::CreateFromComponents(1.0f, 0.0f, 0.0f, Algebra::Testing::PI_2);
        
        assert(Value[0] == 1.0f);
        assert(Value[1] == 0.0f);
        assert(Value[2] == 0.0f);
        assert(Value[3] == Algebra::Testing::PI_2);
    }
    // testing static CreateFromAxisAndAngle constructor
    {
        auto Axis = Vector3f::CreateFromComponents(0.0f, 2.0f, 1.0f);
        auto Value = Algebra::AxisAngle::CreateFromAxisAndAngle(Axis, Algebra::Testing::PI);
        
        assert(Value[0] == 0.0f);
        assert(Value[1] == 2.0f);
        assert(Value[2] == 1.0f);
        assert(Value[3] == Algebra::Testing::PI);
    }
    // testing static CreateNormalisedFromAxisAndAngle constructor
    {
        auto Axis = Vector3f::CreateFromComponents(1.0f, 2.0f, 3.0f);
        auto Value = Algebra::AxisAngle::CreateNormalisedFromAxisAndAngle(Axis, Algebra::Testing::PI);
        
        assert(Algebra::Testing::Equals(Value[0], 0.267261241912) == true);
        assert(Algebra::Testing::Equals(Value[1], 0.534522483825) == true);
        assert(Algebra::Testing::Equals(Value[2], 0.801783725737) == true);
        assert(Value[3] == Algebra::Testing::PI);
    }
    // testing Set(float, float, float, float) initializes the components
    {
        auto Data = Algebra::Testing::GetUninitializedBytes<Algebra::AxisAngle>();
        auto Value = new (Data.data()) Algebra::AxisAngle{};
        
        Value->Set(2.0f, 3.0f, 4.0f, -Algebra::Testing::PI_2);
        assert((*Value)[0] == 2.0f);
        assert((*Value)[1] == 3.0f);
        assert((*Value)[2] == 4.0f);
        assert((*Value)[3] == -Algebra::Testing::PI_2);
    }
    
    return 0;
}
