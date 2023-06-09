#include "rely/cxxopts/include/cxxopts.hpp"
#include "rely/log/easylogging++.h"
#include "rely/trie/trie.h"
#include "rely/time/time.h"
#include "0menu/menu.h"
#include "1path/path.h"


using vs = std::vector<std::string>;
const int NO_LIMIT = -1;

namespace start{
    //当path为空就从default_path开始找
    vs path;
    std::string default_path;
        
}

namespace match{
    //一开始默认严格匹配
    //不给名字或者content就报错
    vs name;
    //vs content;
    bool case_sensitive = true;
}

namespace filter{
    int size = NO_LIMIT;//上限
    int depth = NO_LIMIT; 
    vs type;//directory,file,exe,script
    
    vs skip;//默认无
    bool find_hidden = false;

}

namespace end{
    //time size type...
    int sort;
    std::string output_path;
    bool height_light = true;
}

namespace thread{
    size_t size = 16;
}

Path _path;

INITIALIZE_EASYLOGGINGPP


int main(int argc, char** argv) {
        // 配置日志记录器
    el::Configurations conf;

    conf.setToDefault();

    conf.setGlobally(el::ConfigurationType::Format, "%datetime %level %msg");
    conf.setGlobally(el::ConfigurationType::ToFile, "true");
    conf.setGlobally(el::ConfigurationType::Filename, "mylog.log");

    conf.set(el::Level::Info, el::ConfigurationType::ToStandardOutput, "false");
    conf.set(el::Level::Warning, el::ConfigurationType::ToStandardOutput, "false");
    el::Loggers::reconfigureAllLoggers(conf);
    //读myfind.conf

    // 创建选项解析器
    cxxopts::Options options("file_search_engine", "File Search Engine");

    //添加命令参数
    options.add_options("5 thread")
        ("threads","set the size of threads",cxxopts::value<size_t>(thread::size));
        ("get-threads","get the size of threads");
     options.add_options("3 filter")
        ("s,size","filter file smaller than size",cxxopts::value<int>(filter::size))
        //("d,date","filter date of file",cxxopts::value<std::string>(filter::date))
        ("t,type","filter type of file",cxxopts::value<std::vector<std::string>>(filter::type))//
        ("skip","filter skip of file/folder",cxxopts::value<std::vector<std::string>>(filter::skip))//
        ("a,all","filter search hidden file/folder",cxxopts::value<bool>(filter::find_hidden))
        ("depth","filter depth of folder",cxxopts::value<int>(filter::depth));
     options.add_options("4 end")
        ("sort","sort the output",cxxopts::value<int>(end::sort))
        ("o,output","output the answer to the path",cxxopts::value<std::string>(end::output_path))
        ("height-light","height-light the answer",cxxopts::value<bool>(end::height_light))
        ("help","help for all command");

     options.add_options("2 match")
        ("n,name","match file/dirctory's name",cxxopts::value<vs>(match::name))//
        ("case-sensitive","match case-sensitive",cxxopts::value<bool>(match::case_sensitive));

    options.add_options("1 start")
        ("p,path", "start find from path", cxxopts::value<vs>(start::path))//
        ("set-default-path", "reset default-path(default form .)", cxxopts::value<std::string>(start::default_path))
        ("get-default-path", "get default-path");

    //初始化数据
    _path.setPath(std::move(start::path));

    // 解析命令行参数
    auto result = options.parse(argc,argv);

    if(result.count("help"))
    {
        std::cout << options.help();
    }
    else
    {
        Menu m(result);
    }

    return 0;
}



