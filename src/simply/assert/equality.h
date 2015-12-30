#pragma once

#include <sstream>
#include <simply/assert/fail.h>
#include <simply/assert/framework.h>

namespace simply { namespace assert 
{
    template<typename t, typename framework = simply::assert::framework::default>
    void is_equal(const t& expected, const t& actual)
    {
        if (!(expected == actual))
        {
            std::ostringstream message;
            message << "Expected: <" << expected << ">\n";
            message << "Actual: <" << actual << ">";
            fail<framework>(message.str());
        }
    }

    template<typename t, typename framework = simply::assert::framework::default>
    void is_not_equal(const t& expected, const t& actual)
    {
        if (expected == actual)
        {
            std::ostringstream message;
            message << "Not expected: <" << expected << ">\n";
            message << "Actual: <" << actual << ">";
            fail<framework>(message.str());
        }
    }
}}
