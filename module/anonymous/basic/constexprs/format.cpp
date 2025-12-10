export module anonymous.basic:constexprs.format;
import                       :concepts;
import        std;

export namespace anonymous::inline basic
{
    template < characteral char_type, class... types >
    class basic_format_string
    {
        public:
            consteval basic_format_string ( const char_type* );
            constexpr std::string format ( types&&... ) const;

        private:
            enum class format_mode { explicit_mode, implicit_mode };
            format_mode mode = format_mode::explicit_mode;
            std::string_view view = std::string_view();
    };

    template < class... types >
    using format_string = basic_format_string<char, type_identity<types>...>;
}



namespace anonymous::inline basic
{
    template < characteral char_type, class... types >
    consteval basic_format_string<char_type, types...>::basic_format_string ( const char_type* ptr )
        extends view ( ptr )
    {
        auto it = std::find(view.begin(), view.end(), '{');
        if (it != view.end() and *(it + 1) > '0' and *(it + 1) < '9')
        {
            self.mode = format_mode::explicit_mode;
            /*static*/ assert(*(it + 1) != '0', "format index should start from {1}");
            [[maybe_unused]] auto check = std::basic_format_string<char_type,int,types...>(ptr);
        }
        else
        {
            self.mode = format_mode::implicit_mode;
            [[maybe_unused]] auto check = std::basic_format_string<char_type,types...>(ptr);
        }
    }

    template < characteral char_type, class... types >
    constexpr std::string basic_format_string<char_type, types...>::format ( types&&... args ) const
    {
        if (self.mode == format_mode::explicit_mode)
        {
            auto placeholder = "";
            return std::vformat(self.view, std::make_format_args(placeholder, args...));
        }
        else
            return std::vformat(self.view, std::make_format_args(args...));
    }
    
}