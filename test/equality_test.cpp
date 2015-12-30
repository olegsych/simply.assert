#include <CppUnitTest.h>
#include <simply/assert/equality.h>
#include "stub.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace simply
{
    TEST_CLASS(equality_test)
    {
    public:
        equality_test()
        {
            stub::output = wstring();
        }

        #pragma region is_equal

        TEST_METHOD(is_equal_fails_when_actual_value_is_not_equal_to_expected)
        {
            const int& expected = 42;
            const int& actual = 0;

            assert::is_equal<int, stub>(expected, actual);

            Assert::AreNotEqual(wstring::npos, stub::output.find(to_wstring(expected)));
            Assert::AreNotEqual(wstring::npos, stub::output.find(to_wstring(actual)));
        }

        TEST_METHOD(is_equal_doesnt_fail_when_actual_value_is_equal_to_expected)
        {
            const int& expected = 42;
            const int& actual = 42;

            assert::is_equal<int, stub>(expected, actual);

            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_equal_infers_types_of_arguments_and_uses_default_framework)
        {
            assert::is_equal(42, 42);
        }

        #pragma endregion

        #pragma region is_not_equal

        TEST_METHOD(is_not_equal_fails_when_actual_value_is_equal_to_expected)
        {
            const int& expected = 42;
            const int& actual = 42;

            assert::is_not_equal<int, stub>(expected, actual);

            Assert::AreNotEqual(wstring::npos, stub::output.find(to_wstring(expected)));
            Assert::AreNotEqual(wstring::npos, stub::output.find(to_wstring(actual)));
        }

        TEST_METHOD(is_not_equal_doesnt_fail_when_actual_value_is_not_equal_to_expected)
        {
            const int& expected = 42;
            const int& actual = 0;

            assert::is_not_equal<int, stub>(expected, actual);

            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_not_equal_infers_types_of_arguments_and_uses_default_framework)
        {
            assert::is_not_equal(0, 42);
        }

        #pragma endregion
    };
}
