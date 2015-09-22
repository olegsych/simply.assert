#include <CppUnitTest.h>
#include <simply/assert/implementation.h>

namespace // unnamed, to prevent direct usage
{
    void fail_to_CppUnitTest(const std::wstring& message)
    {
        std::wstring separated_message { L"\n" + message };
        Microsoft::VisualStudio::CppUnitTestFramework::Assert::Fail(separated_message.c_str());
    }
}

std::function<void(const std::wstring&)> simply::assert::implementation::fail = &fail_to_CppUnitTest;