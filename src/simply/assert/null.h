#pragma once

#include <sstream>
#include <simply/assert/fail.h>
#include <simply/assert/framework.h>
#include <simply/utility.h>
#include <type_traits>

namespace simply { namespace assert
{
    template<typename t, typename framework = simply::assert::framework::default>
    void is_not_null(const t* pointer)
    {
        if (pointer == nullptr)
        {
            std::ostringstream message;
            message << "Expected non-null pointer of type <" << utility::type_name<t*>() << ">";
            fail<framework>(message.str());
        }
    }

    template<typename framework = simply::assert::framework::default>
    void is_null(const void* pointer)
    {
        if (pointer != nullptr)
        {
            std::ostringstream message;
            message << "Expected nullptr of type <void *>\n";
            message << "Actual pointer value <0x" << pointer << ">";
            fail<framework>(message.str());
        }
    }

    template<typename t, typename framework = simply::assert::framework::default>
    void is_null(const t* pointer)
    {
        if (pointer != nullptr)
        {
            std::ostringstream message;
            message << "Expected nullptr of type <" << utility::type_name<t*>() << ">\n";
            message << "Actual pointer <0x" << pointer << ">";
            try
            {
                message << " to type <" << typeid(*pointer).name() << ">";
            }
            catch (...)
            {
                // Ignore potential access violation from dereferencing an invalid pointer
            }
            fail<framework>(message.str());
        }
    }
}}