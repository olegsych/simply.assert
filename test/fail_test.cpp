#include "stdafx.h"
#include <CppUnitTest.h>
#include <simply/assert/fail.h>
#include <simply/utility.h>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace simply
{		
	TEST_CLASS(fail_test)
	{
        wstring output;
        utility::temporary<function<void(const wstring&)>> fail_stub { 
            assert::implementation::fail, 
            [&](const wstring& message) { output = message; } 
        };

	public:	
		TEST_METHOD(fail_writes_given_string_to_output)
		{
            assert::fail("Test Message");

            Assert::AreEqual(L"Test Message", this->output.c_str());
		}

        TEST_METHOD(fail_writes_given_wstring_to_output)
        {
            assert::fail(L"Test Message");

            Assert::AreEqual(L"Test Message", this->output.c_str());
        }

        TEST_METHOD(fail_writes_given_ostringstream_to_output)
        {
            ostringstream message;
            message << "Test Message";

            assert::fail(message);
            
            Assert::AreEqual(L"Test Message", this->output.c_str());
        }

        TEST_METHOD(fail_writes_given_owstringstream_to_output)
        {
            wostringstream message;
            message << L"Test Message";
            
            assert::fail(message);
            
            Assert::AreEqual(L"Test Message", this->output.c_str());
        }
	};
}