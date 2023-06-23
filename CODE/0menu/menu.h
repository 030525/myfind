#ifndef _menu_h_
#define _menu_h_

#include "../rely/cxxopts/include/cxxopts.hpp"
#include "../1path/path.h"

class Menu{

public:
    //读取参数
    Menu(const cxxopts::ParseResult &  _result):result(_result)
    {
        //readConf;

        //如果是读取信息，那么不进行操作
        if(inf()) return;

        //是否可以操作
        if(opearte() == false) return;

        //writeConf;
    }
private:

    bool inf()；
    bool opearte();

    const cxxopts::ParseResult result;

};

#endif



