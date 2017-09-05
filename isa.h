///(C)2015+ kuiash.com; code@kuiash.com, twitter.com/kuiash
///kuiash.com,mere cottage,linnetts lane,sturmer,essex,cb9 7xw
///company reg 08590405;vat 196184766

#ifndef _h_isa_h_
#define _h_isa_h_

////////////////////////////////////////////////////////////////

#include <object.h>
#include <bool.h>

////////////////////////////////////////////////////////////////

template<typename _class, typename _isa> struct isa;

template<>
    struct isa<object, object>
    {
        using _t_isa = t_true;
    };

template<typename _class>
    struct isa<_class, _class>
    {
        using _t_isa = t_true;
    };

template<typename _class>
    struct isa<object, _class>
    {
        using _t_isa = t_false;
    };

template<typename _class, typename _isa>
    struct isa
    {
        using _t_isa = typename isa<typename _class::_t_inherits, _isa>::_t_isa;
    };

#endif
