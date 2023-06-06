#include "rely/cxxopts/include/cxxopts.hpp"
#include <boost/filesystem.hpp>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include "other/conf.h"
#include <iostream>

namespace  fs = boost::filesystem;
using vs = std::vector<std::string>;



namespace start{
    //当path为空就从default_path开始找
    extern vs path;
    extern std::string default_path;
}


namespace match{
    //一开始默认严格匹配
    //不给名字或者content就报错
    extern vs name;
    extern vs content;
    extern bool case_sensitive;
}

namespace filter{
    extern const int NO_LIMIT;

    extern int size;//上限
    extern int depth; 
    //std::string date; 需要一个日期库
    extern vs type;//directory,file,exe,script
    
    extern vs skip;//默认无
    extern bool find_hidden ;

}

namespace end{
    //time size type...
    extern int sort;
    extern std::string output_path;
    extern bool height_light;
}

namespace thread{
    extern size_t size;
}

//设置线程池
boost::asio::thread_pool pool(thread::size);

void find(const boost::filesystem::path & path)
{
        try {
                for (const auto& entry : fs::directory_iterator(path)) {
        // 处理所有文件和子目录，包括嵌套子目录
        fs::path filePath = entry.path();

        // 打印文件名
        std::cout <<" " <<filePath.filename().generic_string();

        // 检查是否为目录
        if (fs::is_directory(filePath)) {
            // 进一步处理子目录
            //std::cout << "*";
            //find(filePath);
            boost::asio::post(pool,[filePath](){
                find(filePath);
            });
        }
        }
        std::cout <<"\n";
        } catch (const boost::filesystem::filesystem_error& ex) {
            
        }

}

void Menu(const cxxopts::ParseResult & result )
{   

    readConf();

    if(result.count("get-default-path"))
    {
        std::cout << "default path(before --set-default-path): " << start::default_path;
    }

    if(result.count("set-default-path"))
    {
        writeConf();
    }

    //当path为空，从default_path中查找
    if(start::path.size() == 0)
    {
        start::path.push_back(start::default_path);
    }

    //查找
    fs::path dir_path;

    for(auto & i : start::path)
    {
        dir_path = i;

        boost::asio::post(pool,[dir_path](){
            find(dir_path);
        });
    }

    pool.join();

}