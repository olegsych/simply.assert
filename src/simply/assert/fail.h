#pragma once

#include <codecvt>
#include <locale>
#include <string>
#include <simply/assert/implementation.h>

namespace simply { namespace assert 
{
    inline void fail(const std::string& message)
    {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring wmessage = converter.from_bytes(message);
        implementation::fail(wmessage);
    }
    
    inline void fail(const std::wstring& message)
    {
        implementation::fail(message);
    }

    template<class char_t> 
    inline void fail(const std::basic_ostringstream<char_t>& message)
    {
        fail(message.str());
    }
}}