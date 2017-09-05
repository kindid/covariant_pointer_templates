///(C)2015+ kuiash.com; code@kuiash.com, twitter.com/kuiash
///kuiash.com,mere cottage,linnetts lane,sturmer,essex,cb9 7xw
///company reg 08590405;vat 196184766#ifndef _h_ptr_h_

#ifndef _h_ptr_h_
#define _h_ptr_h_

////////////////////////////////////////////////////////////////

#include <isa.h>

////////////////////////////////////////////////////////////////

template<typename _inner>
    struct ptr
    {
        using _t_inner = _inner;
        _inner * _data;

        ptr() : _data(nullptr)
        { }

        ptr(_inner * _data) : _data(_data)
        { }

        template<typename _t> ptr(const ptr<_t> & _that)
        {
            // note; rather annoyingly you can't put anything in
            // static_assert other than a string literal which
            // really limits what one can do (static const char * FTW??)
            static_assert(
                isa<_t, _inner>::_t_isa::_v,
                "Cannot cast pointer. Incompatible types");

            _data = _that._data;
        }
    };

////////////////////////////////////////////////////////////////

#endif
