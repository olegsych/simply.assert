#pragma once

#include <string>
#include <sstream>
#include <simply/assert/fail.h>
#include <simply/assert/framework.h>

namespace simply { namespace assert
{
    #pragma region find

    template <typename char_t, typename framework = simply::assert::framework::default>
    size_t find(const std::basic_string<char_t>& expected, const std::basic_string<char_t>& actual)
    {
        size_t position = actual.find(expected);
        if (position == std::basic_string<char_t>::npos)
        {
            std::basic_ostringstream<char_t> message;
            message << "Not found: \"" << expected << "\"\n";
            message << "In: \"" << actual << "\"";
            fail<framework>(message.str());
        }

        return position;
    }

    template <typename char_t, typename framework = simply::assert::framework::default>
    size_t find(const char_t* expected, const std::basic_string<char_t>& actual)
    {
        return find<char_t, framework>(std::basic_string<char_t> { expected }, actual);
    }

    template <typename char_t, typename framework = simply::assert::framework::default>
    size_t find(const std::basic_string<char_t>& expected, const char_t* actual)
    {
        return find<char_t, framework>(expected, std::basic_string<char_t> { actual });
    }

    template <typename char_t, typename framework = simply::assert::framework::default>
    size_t find(const char_t* expected, const char_t* actual)
    {
        return find<char_t, framework>(std::basic_string<char_t> { expected }, std::basic_string<char_t> { actual });
    }

    #pragma endregion

    #pragma region is_equal

    template <typename char_t, typename framework = simply::assert::framework::default>
    void is_equal(const std::basic_string<char_t>& expected, const std::basic_string<char_t>& actual)
    {
        if (!(expected == actual))
        {
            std::basic_ostringstream<char_t> message;
            message << "Expected: \"" << expected << "\"\n";
            message << "Actual: \"" << actual << "\"";
            fail<framework>(message.str());
        }
    }

    template <typename char_t, typename framework = simply::assert::framework::default>
    void is_equal(const char_t* expected, const std::basic_string<char_t>& actual)
    {
        is_equal<char_t, framework>(std::basic_string<char_t> { expected }, actual);
    }

    template <typename char_t, typename framework = simply::assert::framework::default>
    void is_equal(const std::basic_string<char_t>& expected, const char_t* actual)
    {
        is_equal<char_t, framework>(expected, std::basic_string<char_t> { actual });
    }

    template <typename char_t, typename framework = simply::assert::framework::default>
    void is_equal(const char_t* expected, const char_t* actual)
    {
        is_equal<char_t, framework>(std::basic_string<char_t> { expected }, std::basic_string<char_t> { actual });
    }

    #pragma endregion

    #pragma region is_not_equal

    template <typename char_t, typename framework = simply::assert::framework::default>
    void is_not_equal(const std::basic_string<char_t>& not_expected, const std::basic_string<char_t>& actual)
    {
        if (not_expected == actual)
        {
            std::basic_ostringstream<char_t> message;
            message << "Not expected: \"" << not_expected << "\"\n";
            message << "Actual: \"" << actual << "\"";
            fail<framework>(message.str());
        }
    }

    template <typename char_t, typename framework = simply::assert::framework::default>
    void is_not_equal(const char_t* not_expected, const std::basic_string<char_t>& actual)
    {
        is_not_equal<char_t, framework>(std::basic_string<char_t> { not_expected }, actual);
    }

    template <typename char_t, typename framework = simply::assert::framework::default>
    void is_not_equal(const std::basic_string<char_t>& not_expected, const char_t* actual)
    {
        is_not_equal<char_t, framework>(not_expected, std::basic_string<char_t> { actual });
    }

    template <typename char_t, typename framework = simply::assert::framework::default>
    void is_not_equal(const char_t* not_expected, const char_t* actual)
    {
        is_not_equal<char_t, framework>(std::basic_string<char_t> { not_expected }, std::basic_string<char_t> { actual });
    }

    #pragma endregion
}}
