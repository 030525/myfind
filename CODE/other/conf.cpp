#include "conf.h"


std::string  findConf(const std::string & in,const std::string & _find )
{
    std::string s = _find + "=";

    std::string out = "";
    int index = in.find(s);

    if(index != std::string::npos)
    {
        out = in.substr(s.size(),in.length() - index);
    }

    return std::move(out);
}

void initConf(std::set<std::string> &_set)
{
    _set.insert("DEFAULT_PATH");
}

void analyzeConf(const std::string &  marco,const std::string & in)
{
    std::string value = findConf(in,marco);

    if(marco == "DEFAULT_PATH")
    {
        start::default_path = value;
        LOG(INFO) << "read defautl_path :" << start::default_path;
    }
}

void readConf()
{
    std::ifstream o(CONFIGURATION);

    if (o.is_open() == false)
    {
        LOG(ERROR) << "cant open myfind.conf in readconf";
        return ;
    }

    std::set<std::string> set;
    initConf(set);

    std::string s;
    std::set<std::string>::iterator iter;
    while (std::getline(o, s))
    {
        iter = set.begin();
        analyzeConf(*iter,s);
        iter = set.erase(iter);        
    }

    o.close();
}

//有待改进，目前是截断模式，就是全部删除重写，而非修改
void writeConf()
{
    using bff = boost::filesystem::fstream;
    boost::filesystem::fstream f(CONFIGURATION ,bff::trunc | bff::out);

    if(f.is_open() == false)
    {
        LOG(ERROR) << "cant open myfind.conf in writeconf";
        return ;
    }

    std::string default_path = "DEFAULT_PATH="+start::default_path;
    f << default_path << std::endl;

    LOG(INFO) << "set default path : "<< start::default_path; 
    f.close();
}
