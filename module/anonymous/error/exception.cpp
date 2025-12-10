export module anonymous.error:exception;
import        anonymous.basic;
import        std;

export namespace anonymous
{
    class exception;
        class logic_error;
        class runtime_error;
        class signal;

    class exception
        extends public std::exception
    {
        public: // Core
            exception ( ) = default;
            exception ( const exception& );
            template < class... types > 
            exception ( format_string<types...>, types&&... );

        public: // Member
            virtual const char* what ( ) const noexcept;

        private: // Data
            std::string message = "";
            std::stacktrace stacktrace = std::stacktrace();
    };

    class logic_error
        extends public exception
    {
        public:
            using exception::exception;
    };

    class runtime_error
        extends public exception
    {
        public:
            using exception::exception;
            runtime_error ( ) = delete; // A runtime error must carry message.
    };

    class signal
        extends public exception
    {
        using exception::exception;
    };
}



namespace anonymous
{
    constexpr std::string_view red        = "\033[38;2;240;0;0m";
    constexpr std::string_view yellow     = "\033[38;2;240;240;0m";
    constexpr std::string_view green      = "\033[38;2;0;240;0m";
    constexpr std::string_view blue       = "\033[38;2;0;120;240m";
    constexpr std::string_view white      = "\033[38;2;192;192;192m";
    constexpr std::string_view light_grey = "\033[38;2;144;144;144m";
    constexpr std::string_view grey       = "\033[38;2;96;96;96m";
    constexpr std::string_view dark_grey  = "\033[38;2;48;48;48m";

    std::string format_stacktrace_color ( std::string str )
    {
        constexpr std::array<std::string_view,4> colors = { white, light_grey, grey, dark_grey };

        size_t pos = 0;
        size_t depth = 0;
        while ( true )
        {
            pos = std::min(str.find('<', pos), str.find('>', pos));

            if ( pos == str.npos )
                return str;
            
            else if ( str[pos] == '<' )
            {
                ++depth;
                auto color = colors[std::clamp(depth, 0uz, colors.size()-1)];
                str.insert(pos, color);
                pos += color.size() + 1;
            }

            else if ( str[pos] == '>' )
            {
                --depth;
                auto color = colors[std::clamp(depth, 0uz, colors.size()-1)];
                str.insert(pos, color);
                pos += color.size() + 1;
            }
        }
    }

    std::string format_stacktrace ( const std::stacktrace& trace )
    {
        return trace | std::views::reverse
                     | std::views::transform([&] (const auto& entry)
                         {
                             if (entry.source_file() != "" and entry.source_line() != 0)
                                 return std::format("    {}{} {}{} {}{} {}{}:{}{}",
                                                    yellow, "at", white, format_stacktrace_color(entry.description()),
                                                    green,  "in", grey,  entry.source_file(), entry.source_line(),
                                                    white);
                             else
                                 return std::format("    {}{} {}{}{}",
                                                    yellow, "at", white, format_stacktrace_color(entry.description()),
                                                    white);
                         })
                     | std::views::join_with('\n')
                     | std::ranges::to<std::string>();
    }

    template < class... types >
    exception::exception ( format_string<types...> str, types&&... args )
        extends message ( str.format(std::forward<decltype(args)>(args)...) + '\n' + format_stacktrace(std::stacktrace::current()) )
    {
        
    }

    const char* exception::what ( ) const noexcept
    {
        return message.c_str();
    }
}