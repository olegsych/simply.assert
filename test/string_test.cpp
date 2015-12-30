#include <CppUnitTest.h>
#include <simply/assert/string.h>
#include "stub.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace simply 
{
    TEST_CLASS(string_test)
    {
    public:
        string_test()
        {
            stub::output = wstring();
        }

        #pragma region find

        TEST_METHOD(find_fails_when_expected_string_is_not_found_in_actual_string)
        {
            const wstring& sub_string { L"expected" };
            const wstring& actual_string { L"actual" };

            size_t pos = assert::find<wchar_t, stub>(sub_string, actual_string);

            Assert::AreEqual(string::npos, pos);
            Assert::AreNotEqual(string::npos, stub::output.find(L"\"" + sub_string + L"\""));
            Assert::AreNotEqual(string::npos, stub::output.find(L"\"" + actual_string + L"\""));
        }

        TEST_METHOD(find_fails_when_expected_cstyle_string_is_not_found_in_actual_string)
        {
            const wchar_t* sub_string { L"expected" };
            const wstring& actual_string { L"actual" };

            size_t pos = assert::find<wchar_t, stub>(sub_string, actual_string);

            Assert::AreEqual(string::npos, pos);
            Assert::AreNotEqual(string::npos, stub::output.find(L"\"" + wstring { sub_string } + L"\""));
            Assert::AreNotEqual(string::npos, stub::output.find(L"\"" + actual_string + L"\""));
        }

        TEST_METHOD(find_fails_when_expected_string_is_not_found_in_actual_cstyle_string)
        {
            const wstring& sub_string { L"expected" };
            const wchar_t* actual_string { L"actual" };

            size_t pos = assert::find<wchar_t, stub>(sub_string, actual_string);

            Assert::AreEqual(string::npos, pos);
            Assert::AreNotEqual(string::npos, stub::output.find(L"\"" + sub_string + L"\""));
            Assert::AreNotEqual(string::npos, stub::output.find(L"\"" + wstring { actual_string } + L"\""));
        }

        TEST_METHOD(find_fails_when_expected_cstyle_string_is_not_found_in_actual_cstyle_string)
        {
            const wchar_t* sub_string { L"expected" };
            const wchar_t* actual_string { L"actual" };

            size_t pos = assert::find<wchar_t, stub>(sub_string, actual_string);

            Assert::AreEqual(string::npos, pos);
            Assert::AreNotEqual(string::npos, stub::output.find(L"\"" + wstring { sub_string } + L"\""));
            Assert::AreNotEqual(string::npos, stub::output.find(L"\"" + wstring { actual_string } + L"\""));
        }

        TEST_METHOD(find_returns_position_of_expected_string_found_in_actual_string)
        {
            const wstring& sub_string { L"expected" };
            const wstring& actual_string { L"actual with expected" };

            size_t pos = assert::find<wchar_t, stub>(sub_string, actual_string);

            Assert::AreEqual(actual_string.find(sub_string), pos);
            Assert::IsTrue(0ULL == stub::output.length());
        }

        TEST_METHOD(find_infers_char_type_and_uses_default_framework)
        {
            const std::wstring& string { L"test string" };
            assert::find(string, string);
            assert::find(string.c_str(), string);
            assert::find(string, string.c_str());
            assert::find(string.c_str(), string.c_str());
        }

        #pragma endregion

        #pragma region is_equal

        TEST_METHOD(is_equal_fails_when_actual_string_is_different_than_expected_string)
        {
            const wstring& expected { L"expected string" };
            const wstring& actual { L"actual string" };

            assert::is_equal<wchar_t, stub>(expected, actual);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"\"" + expected + L"\""));
            Assert::AreNotEqual(wstring::npos, stub::output.find(L"\"" + actual + L"\""));
        }

        TEST_METHOD(is_equal_fails_when_actual_string_is_different_than_expected_cstyle_string)
        {
            const wchar_t* expected { L"expected string" };
            const wstring& actual { L"actual string" };

            assert::is_equal<wchar_t, stub>(expected, actual);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"\"" + wstring { expected } +L"\""));
            Assert::AreNotEqual(wstring::npos, stub::output.find(L"\"" + actual + L"\""));
        }

        TEST_METHOD(is_equal_fails_when_actual_cstyle_string_is_different_than_expected_string)
        {
            const wstring& expected { L"expected string" };
            const wchar_t* actual { L"actual string" };

            assert::is_equal<wchar_t, stub>(expected, actual);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"\"" + expected + L"\""));
            Assert::AreNotEqual(wstring::npos, stub::output.find(L"\"" + wstring { actual } + L"\""));
        }

        TEST_METHOD(is_equal_fails_when_actual_cstyle_string_is_different_than_expected_cstyle_string)
        {
            const wchar_t* expected { L"expected string" };
            const wchar_t* actual { L"actual string" };

            assert::is_equal<wchar_t, stub>(expected, actual);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"\"" + wstring { expected } + L"\""));
            Assert::AreNotEqual(wstring::npos, stub::output.find(L"\"" + wstring { actual } +L"\""));
        }

        TEST_METHOD(is_equal_doesnt_fail_when_actual_string_is_equal_to_expected)
        {
            const wstring& expected { L"expected string" };
            const wstring& actual { L"expected string" };

            assert::is_equal<wchar_t, stub>(expected, actual);

            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_equal_infers_char_type_and_uses_default_framework)
        {
            const wstring& string { L"test string" };
            assert::is_equal(string, string);
            assert::is_equal(string.c_str(), string);
            assert::is_equal(string, string.c_str());
            assert::is_equal(string.c_str(), string.c_str());
        }

        #pragma endregion

        #pragma region is_not_equal

        TEST_METHOD(is_not_equal_fails_when_actual_string_is_equal_to_expected_string)
        {
            const wstring& not_expected { L"not expected string" };
            const wstring& actual { L"not expected string" };

            assert::is_not_equal<wchar_t, stub>(not_expected, actual);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"\"" + not_expected + L"\""));
        }

        TEST_METHOD(is_not_equal_fails_when_actual_string_is_equal_to_expected_cstyle_string)
        {
            const wchar_t* not_expected { L"not expected string" };
            const wstring& actual { L"not expected string" };

            assert::is_not_equal<wchar_t, stub>(not_expected, actual);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"\"" + wstring { not_expected } + L"\""));
        }

        TEST_METHOD(is_not_equal_fails_when_actual_cstyle_string_is_equal_to_expected_string)
        {
            const wstring& not_expected { L"not expected string" };
            const wchar_t* actual { L"not expected string" };

            assert::is_not_equal<wchar_t, stub>(not_expected, actual);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"\"" + not_expected + L"\""));
        }

        TEST_METHOD(is_not_equal_fails_when_actual_cstyle_string_is_equal_to_expected_cstyle_string)
        {
            const wchar_t* not_expected { L"not expected string" };
            const wchar_t* actual { L"not expected string" };

            assert::is_not_equal<wchar_t, stub>(not_expected, actual);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"\"" + wstring { not_expected } + L"\""));
        }

        TEST_METHOD(is_not_equal_doesnt_fail_when_actual_string_is_equal_to_expected)
        {
            const wstring& not_expected { L"not expected string" };
            const wstring& actual { L"actual string" };

            assert::is_not_equal<wchar_t, stub>(not_expected, actual);

            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_not_equal_infers_char_type_and_uses_default_framework)
        {
            const wstring& unexpected { L"not expected string" };
            const wstring& actual { L"actual string" };

            assert::is_not_equal(unexpected, actual);
            assert::is_not_equal(unexpected.c_str(), actual);
            assert::is_not_equal(unexpected, actual.c_str());
            assert::is_not_equal(unexpected.c_str(), actual.c_str());
        }

        #pragma endregion
    };
}