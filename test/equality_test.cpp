#include "stdafx.h"
#include <CppUnitTest.h>
#include <simply/assert/equality.h>
#include <simply/utility.h>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace simply
{
    TEST_CLASS(equality_test)
    {
        wstring output;
        utility::temporary<function<void(const wstring&)>> fail_stub {
            assert::implementation::fail,
            [&](const wstring& message) { output = message; }
        };

    public:
        #pragma region is_equal

        TEST_METHOD(is_equal_fails_when_actual_value_is_not_equal_to_expected)
        {
            const int& expected = 42;
            const int& actual = 0;

            assert::is_equal(expected, actual);

            Assert::AreNotEqual(wstring::npos, this->output.find(to_wstring(expected)));
            Assert::AreNotEqual(wstring::npos, this->output.find(to_wstring(actual)));
        }

        TEST_METHOD(is_equal_doesnt_fail_when_actual_value_is_equal_to_expected)
        {
            const int& expected = 42;
            const int& actual = 42;

            assert::is_equal(expected, actual);

            Assert::AreEqual<size_t>(0, this->output.length());
        }

        #pragma endregion

        #pragma region is_not_equal

        TEST_METHOD(is_not_equal_fails_when_actual_value_is_equal_to_expected)
        {
            const int& expected = 42;
            const int& actual = 42;

            assert::is_not_equal(expected, actual);

            Assert::AreNotEqual(wstring::npos, this->output.find(to_wstring(expected)));
            Assert::AreNotEqual(wstring::npos, this->output.find(to_wstring(actual)));
        }

        TEST_METHOD(is_not_equal_doesnt_fail_when_actual_value_is_not_equal_to_expected)
        {
            const int& expected = 42;
            const int& actual = 0;

            assert::is_not_equal(expected, actual);

            Assert::AreEqual<size_t>(0, this->output.length());
        }

        #pragma endregion
    };
}
