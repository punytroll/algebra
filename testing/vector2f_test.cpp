/**
 * Copyright 2022 Hagen Möbius
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

#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>

#include <algebra/vector2f.h>

template<class Type>
auto GetUnInitializedArray() -> std::array<std::uint8_t, sizeof(Type)>
{
    auto Result = std::array<std::uint8_t, sizeof(Type)>{};
    
    for(auto & Byte : Result)
    {
        Byte = 0xa5;
    }
    
    return Result;
}

inline constexpr auto PI_2 = std::numbers::pi_v<float> / 2.0f;

auto Equals(float One, float Two, float Delta = 0.0001f) -> bool
{
    return std::abs(One - Two) < Delta;
}

auto NotEquals(float One, float Two, float Delta = 0.0001f) -> bool
{
    return std::abs(One - Two) > Delta;
}

auto main([[maybe_unused]] int argc, [[maybe_unused]] char * argv[]) -> int
{
    // testing default constructor doesn't initialize the components
    {
        auto Data = GetUnInitializedArray<Vector2f>();
        auto Value = new (Data.data()) Vector2f{};
        
        assert((*Value)[0] != 0.0f);
        assert((*Value)[1] != 0.0f);
    }
    // testing (bool) constructor does initialize the components
    {
        auto Data = GetUnInitializedArray<Vector2f>();
        auto Value = new (Data.data()) Vector2f{true};
        
        assert((*Value)[0] == 0.0f);
        assert((*Value)[1] == 0.0f);
    }
    // testing (float, float) constructor
    {
        auto Data = GetUnInitializedArray<Vector2f>();
        auto Value = new (Data.data()) Vector2f{4.0f, 2.4f};
        
        assert((*Value)[0] == 4.0f);
        assert((*Value)[1] == 2.4f);
    }
    // testing copy constructor
    {
        auto OldValue = Vector2f{6.0f, 1.4f};
        auto Data = GetUnInitializedArray<Vector2f>();
        auto Value = new (Data.data()) Vector2f{OldValue};
        
        assert((*Value)[0] == 6.0f);
        assert((*Value)[1] == 1.4f);
    }
    // testing static CreateFromMagnitudeAndAngle constructor
    {
        auto Value = Vector2f::CreateFromMagnitudeAndAngle(4.0f, PI_2);
        
        assert(Equals(Value[0], 0.0f) == true);
        assert(Equals(Value[1], 4.0f) == true);
    }
    // testing Set() on an uninitialized value
    {
        auto Data = GetUnInitializedArray<Vector2f>();
        auto Value = new (Data.data()) Vector2f{};
        
        Value->Set(5.7f, -1.9f);
        assert((*Value)[0] == 5.7f);
        assert((*Value)[1] == -1.9f);
    }
    // testing Set() on an initialized value
    {
        auto Value = Vector2f{5.0f, 3.2f};
        
        Value.Set(-5.7f, 1.9f);
        assert(Value[0] == -5.7f);
        assert(Value[1] == 1.9f);
    }
    // testing Length()
    {
        auto Value = Vector2f{5.1f, -3.2f};
        
        assert(Equals(Value.Length(), 6.0207972f));
    }
    // testing Length() on zeroed vector
    {
        auto Value = Vector2f{true};
        
        assert(Value.Length() == 0.0f);
    }
    // testing SquaredLength()
    {
        auto Value = Vector2f{-5.1f, 3.2f};
        
        assert(Value.SquaredLength() == 36.25f);
    }
    // testing SquaredLength() on zeroed vector
    {
        auto Value = Vector2f{true};
        
        assert(Value.SquaredLength() == 0.0f);
    }
    // testing Normalize() return this
    {
        auto Value = Vector2f{2.0f, 1.0f};
        
        assert(&(Value.Normalize()) == &Value);
        
        auto & Result = Value.Normalize();
        
        assert(&Result == &Value);
    }
    // testing Normalize() changes this
    {
        auto Value = Vector2f{2.0f, 1.0f};
        
        Value.Normalize();
        assert(NotEquals(Value[0], 2.0f) == true);
        assert(NotEquals(Value[1], 1.0f) == true);
    }
    // testing Normalize() result
    {
        auto Value = Vector2f{2.0f, 1.0f};
        
        Value.Normalize();
        assert(Equals(Value[0], 0.894427191) == true);
        assert(Equals(Value[1], 0.4472135955) == true);
    }
    // testing Normalize().Length() is 1.0f
    {
        auto Value = Vector2f{-4.0f, 2.555f};
        
        Value.Normalize();
        assert(Equals(Value.Length(), 1.0f) == true);
    }
    // checking the return value of Normalized()
    {
        auto Value = Vector2f{2.0f, 1.0f};
        auto Result = Value.Normalized();
        
        assert(&Result != &Value);
    }
    // checking Normalized() doesn't changes this
    {
        auto Value = Vector2f{-2.32f, 0.02f};
        
        Value.Normalized();
        assert(Equals(Value[0], -2.32f) == true);
        assert(Equals(Value[1], 0.02f) == true);
    }
    // testing Normalized() result
    {
        auto Value = Vector2f{2.0f, 1.0f};
        auto Result = Value.Normalized();
        
        assert(Equals(Result[0], 0.894427191) == true);
        assert(Equals(Result[1], 0.4472135955) == true);
    }
    // testing Normalized().Length() is 1.0f
    {
        auto Value = Vector2f{-4.0f, 2.555f};
        auto Result = Value.Normalized();
        
        assert(Equals(Result.Length(), 1.0f) == true);
    }
    // testing Scale() returns this
    {
        auto Value = Vector2f{-7.1f, 0.04f};
        
        assert(&(Value.Scale(0.5)) == &Value);
        
        auto & Result = Value.Scale(0.5);
        
        assert(&Result == &Value);
    }
    // testing Scale() changes this
    {
        auto Value = Vector2f{-7.1f, 0.04f};
        
        Value.Scale(0.5);
        assert(NotEquals(Value[0], -7.1f) == true);
        assert(NotEquals(Value[1], 0.04f) == true);
    }
    // testing the result of Scale()
    {
        auto Value = Vector2f{-7.1f, 0.04f};
        
        Value.Scale(-0.5);
        assert(Equals(Value[0], 3.55f) == true);
        assert(Equals(Value[1], -0.02f) == true);
    }
    // testing Scaled() doesn't return this
    {
        auto Value = Vector2f{-7.1f, 0.04f};
        auto Result = Value.Scaled(0.5);
        
        assert(&Result != &Value);
    }
    // testing Scaled() doesn't change this
    {
        auto Value = Vector2f{-7.1f, 0.04f};
        
        Value.Scaled(0.5);
        assert(Equals(Value[0], -7.1f) == true);
        assert(Equals(Value[1], 0.04f) == true);
    }
    // testing the result of Scaled()
    {
        auto Value = Vector2f{-7.1f, 0.04f};
        auto Result = Value.Scaled(-0.5);
        
        assert(Equals(Result[0], 3.55f) == true);
        assert(Equals(Result[1], -0.02f) == true);
    }
    // testing binary operator Vector2f + Vector2f doesn't change LHS
    {
        auto LHS = Vector2f{9.4f, 3.2};
        auto RHS = Vector2f{7.0f, -5.55f};
        [[maybe_unused]] auto Result = (LHS + RHS);
        
        assert(LHS[0] == 9.4f);
        assert(LHS[1] == 3.2f);
    }
    // testing binary operator Vector2f + Vector2f doesn't change RHS
    {
        auto LHS = Vector2f{9.4f, 3.2};
        auto RHS = Vector2f{7.0f, -5.55f};
        [[maybe_unused]] auto Result = (LHS + RHS);
        
        assert(RHS[0] == 7.0f);
        assert(RHS[1] == -5.55f);
    }
    // testing the result of binary operator Vector2f + Vector2f
    {
        auto LHS = Vector2f{9.4f, 3.2};
        auto RHS = Vector2f{7.0f, -5.55f};
        auto Result = (LHS + RHS);
        
        assert(Equals(Result[0], 16.4f) == true);
        assert(Equals(Result[1], -2.35f) == true);
    }
    // testing the result of binary operator Vector2f + Vector2f is independent from LHS
    {
        auto LHS = Vector2f{9.4f, 3.2};
        auto RHS = Vector2f{7.0f, -5.55f};
        auto Result = (LHS + RHS);
        
        assert(&LHS != &Result);
        Result[0] = 0.0f;
        Result[1] = 0.0f;
        assert(LHS[0] == 9.4f);
        assert(LHS[1] == 3.2f);
    }
    // testing the result of binary operator Vector2f + Vector2f is independent from RHS
    {
        auto LHS = Vector2f{9.4f, 3.2};
        auto RHS = Vector2f{7.0f, -5.55f};
        auto Result = (LHS + RHS);
        
        assert(&RHS != &Result);
        Result[0] = 0.0f;
        Result[1] = 0.0f;
        assert(RHS[0] == 7.0f);
        assert(RHS[1] == -5.55f);
    }
    // testing binary operator Vector2f - Vector2f doesn't change LHS
    {
        auto LHS = Vector2f{9.4f, 3.2};
        auto RHS = Vector2f{7.0f, -5.55f};
        [[maybe_unused]] auto Result = (LHS - RHS);
        
        assert(LHS[0] == 9.4f);
        assert(LHS[1] == 3.2f);
    }
    // testing binary operator Vector2f - Vector2f doesn't change RHS
    {
        auto LHS = Vector2f{9.4f, 3.2};
        auto RHS = Vector2f{7.0f, -5.55f};
        [[maybe_unused]] auto Result = (LHS - RHS);
        
        assert(RHS[0] == 7.0f);
        assert(RHS[1] == -5.55f);
    }
    // testing the result of binary operator Vector2f - Vector2f
    {
        auto LHS = Vector2f{9.4f, 3.2};
        auto RHS = Vector2f{7.0f, -5.55f};
        auto Result = (LHS - RHS);
        
        assert(Equals(Result[0], 2.4f) == true);
        assert(Equals(Result[1], 8.75f) == true);
    }
    // testing the result of binary operator Vector2f - Vector2f is independent from LHS
    {
        auto LHS = Vector2f{9.4f, 3.2};
        auto RHS = Vector2f{7.0f, -5.55f};
        auto Result = (LHS - RHS);
        
        assert(&LHS != &Result);
        Result[0] = 0.0f;
        Result[1] = 0.0f;
        assert(LHS[0] == 9.4f);
        assert(LHS[1] == 3.2f);
    }
    // testing the result of binary operator Vector2f - Vector2f is independent from RHS
    {
        auto LHS = Vector2f{9.4f, 3.2};
        auto RHS = Vector2f{7.0f, -5.55f};
        auto Result = (LHS - RHS);
        
        assert(&RHS != &Result);
        Result[0] = 0.0f;
        Result[1] = 0.0f;
        assert(RHS[0] == 7.0f);
        assert(RHS[1] == -5.55f);
    }
    // testing binary operator Vector2f * float doesn't change LHS
    {
        auto LHS = Vector2f{-3.0f, -3.0f};
        [[maybe_unused]] auto Result = LHS * -3.333333333f;
        
        assert(LHS[0] == -3.0f);
        assert(LHS[1] == -3.0f);
    }
    // testing the result of binary operator Vector2f * float is independent from LHS
    {
        auto LHS = Vector2f{-3.0f, -3.0f};
        auto Result = LHS * -3.333333333f;
        
        assert(&LHS != &Result);
        Result[0] = 0.0f;
        Result[1] = 0.0f;
        assert(LHS[0] == -3.0f);
        assert(LHS[1] == -3.0f);
    }
    // testing the result of binary operator Vector2f * float
    {
        auto LHS = Vector2f{-3.0f, -3.0f};
        auto Result = LHS * -3.333333333f;
        
        assert(Equals(Result[0], 10.0f) == true);
        assert(Equals(Result[1], 10.0f) == true);
    }
    // testing binary operator Vector2f / float doesn't change LHS
    {
        auto LHS = Vector2f{3.0f, 3.0f};
        [[maybe_unused]] auto Result = LHS / 6.66666666666f;
        
        assert(LHS[0] == 3.0f);
        assert(LHS[1] == 3.0f);
    }
    // testing the result of binary operator Vector2f / float is independent from LHS
    {
        auto LHS = Vector2f{3.0f, 3.0f};
        auto Result = LHS / 6.66666666666f;
        
        assert(&LHS != &Result);
        Result[0] = 0.0f;
        Result[1] = 0.0f;
        assert(LHS[0] == 3.0f);
        assert(LHS[1] == 3.0f);
    }
    // testing the result of binary operator Vector2f / float
    {
        auto LHS = Vector2f{3.0f, 3.0f};
        auto Result = LHS / 6.66666666666f;
        
        assert(Equals(Result[0], 0.45f) == true);
        assert(Equals(Result[1], 0.45f) == true);
    }
    // testing binary operator Vector2f = Vector2f doesn't change RHS
    {
        auto LHS = Vector2f{-1.0f, -1.0f};
        auto RHS = Vector2f{444.4f, -0.333333333f};
        
        LHS = RHS;
        assert(RHS[0] == 444.4f);
        assert(RHS[1] == -0.333333333f);
    }
    // testing binary operator Vector2f = Vector2f changes LHS
    {
        auto LHS = Vector2f{-1.0f, -1.0f};
        auto RHS = Vector2f{444.4f, -0.333333333f};
        
        LHS = RHS;
        assert(LHS[0] == 444.4f);
        assert(LHS[1] == -0.333333333f);
    }
    // testing binary operator Vector2f = Vector2f returns reference to LHS
    {
        auto LHS = Vector2f{-1.0f, -1.0f};
        auto RHS = Vector2f{444.4f, -0.333333333f};
        auto & Result = (LHS = RHS);
        
        assert(&Result == &LHS);
    }
    // testing binary operator Vector2f += Vector2f doesn't change RHS
    {
        auto LHS = Vector2f{-100.0f, 100.0f};
        auto RHS = Vector2f{444.4f, -0.333333333f};
        
        LHS += RHS;
        assert(RHS[0] == 444.4f);
        assert(RHS[1] == -0.333333333f);
    }
    // testing binary operator Vector2f += Vector2f changes LHS
    {
        auto LHS = Vector2f{-100.0f, 100.0f};
        auto RHS = Vector2f{444.4f, -0.333333333f};
        
        LHS += RHS;
        assert(LHS[0] == 344.4f);
        assert(LHS[1] == 99.666666666f);
    }
    // testing binary operator Vector2f += Vector2f returns reference to LHS
    {
        auto LHS = Vector2f{-100.0f, 100.0f};
        auto RHS = Vector2f{444.4f, -0.333333333f};
        auto & Result = (LHS += RHS);
        
        assert(&Result == &LHS);
    }
    // testing binary operator Vector2f -= Vector2f doesn't change RHS
    {
        auto LHS = Vector2f{-100.0f, 100.0f};
        auto RHS = Vector2f{444.4f, -0.333333333f};
        
        LHS -= RHS;
        assert(RHS[0] == 444.4f);
        assert(RHS[1] == -0.333333333f);
    }
    // testing binary operator Vector2f -= Vector2f changes LHS
    {
        auto RHS = Vector2f{444.4f, -0.333333333f};
        auto LHS = Vector2f{-100.0f, 100.0f};
        
        LHS -= RHS;
        assert(LHS[0] == -544.4f);
        assert(LHS[1] == 100.333333333f);
    }
    // testing binary operator Vector2f -= Vector2f returns reference to LHS
    {
        auto LHS = Vector2f{-100.0f, 100.0f};
        auto RHS = Vector2f{444.4f, -0.333333333f};
        auto & Result = (LHS -= RHS);
        
        assert(&Result == &LHS);
    }
    // testing binary operator Vector2f *= float changes LHS
    {
        auto LHS = Vector2f{444.4f, -0.333333333f};
        
        LHS *= -100.0f;
        assert(Equals(LHS[0], -44440.0f) == true);
        assert(Equals(LHS[1], 33.3333333f) == true);
    }
    // testing binary operator Vector2f *= float returns reference to LHS
    {
        auto LHS = Vector2f{444.4f, -0.333333333f};
        auto & Result = (LHS *= 123.0f);
        
        assert(&Result == &LHS);
    }
    // testing binary operator Vector2f /= float changes LHS
    {
        auto LHS = Vector2f{444.4f, -0.333333333f};
        
        LHS /= -100.0f;
        assert(Equals(LHS[0], -4.444f) == true);
        assert(Equals(LHS[1], 0.00333333333f) == true);
    }
    // testing binary operator Vector2f /= float returns reference to LHS
    {
        auto LHS = Vector2f{444.4f, -0.333333333f};
        auto & Result = (LHS /= 123.0f);
        
        assert(&Result == &LHS);
    }
    // testing unary operator +Vector2f doesn't change this
    {
        auto Value = Vector2f{-12.12f, 0.321f};
        [[maybe_unused]] auto Result = +Value;
        
        assert(Value[0] == -12.12f);
        assert(Value[1] == 0.321f);
    }
    // testing unary operator +Vector2f creates an independent instance
    {
        auto Value = Vector2f{-12.12f, 0.321f};
        auto Result = +Value;
        
        assert(&Value != &Result);
        Result[0] = 0.0f;
        Result[1] = 0.0f;
        assert(Value[0] == -12.12f);
        assert(Value[1] == 0.321f);
    }
    // testing the result unary operator +Vector2f
    {
        auto Value = Vector2f{-12.12f, 0.321f};
        auto Result = +Value;
        
        assert(Result[0] == -12.12f);
        assert(Result[1] == 0.321f);
    }
    // testing unary operator -Vector2f doesn't change this
    {
        auto Value = Vector2f{-12.12f, 0.321f};
        [[maybe_unused]] auto Result = -Value;
        
        assert(Value[0] == -12.12f);
        assert(Value[1] == 0.321f);
    }
    // testing unary operator -Vector2f creates an independent instance
    {
        auto Value = Vector2f{-12.12f, 0.321f};
        auto Result = -Value;
        
        assert(&Value != &Result);
        Result[0] = 0.0f;
        Result[1] = 0.0f;
        assert(Value[0] == -12.12f);
        assert(Value[1] == 0.321f);
    }
    // testing the result of unary operator -Vector2f
    {
        auto Value = Vector2f{-12.12f, 0.321f};
        auto Result = -Value;
        
        assert(Result[0] == 12.12f);
        assert(Result[1] == -0.321f);
    }
    // testing Negate() returns Operand
    {
        auto Operand = Vector2f{-7.1f, 0.04f};
        auto & Result = Operand.Negate();
        
        assert(&Result == &Operand);
    }
    // testing Negate() changes Operand
    {
        auto Operand = Vector2f{-7.1f, 0.04f};
        
        Operand.Negate();
        assert(NotEquals(Operand[0], -7.1f) == true);
        assert(NotEquals(Operand[1], 0.04f) == true);
    }
    // testing the result of Negate()
    {
        auto Operand = Vector2f{-7.1f, 0.04f};
        
        Operand.Negate();
        assert(Equals(Operand[0], 7.1f) == true);
        assert(Equals(Operand[1], -0.04f) == true);
    }
    // testing Negated() doesn't return Operand
    {
        auto Operand = Vector2f{-7.1f, 0.04f};
        auto Result = Operand.Negated();
        
        assert(&Result != &Operand);
    }
    // testing the result of Negated() is independent from Operand
    {
        auto Operand = Vector2f{-7.1f, 0.04f};
        auto Result = Operand.Negated();
        
        Result[0] = 0.0f;
        Result[1] = 0.0f;
        assert(Operand[0] == -7.1f);
        assert(Operand[1] == 0.04f);
    }
    // testing Negated() doesn't change Operand
    {
        auto Operand = Vector2f{-7.1f, 0.04f};
        
        Operand.Negated();
        assert(Equals(Operand[0], -7.1f) == true);
        assert(Equals(Operand[1], 0.04f) == true);
    }
    // testing the result of Negated()
    {
        auto Operand = Vector2f{-7.1f, 0.04f};
        auto Result = Operand.Negated();
        
        assert(Equals(Result[0], 7.1f) == true);
        assert(Equals(Result[1], -0.04f) == true);
    }
    
    return 0;
}
