#pragma once

#include <codecvt>
#include <locale>
#include <string>
#include <simply/assert/framework.h>

namespace simply { namespace assert 
{
    template<typename framework = simply::assert::framework::default>
    inline void fail(const std::string& message)
    {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring wmessage = converter.from_bytes(message);
        fail<framework>(wmessage);
    }
    
    template<typename framework = framework::default>
    inline void fail(const std::wstring& message)
    {
        framework::fail(message);
    }
}}