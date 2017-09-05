///(C)2015+ kuiash.com; code@kuiash.com, twitter.com/kuiash
///kuiash.com,mere cottage,linnetts lane,sturmer,essex,cb9 7xw
///company reg 08590405;vat 196184766

////////////////////////////////////////////////////////////////

#include <iostream>
#include <typeinfo>
#include <sanitise.h>

////////////////////////////////////////////////////////////////

#include <object.h>
#include <inherits.h>
#include <isa.h>
#include <ptr.h>

////////////////////////////////////////////////////////////////
///
///            test hierarchy
///
///         .---------object----.
///         va                  vb
///         |                   |
///         vaa                 vbb-----.
///                             |       |
///                             vbbb    vbbc
///
////////////////////////////////////////////////////////////////

struct va : inherits<object>
{ };

struct vb : inherits<object>
{ };

struct vbb : inherits<vb>
{ };

struct vaa : inherits<va>
{ };

struct vbbb : inherits<vbb>
{ };

struct vbbc : inherits<vbb>
{ };

////////////////////////////////////////////////////////////////

#define DECL(...) __VA_ARGS__
#define HACK2(x) { std::cout << '"' << #x << '"' << " == " << sanitise(typeid(DECL x).name()); }

////////////////////////////////////////////////////////////////

int main(int /*argc*/, char * /*argv*/[])
{
    // check casts
    ptr<va> _p_va;
    ptr<va> _p_va_2;
    _p_va = _p_va_2;
    ptr<vaa> _p_vaa;
    // you can't do this without run time checking. that is, this is NOT possible
    // as it is not possible to know that _p_va is a pointer to the inherited
    // type _p_vaa without storing some runtime information about it
    //_p_vaa = _p_va;   // uncomment this line to break compilation
    ptr<object> _p_catch_all_objects;
    // you CAN do this, but, once it's in there it's impossible to get the
    // pointer back out as a ptr<va> without runtime information (vtable for example)
    _p_catch_all_objects = _p_va;

//    std::cout << (isa<vbbb,vb>::_t_isa::_v);  // _t_v is NOT a type, it IS a value. should be _v

    std::cout << "isa object" << "\n";

    HACK2((isa<object,object>::_t_isa));
    HACK2((isa<va,object>::_t_isa));
    HACK2((isa<vaa,object>::_t_isa));
    HACK2((isa<vb,object>::_t_isa));
    HACK2((isa<vbb,object>::_t_isa));
    HACK2((isa<vbbb,object>::_t_isa));
    HACK2((isa<vbbc,object>::_t_isa));

    std::cout << "isa va" << "\n";

    HACK2((isa<object,va>::_t_isa));
    HACK2((isa<va,va>::_t_isa));
    HACK2((isa<vaa,va>::_t_isa));
    HACK2((isa<vb,va>::_t_isa));
    HACK2((isa<vbb,va>::_t_isa));
    HACK2((isa<vbbb,va>::_t_isa));
    HACK2((isa<vbbc,va>::_t_isa));

    std::cout << "isa vaa" << "\n";

    HACK2((isa<object,vaa>::_t_isa));
    HACK2((isa<va,vaa>::_t_isa));
    HACK2((isa<vaa,vaa>::_t_isa));
    HACK2((isa<vb,vaa>::_t_isa));
    HACK2((isa<vbb,vaa>::_t_isa));
    HACK2((isa<vbbb,vaa>::_t_isa));
    HACK2((isa<vbbc,vaa>::_t_isa));

    std::cout << "isa vb" << "\n";

    HACK2((isa<object,vb>::_t_isa));
    HACK2((isa<va,vb>::_t_isa));
    HACK2((isa<vaa,vb>::_t_isa));
    HACK2((isa<vb,vb>::_t_isa));
    HACK2((isa<vbb,vb>::_t_isa));
    HACK2((isa<vbbb,vb>::_t_isa));
    HACK2((isa<vbbc,vb>::_t_isa));

    std::cout << "isa vbb" << "\n";

    HACK2((isa<object,vbb>::_t_isa));
    HACK2((isa<va,vbb>::_t_isa));
    HACK2((isa<vaa,vbb>::_t_isa));
    HACK2((isa<vb,vbb>::_t_isa));
    HACK2((isa<vbb,vbb>::_t_isa));
    HACK2((isa<vbbb,vbb>::_t_isa));
    HACK2((isa<vbbc,vbb>::_t_isa));

    std::cout << "isa vbbb" << "\n";

    HACK2((isa<object,vbbb>::_t_isa));
    HACK2((isa<va,vbbb>::_t_isa));
    HACK2((isa<vaa,vbbb>::_t_isa));
    HACK2((isa<vb,vbbb>::_t_isa));
    HACK2((isa<vbb,vbbb>::_t_isa));
    HACK2((isa<vbbb,vbbb>::_t_isa));
    HACK2((isa<vbbc,vbbb>::_t_isa));

    std::cout << "isa vbbc" << "\n";

    HACK2((isa<object,vbbc>::_t_isa));
    HACK2((isa<va,vbbc>::_t_isa));
    HACK2((isa<vaa,vbbc>::_t_isa));
    HACK2((isa<vb,vbbc>::_t_isa));
    HACK2((isa<vbb,vbbc>::_t_isa));
    HACK2((isa<vbbb,vbbc>::_t_isa));
    HACK2((isa<vbbc,vbbc>::_t_isa));
}

////////////////////////////////////////////////////////////////
