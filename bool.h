///(C)2015+ kuiash.com; code@kuiash.com, twitter.com/kuiash
///kuiash.com,mere cottage,linnetts lane,sturmer,essex,cb9 7xw
///company reg 08590405;vat 196184766

#ifndef _h_bool_h_
#define _h_bool_h_

////////////////////////////////////////////////////////////////

template<bool __v>
    struct bool_type
    {
        using _t_type = bool;
        static const bool _v = __v;
        constexpr operator bool() const { return __v; }
    };

struct t_false : bool_type<false> { };

struct t_true : bool_type<true> { };

////////////////////////////////////////////////////////////////

template<class _bool> struct invert;

template<>
    struct invert<t_true>
    {
        using _t_result = t_false;
    };

template<>
    struct invert<t_false>
    {
        using _t_result = t_true;
    };

////////////////////////////////////////////////////////////////

#endif
