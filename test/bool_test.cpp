#include "stdafx.h"
#include <CppUnitTest.h>
#include <functional>
#include <simply/assert/bool.h>
#include <simply/utility.h>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace simply
{
    TEST_CLASS(bool_test)
    {
        wstring output;
        utility::temporary<function<void(const wstring&)>> fail_stub {
            assert::implementation::fail,
            [&](const wstring& message) { output = message; }
        };

    public:
        #pragma region is_true(bool)

        TEST_METHOD(is_true_fails_when_given_value_is_false)
        {
            assert::is_true(false);

            Assert::AreNotEqual(wstring::npos, this->output.find(L"true"));
            Assert::AreNotEqual(wstring::npos, this->output.find(L"false"));
        }

        TEST_METHOD(is_true_doesnt_fail_when_given_value_is_true)
        {
            assert::is_true(true);
            
            Assert::AreEqual<size_t>(0, this->output.length());
        }

        #pragma endregion

        #pragma region is_true(int)

        TEST_METHOD(is_true_fails_when_given_value_is_FALSE)
        {
            int actual = 0;

            assert::is_true(actual);

            Assert::AreNotEqual(wstring::npos, this->output.find(L"TRUE(!0)"));
            Assert::AreNotEqual(wstring::npos, this->output.find(L"FALSE(0)"));
        }

        TEST_METHOD(is_true_doesnt_fail_when_given_value_is_TRUE)
        {
            int actual = 1;

            assert::is_true(actual);

            Assert::AreEqual<size_t>(0, this->output.length());
        }

        #pragma endregion

        #pragma region is_false(bool)

        TEST_METHOD(is_false_fails_when_given_value_is_true)
        {
            assert::is_false(true);

            Assert::AreNotEqual(wstring::npos, this->output.find(L"false"));
            Assert::AreNotEqual(wstring::npos, this->output.find(L"true"));
        }

        TEST_METHOD(is_false_doesnt_fail_when_given_value_is_false)
        {
            assert::is_false(false);

            Assert::AreEqual<size_t>(0, this->output.length());
        }

        #pragma endregion

        #pragma region is_false(int)

        TEST_METHOD(is_false_fails_when_given_value_is_TRUE)
        {
            int actual = 42;

            assert::is_false(actual);

            Assert::AreNotEqual(wstring::npos, this->output.find(L"FALSE(0)"));
            Assert::AreNotEqual(wstring::npos, this->output.find(L"TRUE(42)"));
        }

        TEST_METHOD(is_false_doesnt_fail_when_given_value_is_FALSE)
        {
            int actual = 0;

            assert::is_false(actual);

            Assert::AreEqual<size_t>(0, this->output.length());
        }

        #pragma endregion
    };
}