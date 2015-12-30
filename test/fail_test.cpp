#include "stdafx.h"
#include <CppUnitTest.h>
#include <simply/assert/fail.h>
#include "stub.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace simply
{		
    TEST_CLASS(fail_test)
	{
	public:	
        fail_test()
        {
            stub::output = wstring();
        }

		TEST_METHOD(fail_writes_given_string_to_output)
		{
            assert::fail<stub>("Test Message");

            Assert::AreEqual(L"Test Message", stub::output.c_str());
		}

        TEST_METHOD(fail_writes_given_wstring_to_output)
        {
            assert::fail<stub>(L"Test Message");

            Assert::AreEqual(L"Test Message", stub::output.c_str());
        }

        // Compile-time test
        void fail_can_be_called_with_default_framework()
        {
            assert::fail("Test Message");
            assert::fail(L"Test Messate");
        }
	};
}