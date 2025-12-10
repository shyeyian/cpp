export module anonymous.basic:constexprs.pack;

export namespace anonymous::inline basic
{
    template < class... types >            
    using first_type_of = types...[0];

    template < class... types >            
    using last_type_of = types...[sizeof...(types)-1];

    template < int index, class... types > 
    using index_type_of = types...[index >= 0 ? index-1 : index+sizeof...(types)];

    constexpr decltype(auto) first_value_of ( auto&&... );
    constexpr decltype(auto) first_value_of ( auto&&... );
    template < int index >
    constexpr decltype(auto) first_value_of ( auto&&... );   
}



namespace anonymous::inline basic
{
    constexpr decltype(auto) first_value_of ( auto&&... args ) 
    { 
        return args...[0]; 
    };
                                          
    constexpr decltype(auto) last_value_of ( auto&&... args ) 
    { 
        return args...[sizeof...(args)-1];
    };

    template < int index >                 
    constexpr decltype(auto) index_value_of ( auto&&... args ) 
    { 
        return args...[index >= 0 ? index-1 : index+sizeof...(args)]; 
    }

}