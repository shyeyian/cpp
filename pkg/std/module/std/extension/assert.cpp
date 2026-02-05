export module std:extension.assert;
import           :extension.stdio;
import           :core;


export
{
    constexpr void assert ( bool,              std::source_location = std::source_location::current() );
    constexpr void assert ( bool, const char*, std::source_location = std::source_location::current() );
}



constexpr void assert(bool condition, std::source_location location)
{
    assert(condition, "", location);
}

constexpr void assert(bool condition, const char* message, std::source_location location)
{
    if (not condition)
    {
        if (std::strlen(message) > 0)
            std::println(stderr_, "assertion failed at {} in {}:{}:{}: {}", location.function_name(), location.file_name(), location.line(), location.column(), message);
        else
            std::println(stderr_, "assertion failed at {} in {}:{}:{}",     location.function_name(), location.file_name(), location.line(), location.column());
        std::terminate();
    }
}
