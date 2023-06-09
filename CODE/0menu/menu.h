#ifndef _menu_h_
#define _menu_h_

#include "../rely/cxxopts/include/cxxopts.hpp"
#include "../1path/path.h"

class Menu{

public:
    Menu(const cxxopts::ParseResult &  _result):result(_result)
    {
        //readConf;

        if(inf()) return;

        if(opearte() == false) return;

        //writeConf;
    }
private:

    bool inf();
    bool opearte();

    const cxxopts::ParseResult result;

};

#endif



