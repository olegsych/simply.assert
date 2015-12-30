#include "stdafx.h"
#include <CppUnitTest.h>
#include <simply/assert/type_traits.h>
#include "stub.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace simply
{
    TEST_CLASS(type_traits_test)
    {
        class abstract_type
        {
        public: 
            virtual void method() = 0;
        };

        class concrete_type : public abstract_type 
        {
        public:
            void method() override {}
        };

        class non_copy_constructible_type
        {
        public:
            non_copy_constructible_type(non_copy_constructible_type&) = delete;
        };

        class non_copy_assignable_type
        {
        public:
            non_copy_assignable_type& operator=(non_copy_assignable_type&&) = delete;
        };

        class non_destructible_type
        {
        public:
            ~non_destructible_type() = delete;
        };

        class standalone_type 
        {
        };

    public:
        type_traits_test()
        {
            stub::output = wstring();
        }

        #pragma region is_abstract<actual_t>()

        TEST_METHOD(is_abstract_fails_when_type_is_concrete)
        {
            assert::is_abstract<concrete_type, stub>();

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"abstract"));
            Assert::AreNotEqual(wstring::npos, stub::output.find(L"concrete_type"));
        }

        TEST_METHOD(is_abstract_doesnt_fail_when_type_is_abstract)
        {
            assert::is_abstract<abstract_type, stub>();

            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_abstract_uses_default_framework)
        {
            assert::is_abstract<abstract_type>();
        }

        #pragma endregion

        #pragma region is_base_of<base_t, derived_t>()

        TEST_METHOD(is_base_of_fails_when_actual_type_is_not_derived_from_base)
        {
            assert::is_base_of<abstract_type, standalone_type, stub>();

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"abstract_type"));
            Assert::AreNotEqual(wstring::npos, stub::output.find(L"standalone_type"));
        }

        TEST_METHOD(is_base_of_doesnt_fail_when_actual_type_is_derived_from_base)
        {
            assert::is_base_of<abstract_type, concrete_type, stub>();

            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_base_of_uses_default_framework)
        {
            assert::is_base_of<abstract_type, concrete_type>();
        }

        #pragma endregion

        #pragma region is_concrete<actual_t>()

        TEST_METHOD(is_concrete_fails_when_type_is_abstract)
        {
            assert::is_concrete<abstract_type, stub>();

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"concrete"));
            Assert::AreNotEqual(wstring::npos, stub::output.find(L"abstract_type"));
        }

        TEST_METHOD(is_concrete_doesnt_fail_when_type_is_concrete)
        {
            assert::is_concrete<concrete_type, stub>();

            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_concrete_uses_default_framework)
        {
            assert::is_concrete<concrete_type>();
        }

        #pragma endregion

        #pragma region is_copy_assignable<actual_t>()

        TEST_METHOD(is_copy_assignable_fails_when_type_is_not_copy_assignable)
        {
            assert::is_copy_assignable<non_copy_assignable_type, stub>();

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"copy-assignable"));
            Assert::AreNotEqual(wstring::npos, stub::output.find(L"non_copy_assignable_type"));
        }

        TEST_METHOD(is_copy_assignable_doesnt_fail_when_type_is_copy_assignable)
        {
            assert::is_copy_assignable<int, stub>();

            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_copy_assignable_uses_default_framework)
        {
            assert::is_copy_assignable<int>();
        }

        #pragma endregion

        #pragma region is_copy_constructible<actual_t>()

        TEST_METHOD(is_copy_constructible_fails_when_type_is_not_copy_constructible)
        {
            assert::is_copy_constructible<non_copy_constructible_type, stub>();

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"copy-constructible"));
            Assert::AreNotEqual(wstring::npos, stub::output.find(L"non_copy_constructible_type"));
        }

        TEST_METHOD(is_copy_constructible_doesnt_fail_when_type_is_copy_constructible)
        {
            assert::is_copy_constructible<int, stub>();

            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_copy_constructible_uses_default_framework)
        {
            assert::is_copy_constructible<int>();
        }

        #pragma endregion

        #pragma region is_destructible<actual_t>()

        TEST_METHOD(is_destructible_fails_when_type_is_not_destructible)
        {
            assert::is_destructible<non_destructible_type, stub>();

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"destructible"));
            Assert::AreNotEqual(wstring::npos, stub::output.find(L"non_destructible_type"));
        }

        TEST_METHOD(is_destructible_doesnt_fail_when_type_is_destructible)
        {
            assert::is_copy_constructible<int, stub>();

            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_destructible_uses_default_framework)
        {
            assert::is_destructible<int>();
        }

        #pragma endregion

        #pragma region is_same<expected_t, actual_t>()
        
        TEST_METHOD(is_same_fails_when_types_are_different)
        {
            assert::is_same<int, double, stub>();

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"int"));
            Assert::AreNotEqual(wstring::npos, stub::output.find(L"double"));
        }

        TEST_METHOD(is_same_failure_message_includes_const_and_volatile_modifiers)
        {
            assert::is_same<volatile int, const int, stub>();

            Assert::AreNotEqual(wstring::npos, stub::output.find(L"volatile int"));
            Assert::AreNotEqual(wstring::npos, stub::output.find(L"const int"));
        }

        TEST_METHOD(is_same_doesnt_fail_when_types_are_same)
        {
            assert::is_same<int, int, stub>();

            Assert::AreEqual<size_t>(0, stub::output.length());
        }

        TEST_METHOD(is_same_uses_default_framework)
        {
            assert::is_same<int, int>();
        }

        #pragma endregion
    };
}