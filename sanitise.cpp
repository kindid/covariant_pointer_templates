///(C)2015+ kuiash.com; code@kuiash.com, twitter.com/kuiash
///kuiash.com,mere cottage,linnetts lane,sturmer,essex,cb9 7xw
///company reg 08590405;vat 196184766

////////////////////////////////////////////////////////////////

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

////////////////////////////////////////////////////////////////

std::string sanitise(const char * _criminally_insane)
{
    std::array<char, 256> _buffer;
    std::string _sane;

    std::string command("c++filt ");
    command.append(_criminally_insane);

    std::shared_ptr<FILE> pipe(popen(command.data(), "r"), pclose);

    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    else {
        while (!feof(pipe.get())) {
            if (fgets(_buffer.data(), _buffer.size(), pipe.get()) != nullptr) {
                _sane += _buffer.data();
            }
        }
    }

    return _sane;
}

////////////////////////////////////////////////////////////////
