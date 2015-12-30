#include <CppUnitTest.h>
#include <simply/assert/implementation.h>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace simply { namespace assert { namespace implementation
{
    TEST_CLASS(type_name_test)
    {
    public:
        TEST_METHOD(type_name_for_non_reference_types_returns_const_string)
        {
            Assert::IsTrue(is_same<const string, decltype(type_name<int>())>());
        }

        TEST_METHOD(type_name_for_reference_types_returns_const_string)
        {
            Assert::IsTrue(is_same<const string, decltype(type_name<int&>())>());
        }

        TEST_METHOD(type_name_returns_name_of_given_type)
        {
            Assert::AreEqual(string { "int" }, type_name<int>());
        }

        TEST_METHOD(type_name_returns_name_of_given_const_type)
        {
            Assert::AreEqual(string { "const int" }, type_name<const int>());
        }

        TEST_METHOD(type_name_return_name_of_given_volatile_type)
        {
            Assert::AreEqual(string { "volatile int" }, type_name<volatile int>());
        }

        TEST_METHOD(type_name_returns_name_of_given_reference_type)
        {
            Assert::AreEqual(string { "int&" }, type_name<int&>());
        }

        TEST_METHOD(type_name_returns_name_of_given_const_reference_type)
        {
            Assert::AreEqual(string { "const int&" }, type_name<const int&>());
        }

        TEST_METHOD(type_name_returns_name_of_given_volatile_reference_type)
        {
            Assert::AreEqual(string { "volatile int&" }, type_name<volatile int&>());
        }
    };
}}}