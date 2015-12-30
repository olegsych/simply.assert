#pragma once

#include <string>
#include <type_traits>

namespace simply { namespace assert { namespace implementation
{
    template<typename t> 
    typename std::enable_if<!std::is_reference<t>::value, const std::string>::type
    type_name()
    {
        std::string result { typeid(t).name() };
        
        if (std::is_const<t>())
        {
            result.insert(0, "const ");
        }

        if (std::is_volatile<t>())
        {
            result.insert(0, "volatile ");
        }

        return result;
    }

    template<typename t> 
    typename std::enable_if<std::is_reference<t>::value, const std::string>::type 
    type_name()
    {
        std::string result = type_name<std::remove_reference<t>::type>();
        result.append("&");
        return result;
    }
}}}
