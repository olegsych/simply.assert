#include "stdafx.h"
#include <exception>
#include <CppUnitTest.h>
#include <simply/assert/exception.h>
#include <simply/utility.h>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace simply
{
    TEST_CLASS(exception_test)
    {
        wstring output;
        utility::temporary<function<void(const wstring&)>> fail_stub {
            assert::implementation::fail,
            [&](const wstring& message) { output = message; }
        };

    public:
        TEST_METHOD(throws_returns_copy_of_exception_thrown_by_given_function)
        {
            exception expected { "Test Message" };

            unique_ptr<exception> actual = assert::throws<exception>([&] { throw expected; });
            
            Assert::IsFalse(&expected == actual.get());
            Assert::AreEqual(expected.what(), actual->what());
        }

        TEST_METHOD(throws_returns_nullptr_and_fails_with_descriptive_message_when_exception_is_not_thrown)
        {
            unique_ptr<exception> result = assert::throws<exception>([]{});
            
            Assert::IsNull(result.get());
            Assert::AreNotEqual(string::npos, this->output.find(L"std::exception"));
        }

        TEST_METHOD(throws_returns_nullptr_and_fails_with_descriptive_message_when_different_exception_is_thrown)
        {
            unique_ptr<runtime_error> result = assert::throws<runtime_error>([] { throw logic_error { "Test Message" }; });

            Assert::IsNull(result.get());
            Assert::AreNotEqual(string::npos, this->output.find(L"std::runtime_error"));
            Assert::AreNotEqual(string::npos, this->output.find(L"std::logic_error"));
        }
    };
}