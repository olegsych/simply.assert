#pragma once

#include <sstream>
#include <simply/assert/fail.h>

namespace simply { namespace assert 
{
    template<typename t>
    void is_equal(const t& expected, const t& actual)
    {
        if (!(expected == actual))
        {
            std::ostringstream message;
            message << "Expected: <" << expected << ">\n";
            message << "Actual: <" << actual << ">";
            fail(message);
        }
    }

    template<typename t>
    void is_not_equal(const t& expected, const t& actual)
    {
        if (expected == actual)
        {
            std::ostringstream message;
            message << "Not expected: <" << expected << ">\n";
            message << "Actual: <" << actual << ">";
            fail(message);
        }
    }
}}
