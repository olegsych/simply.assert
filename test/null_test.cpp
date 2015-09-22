#include "stdafx.h"
#include <CppUnitTest.h>
#include <functional>
#include <simply/assert/null.h>
#include <simply/assert/implementation.h>
#include <simply/utility.h>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace simply
{
    TEST_CLASS(null_test)
    {
        wstring output;
        utility::temporary<function<void(const wstring&)>> fail_stub {
            assert::implementation::fail,
            [&](const wstring& message) { output = message; }
        };

        class custom
        {
        public:
            virtual ~custom() {}
        };

        class derived : public custom
        {
        public:
            virtual ~derived() {}
        };

    public:
        #pragma region is_not_null(void*)

        TEST_METHOD(is_not_null_doesnt_fail_when_given_void_pointer_is_not_null)
        {
            const void* pointer = reinterpret_cast<void*>(42);

            assert::is_not_null(pointer);

            Assert::AreEqual<size_t>(0, this->output.length());
        }

        TEST_METHOD(is_not_null_fails_when_given_void_pointer_is_null)
        {
            const void* pointer = nullptr;

            assert::is_not_null(pointer);

            Assert::AreNotEqual<size_t>(0, this->output.length());
        }

        TEST_METHOD(is_not_null_includes_void_pointer_type_name_in_failure_message)
        {
            const void* pointer = nullptr;

            assert::is_not_null(pointer);

            Assert::AreNotEqual(wstring::npos, this->output.find(L"void *"));
        }

        TEST_METHOD(is_not_null_includes_custom_pointer_type_name_in_failure_message)
        {
            const custom* pointer = nullptr;

            assert::is_not_null(pointer);

            Assert::AreNotEqual(wstring::npos, this->output.find(L"custom *"));
        }

        #pragma endregion

        #pragma region assert::is_null(void*)

        TEST_METHOD(is_null_doesnt_fail_when_given_void_pointer_is_null)
        {
            const void* actual = nullptr;

            assert::is_null(actual);
            
            Assert::AreEqual<size_t>(0, this->output.length());
        }

        TEST_METHOD(is_null_fails_when_given_void_pointer_is_not_null)
        {
            const void* actual = reinterpret_cast<void*>(0x01);

            assert::is_null(actual);
            
            Assert::AreNotEqual<size_t>(0, this->output.length());
        }

        TEST_METHOD(is_null_includes_void_pointer_value_in_failure_message)
        {
            const void* pointer = reinterpret_cast<void*>(0x42);

            assert::is_null(pointer);
            
            wostringstream expected;
            expected << pointer;
            Assert::AreNotEqual(wstring::npos, this->output.find(expected.str()));
        }

        TEST_METHOD(is_null_includes_void_pointer_type_name_in_failure_message)
        {
            const void* pointer = reinterpret_cast<void*>(0x42);

            assert::is_null(pointer);

            Assert::AreNotEqual(wstring::npos, this->output.find(L"void *"));
        }

        #pragma endregion

        #pragma region assert::is_null<t>(const t* pointer)

        TEST_METHOD(is_null_doesnt_fail_when_given_custom_pointer_is_null)
        {
            const custom* actual = nullptr;

            assert::is_null(actual);
            
            Assert::AreEqual<unsigned long long>(0, this->output.length());
        }

        TEST_METHOD(is_null_includes_custom_pointer_value_in_failure_message)
        {
            const custom* pointer = reinterpret_cast<custom*>(0x42);

            assert::is_null(pointer);

            wostringstream expected;
            expected << pointer;
            Assert::AreNotEqual(wstring::npos, this->output.find(expected.str()));
        }

        TEST_METHOD(is_null_includes_custom_class_name_in_failure_message)
        {
            const custom* pointer = reinterpret_cast<custom*>(0x42);

            assert::is_null(pointer);

            Assert::AreNotEqual(wstring::npos, this->output.find(L"custom *"));
        }

        TEST_METHOD(is_null_includes_derived_class_name_in_failure_message)
        {
            derived instance;
            const custom* pointer { &instance };

            assert::is_null(pointer);

            Assert::AreNotEqual(wstring::npos, this->output.find(L"derived"));
        }

        #pragma endregion
    };
}