#pragma once

#include <type_traits>
#include <simply/assert/fail.h>
#include <simply/utility/type_name.h>

namespace simply { namespace assert
{
    template<typename actual_t> void is_abstract()
    {
        if (!std::is_abstract<actual_t>())
        {
            std::ostringstream message;
            message << "Expected abstract type\n";
            message << "Actual concrete type: <" << utility::type_name<actual_t>() << ">";
            fail(message);
        }
    }

    template<typename base_t, typename actual_t> void is_base_of()
    {
        if (!std::is_base_of<base_t, actual_t>())
        {
            std::ostringstream message;
            message << "Expected type derived from <" << utility::type_name<base_t>() << ">\n";
            message << "Actual type <" << utility::type_name<actual_t>() << "> is not";
            fail(message);
        }
    }

    template<typename actual_t> void is_concrete()
    {
        if (std::is_abstract<actual_t>())
        {
            std::ostringstream message;
            message << "Expected concrete type\n";
            message << "Actual abstract type: <" << utility::type_name<actual_t>() << ">";
            fail(message);
        }
    }

    template<typename actual_t> void is_copy_assignable()
    {
        if (!std::is_copy_assignable<actual_t>())
        {
            std::ostringstream message;
            message << "Expected copy-assignable type\n";
            message << "Actual type: <" << utility::type_name<actual_t>() << "> is not";
            fail(message);
        }
    }

    template<typename actual_t> void is_copy_constructible()
    {
        if (!std::is_copy_constructible<actual_t>())
        {
            std::ostringstream message;
            message << "Expected copy-constructible type\n";
            message << "Actual type: <" << utility::type_name<actual_t>() << "> is not";
            fail(message);
        }
    }

    template<typename actual_t> void is_destructible()
    {
        if (!std::is_destructible<actual_t>())
        {
            std::ostringstream message;
            message << "Expected destructible type\n";
            message << "Actual type: <" << utility::type_name<actual_t>() << "> is not";
            fail(message);
        }
    }

    template<typename expected_t, typename actual_t> void is_same()
    {      
        if (!std::is_same<expected_t, actual_t>())
        {
            std::ostringstream message;
            message << "Expected type: <" << utility::type_name<expected_t>() << ">\n";
            message << "Actual type: <" << utility::type_name<actual_t>() << ">";
            fail(message);
        }
    }
}}