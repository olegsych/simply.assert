#pragma once

#include <exception>
#include <memory>
#include <sstream>
#include <simply/assert/fail.h>
#include <simply/assert/framework.h>
#include <simply/assert/implementation.h>

namespace simply { namespace assert
{
    template<typename exception_t, typename functor_t, typename framework = simply::assert::framework::default>
    std::unique_ptr<exception_t> throws(functor_t&& functor)
    {
        std::exception_ptr actual_exception;

        try
        {
            functor();
        }
        catch (const exception_t& e)
        {
            return std::unique_ptr<exception_t> { new exception_t { e } };
        }
        catch (...)
        {
            actual_exception = std::current_exception();
        }

        std::ostringstream message;
        message << "Expected exception of type: <" << implementation::type_name<exception_t>() << ">";

        if (actual_exception)
        {
            try
            {
                std::rethrow_exception(actual_exception);
            }
            catch (const std::exception& e)
            {
                message << "\n" << "Actual exception of type: <" << typeid(e).name() << ">.";
            }
        }

        fail<framework>(message.str());
        return std::unique_ptr<exception_t> { nullptr };
    }
}}
