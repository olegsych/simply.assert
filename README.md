# simply::com

A small C++ library for working with COM

## building

[![Build status](https://ci.appveyor.com/api/projects/status/github/olegsych/simply.com?branch=master&retina=true)](https://ci.appveyor.com/project/olegsych/simply-com/branch/master)

From [Visual Studio 2015](https://www.visualstudio.com/downloads):
- Open `simply.com.sln`
- Select _Build Solution_ from the _Build_ menu
- To switch build between `x86` and `x64` platforms, select _Configuration Manager_ from the _Build_ menu and change the _Active Solution Configuration_

From [Developer Command Prompt for VS2015](https://msdn.microsoft.com/en-us/library/ms229859.aspx):
```
msbuild simply.com.sln /p:Platform=x86
msbuild simply.com.sln /p:Platform=x64
```

## testing

From Visual Studio 2015:
- Select _Run_ / _All Tests_ from the _Test_ menu
- To switch test execution between `x86` and `x64` platform, select _Test Settings_ from the _Test_ menu and change the _Default Processor Architecture_.

From Developer Command Prompt for VS2015:
```
vstest.console bin\debug\Win32\test.dll /Platform:x86
vstest.console bin\debug\x64\test.dll /Platform:x64 /inIsolation
```