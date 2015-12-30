#pragma once

#include <string>
#include <CppUnitTest.h>

namespace simply { namespace assert { namespace framework 
{
    struct cpp_unit_test
    {
        static void fail(const std::wstring& message)
        {
            std::wstring separated_message { L"\n" + message };
            Microsoft::VisualStudio::CppUnitTestFramework::Assert::Fail(separated_message.c_str());
        }
    };

    using default = cpp_unit_test;
}}}