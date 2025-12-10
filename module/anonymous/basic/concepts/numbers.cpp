export module anonymous.basic:concepts.numbers;
import        std;

export namespace anonymous::inline basic
{
    template < class type > concept characteral    = std::same_as<type,char>;
    template < class type > concept integral       = std::signed_integral<type>;
    template < class type > concept floating_point = std::floating_point <type>;
    template < class type > concept numeric        = integral<type> or floating_point<type>;
}