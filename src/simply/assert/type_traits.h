#pragma once

#include <type_traits>
#include <simply/assert/fail.h>
#include <simply/assert/framework.h>
#include <simply/assert/implementation.h>

namespace simply { namespace assert
{
    template<typename actual_t, typename framework = simply::assert::framework::default>
    void is_abstract()
    {
        if (!std::is_abstract<actual_t>())
        {
            std::ostringstream message;
            message << "Expected abstract type\n";
            message << "Actual concrete type: <" << implementation::type_name<actual_t>() << ">";
            fail<framework>(message.str());
        }
    }

    template<typename base_t, typename actual_t, typename framework = simply::assert::framework::default>
    void is_base_of()
    {
        if (!std::is_base_of<base_t, actual_t>())
        {
            std::ostringstream message;
            message << "Expected type derived from <" << implementation::type_name<base_t>() << ">\n";
            message << "Actual type <" << implementation::type_name<actual_t>() << "> is not";
            fail<framework>(message.str());
        }
    }

    template<typename actual_t, typename framework = simply::assert::framework::default>
    void is_concrete()
    {
        if (std::is_abstract<actual_t>())
        {
            std::ostringstream message;
            message << "Expected concrete type\n";
            message << "Actual abstract type: <" << implementation::type_name<actual_t>() << ">";
            fail<framework>(message.str());
        }
    }

    template<typename from_t, typename to_t, typename framework = simply::assert::framework::default>
    void is_convertible(bool expected = true)
    {
        if (expected != std::is_convertible<from_t, to_t>())
        {
            std::ostringstream message;
            message << "Type <" << implementation::type_name<from_t>() << "> is ";
            message << (expected ? "not " : "");
            message << "convertible to type <" << implementation::type_name<to_t>() << ">";
            fail<framework>(message.str());
        }
    }

    template<typename actual_t, typename framework = simply::assert::framework::default>
    void is_copy_assignable()
    {
        if (!std::is_copy_assignable<actual_t>())
        {
            std::ostringstream message;
            message << "Expected copy-assignable type\n";
            message << "Actual type: <" << implementation::type_name<actual_t>() << "> is not";
            fail<framework>(message.str());
        }
    }

    template<typename actual_t, typename framework = simply::assert::framework::default>
    void is_copy_constructible()
    {
        if (!std::is_copy_constructible<actual_t>())
        {
            std::ostringstream message;
            message << "Expected copy-constructible type\n";
            message << "Actual type: <" << implementation::type_name<actual_t>() << "> is not";
            fail<framework>(message.str());
        }
    }

    template<typename actual_t, typename framework = simply::assert::framework::default>
    void is_destructible()
    {
        if (!std::is_destructible<actual_t>())
        {
            std::ostringstream message;
            message << "Expected destructible type\n";
            message << "Actual type: <" << implementation::type_name<actual_t>() << "> is not";
            fail<framework>(message.str());
        }
    }

    template<typename expected_t, typename actual_t, typename framework = simply::assert::framework::default>
    void is_same()
    {      
        if (!std::is_same<expected_t, actual_t>())
        {
            std::ostringstream message;
            message << "Expected type: <" << implementation::type_name<expected_t>() << ">\n";
            message << "Actual type: <" << implementation::type_name<actual_t>() << ">";
            fail<framework>(message.str());
        }
    }
}}