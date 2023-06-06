#ifndef _conf_h_
#define _conf_h_

#include "../rely/log/easylogging++.h"
#include <boost/filesystem.hpp>
#include <set>
#include <string>

namespace start{
    extern std::string default_path;
}

namespace thread{
    extern size_t size;
}

const std::string CONFIGURATION = "myfind.conf";

void initConf(std::set<std::string> & _set);
void readConf();
void writeConf();

#endif



