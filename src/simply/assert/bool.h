#pragma once

#include <string>
#include <simply/assert/fail.h>

namespace simply { namespace assert
{
    /// <summary>Verifies that the <paramref name="actual"/> value is <c>true</c>.</summary>
    inline void is_true(bool actual)
    {
        if (!actual)
        {
            fail("Expected: true\nActual: false");
        }
    }

    /// <summary>Verifies that the <paramref name="actual"/> value is <c>TRUE</c>.</summary>
    /// <remarks>
    /// This function overloads <see cref="is_true(bool"/> to enable testing C-style <c>BOOL</c> values without 
    /// converting them to C++ <c>bool</c>, which triggers performance warning C4800 in Visual C++.
    /// </remarks>
    inline void is_true(int actual)
    {
        if (!actual)
        {
           fail("Expected: TRUE(!0)\nActual: FALSE(0)");
        }
    }

    /// <summary>Verifies that the <paramref name="actual"/> value is <c>false</c>.</summary>
    inline void is_false(bool actual)
    {
        if (actual)
        {
            fail("Expected: false\nActual: true");
        }
    }

    /// <summary>Verifies that the <paramref name="actual"/> value is <c>FALSE</c>.</summary>
    /// <remarks>
    /// This function overloads <see cref="is_false(bool"/> to enable testing C-style <c>BOOL</c> values without 
    /// converting them to C++ <c>bool</c>, which triggers performance warning C4800 in Visual C++.
    /// </remarks>
    inline void is_false(int actual)
    {
        if (actual)
        {
            fail("Expected: FALSE(0)\nActual: TRUE(" + std::to_string(actual) + ")");
        }
    }
}}