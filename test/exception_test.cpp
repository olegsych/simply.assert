#include "stdafx.h"
#include <CppUnitTest.h>
#include <exception>
#include <functional>
#include <simply/assert/exception.h>
#include "stub.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace simply
{
    TEST_CLASS(exception_test)
    {
    public:
        exception_test()
        {
            stub::output = wstring();
        }

        TEST_METHOD(throws_returns_copy_of_exception_thrown_by_given_function)
        {
            exception expected { "Test Message" };

            unique_ptr<exception> actual = assert::throws<exception, function<void()>, stub>([&] { throw expected; });
            
            Assert::IsFalse(&expected == actual.get());
            Assert::AreEqual(expected.what(), actual->what());
            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(throws_returns_nullptr_and_fails_with_descriptive_message_when_exception_is_not_thrown)
        {
            unique_ptr<exception> result = assert::throws<exception, function<void()>, stub>([]{});
            
            Assert::IsNull(result.get());
            Assert::AreNotEqual(string::npos, stub::output.find(L"std::exception"));
        }

        TEST_METHOD(throws_returns_nullptr_and_fails_with_descriptive_message_when_different_exception_is_thrown)
        {
            unique_ptr<runtime_error> result = assert::throws<runtime_error, function<void()>, stub>([] { throw logic_error { "Test Message" }; });

            Assert::IsNull(result.get());
            Assert::AreNotEqual(string::npos, stub::output.find(L"std::runtime_error"));
            Assert::AreNotEqual(string::npos, stub::output.find(L"std::logic_error"));
        }

        TEST_METHOD(throws_infers_function_type_and_uses_default_framework)
        {
            assert::throws<exception>([] { throw exception(); });
        }
    };
}