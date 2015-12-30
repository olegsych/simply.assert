#include "stdafx.h"
#include <CppUnitTest.h>
#include <simply/assert/null.h>
#include "stub.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace simply
{
    TEST_CLASS(null_test)
    {
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
        null_test()
        {
            stub::output = wstring();
        }

        #pragma region is_not_null<t>()

        TEST_METHOD(is_not_null_doesnt_fail_when_given_void_pointer_is_not_null)
        {
            const void* pointer = reinterpret_cast<void*>(42);

            assert::is_not_null<void, stub>(pointer);

            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_not_null_fails_when_given_void_pointer_is_null)
        {
            const void* pointer = nullptr;

            assert::is_not_null<void, stub>(pointer);

            Assert::AreNotEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_not_null_includes_void_pointer_type_name_in_failure_message)
        {
            const void* pointer = nullptr;

            assert::is_not_null<void, stub>(pointer);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"void *"));
        }

        TEST_METHOD(is_not_null_includes_custom_pointer_type_name_in_failure_message)
        {
            const custom* pointer = nullptr;

            assert::is_not_null<custom, stub>(pointer);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"custom *"));
        }

        TEST_METHOD(is_not_null_infers_pointer_type_and_uses_default_framework)
        {
            const custom instance;
            assert::is_not_null(&instance);

            const void* pointer = reinterpret_cast<const void*>(0x42);
            assert::is_not_null(pointer);
        }

        #pragma endregion

        #pragma region assert::is_null(void*)

        TEST_METHOD(is_null_doesnt_fail_when_given_void_pointer_is_null)
        {
            const void* actual = nullptr;

            assert::is_null<stub>(actual);
            
            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_null_fails_when_given_void_pointer_is_not_null)
        {
            const void* actual = reinterpret_cast<void*>(0x01);

            assert::is_null<stub>(actual);
            
            Assert::AreNotEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_null_includes_void_pointer_value_in_failure_message)
        {
            const void* pointer = reinterpret_cast<void*>(0x42);

            assert::is_null<stub>(pointer);
            
            wostringstream expected;
            expected << pointer;
            Assert::AreNotEqual(wstring::npos, stub::output.find(expected.str()));
        }

        TEST_METHOD(is_null_includes_void_pointer_type_name_in_failure_message)
        {
            const void* pointer = reinterpret_cast<void*>(0x42);

            assert::is_null<stub>(pointer);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"void *"));
        }

        TEST_METHOD(is_null_uses_default_framework)
        {
            const void* pointer { nullptr };
            assert::is_null(pointer);
        }

        #pragma endregion

        #pragma region assert::is_null<t>(const t* pointer)

        TEST_METHOD(is_null_doesnt_fail_when_given_custom_pointer_is_null)
        {
            const custom* actual = nullptr;

            assert::is_null<custom, stub>(actual);
            
            Assert::AreEqual<unsigned long long>(0, stub::output.length());
        }

        TEST_METHOD(is_null_includes_custom_pointer_value_in_failure_message)
        {
            const custom* pointer = reinterpret_cast<custom*>(0x42);

            assert::is_null<custom, stub>(pointer);

            wostringstream expected;
            expected << pointer;
            Assert::AreNotEqual(wstring::npos, stub::output.find(expected.str()));
        }

        TEST_METHOD(is_null_includes_custom_class_name_in_failure_message)
        {
            const custom* pointer = reinterpret_cast<custom*>(0x42);

            assert::is_null<custom, stub>(pointer);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"custom *"));
        }

        TEST_METHOD(is_null_includes_derived_class_name_in_failure_message)
        {
            derived instance;
            const custom* pointer { &instance };

            assert::is_null<custom, stub>(pointer);

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"derived"));
        }

        TEST_METHOD(is_null_infers_pointer_type_and_uses_default_framework)
        {
            const custom* pointer { nullptr };
            assert::is_null(pointer);
        }

        #pragma endregion
    };
}