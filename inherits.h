///(C)2015+ kuiash.com; code@kuiash.com, twitter.com/kuiash
///kuiash.com,mere cottage,linnetts lane,sturmer,essex,cb9 7xw
///company reg 08590405;vat 196184766

#ifndef _h_inherits_
#define _h_inherits_

////////////////////////////////////////////////////////////////

template<typename _parent>
    struct inherits : _parent
    {
        using _t_inherits = _parent;
    };

////////////////////////////////////////////////////////////////

#endif
