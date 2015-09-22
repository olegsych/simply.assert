#pragma once

#include <functional>
#include <string>

namespace simply { namespace assert { namespace implementation 
{
    extern std::function<void(const std::wstring&)> fail;
}}}