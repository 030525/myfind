#ifndef _match_h_
#define _match_h_

#include "../args/MatchData.h"
#include <boost/filesystem.hpp>
#include <boost/asio/thread_pool.hpp>

using bfp = boost::filesystem::path;

class Match : private MatchData{

public:
    Match(boost::asio::thread_pool * threadspool = nullptr):threads(threadspool)
    {
        if(threads == nullptr)
        {
            threads = new boost::asio::thread_pool(3);
        }
    }

	bool match(const bfp & path);
private:
    std::atomic<bool> flag = true;

    boost::asio::thread_pool *threads;

    bool matchNameSkip(const bfp & path);//比较文件名称
    bool matchType(const bfp & path);//比较文件类型
    bool matchSize(const bfp & path);
    //bool matchPermission(const bfp & path);//比较文件权限
};

#endif



