#include <CppUnitTest.h>
#include <simply/assert/bool.h>
#include "stub.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace simply
{
    TEST_CLASS(bool_test)
    {
    public:
        bool_test()
        {
            stub::output = wstring();
        }

        #pragma region is_true(bool)

        TEST_METHOD(is_true_fails_when_given_value_is_false)
        {
            assert::is_true<stub>(false);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"true"));
            Assert::AreNotEqual(wstring::npos, stub::output.find(L"false"));
        }

        TEST_METHOD(is_true_doesnt_fail_when_given_value_is_true)
        {
            assert::is_true<stub>(true);
            
            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_true_uses_default_framework)
        {
            assert::is_true(true);
        }

        #pragma endregion

        #pragma region is_true(int)

        TEST_METHOD(is_true_fails_when_given_value_is_FALSE)
        {
            int actual = 0;

            assert::is_true<stub>(actual);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"TRUE(!0)"));
            Assert::AreNotEqual(wstring::npos, stub::output.find(L"FALSE(0)"));
        }

        TEST_METHOD(is_true_doesnt_fail_when_given_value_is_TRUE)
        {
            int actual = 1;

            assert::is_true<stub>(actual);

            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_true_int_uses_default_framework)
        {
            assert::is_true(1);
        }

        #pragma endregion

        #pragma region is_false(bool)

        TEST_METHOD(is_false_fails_when_given_value_is_true)
        {
            assert::is_false<stub>(true);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"false"));
            Assert::AreNotEqual(wstring::npos, stub::output.find(L"true"));
        }

        TEST_METHOD(is_false_doesnt_fail_when_given_value_is_false)
        {
            assert::is_false<stub>(false);

            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_false_uses_default_framework)
        {
            assert::is_false(false);
        }

        #pragma endregion

        #pragma region is_false(int)

        TEST_METHOD(is_false_fails_when_given_value_is_TRUE)
        {
            int actual = 42;

            assert::is_false<stub>(actual);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"FALSE(0)"));
            Assert::AreNotEqual(wstring::npos, stub::output.find(L"TRUE(42)"));
        }

        TEST_METHOD(is_false_doesnt_fail_when_given_value_is_FALSE)
        {
            int actual = 0;

            assert::is_false<stub>(actual);

            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_false_int_uses_default_framework)
        {
            assert::is_false(0);
        }

        #pragma endregion
    };
}