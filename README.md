# simply::assert

A small C++ library for asserting in unit tests. It was born out of frustration with the CppUnitTest framework 
used by the Visual Studio Native Unit Test projects and meant to replace its rudimentary [Assert](https://msdn.microsoft.com/en-us/library/hh694604.aspx) 
class with a TDD-focused, rich, modern assertion APIs comparable to [Xunit.Assert](https://github.com/xunit/xunit/tree/master/src/xunit.assert)'s.

## use

Add the [simply.assert](http://www.nuget.org/packages/simply.assert/) NuGet package to your Visual C++ Native Unit Test project 
using the [Package Manager Console](http://docs.nuget.org/consume/package-manager-console) or 
using the [Package Manager Dialog](http://docs.nuget.org/consume/Package-Manager-Dialog).

``` PowerShell
Install-Package simply.assert
```

Include the `simply/assert.h` header to your C++ file and use the `simply` namespace.

``` C++
#include <simply/assert.h>
using namespace simply;
```

Use assert functions.

``` C++
// fail (with overloads for std::string and std::wstring)
assert::fail("foo");

// bool
assert::is_true(true);
assert::is_false(false);

// equality
assert::is_equal(42, 42);
assert::is_not_equal(0, 42);

// exceptions
unique_ptr<exception> e = assert::throws<exception>([] { throw exception("foo"}; );

// null (with overloads for typed and void pointers)
assert::is_null(nullptr);
assert::is_not_null(reinterpret_cast<void*>(0x42));

// string (with overloads for string, wstring, char* and wchar_t*)
size_t position = assert::find("bar", "foo bar baz");
assert::is_equal("foo", "foo");
assert::is_not_equal("foo", "bar");

// type traits
assert::is_abstract<foo>();
assert::is_base_of<foo, bar>();
assert::is_concrete<foo>();
assert::is_copy_assignable<foo>();
assert::is_copy_constructible<foo>();
assert::is_destructible();
assert::is_same<foo, foo>();
```

## build

[![Build status](https://ci.appveyor.com/api/projects/status/github/olegsych/simply.assert?branch=master&retina=true)](https://ci.appveyor.com/project/olegsych/simply-assert/branch/master)

From [Visual Studio 2017](https://www.visualstudio.com/downloads):
- Open `simply.assert.sln`
- Select _Build Solution_ from the _Build_ menu
- To switch build between `x86` and `x64` platforms, select _Configuration Manager_ from the _Build_ menu and change the _Active Solution Configuration_

From [Developer Command Prompt for VS2017](https://docs.microsoft.com/en-us/dotnet/framework/tools/developer-command-prompt-for-vs):
```
msbuild simply.assert.sln /p:Platform=x86
msbuild simply.assert.sln /p:Platform=x64
```

## test

From Visual Studio 2015:
- Select _Run_ / _All Tests_ from the _Test_ menu
- To switch test execution between `x86` and `x64` platform, select _Test Settings_ from the _Test_ menu and change the _Default Processor Architecture_.

From Developer Command Prompt for VS2017:
```
vstest.console bin\debug\Win32\test.dll /Platform:x86
vstest.console bin\debug\x64\test.dll /Platform:x64 /inIsolation
```