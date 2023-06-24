#include "match.h"

using bfp =  boost::filesystem::path;
using bff = boost::filesystem::file_type;
using bfs = boost::filesystem::file_status;
using mt = MatchData::TYPE;

bool Match::match(const bfp &path)
{
    boost::asio::post(threads,[&flag](){
        if(flag)
        {
            
        }
    });
}

bool Match::matchType(const bfp &path)
{
    //获取文件实际type
    bff file_type = boost::filesystem::status(path).type();
    
    //对比需要的文件类型和实际的文件类型    
    if( this->type & mt::FILE && file_type & boost::filesystem::regular_file ||
        this->type & mt::DIRECTORY && file_type & boost::filesystem::directory_file ||
        this->type & mt::LINK && file_type & boost::filesystem::symlink_file ||
        this->type & mt::CHARACTER && file_type & boost::filesystem::character_file ||
        this->type & mt::SOCKETS && file_type & boost::filesystem::socket_file ||
        this->type & mt::BLOCK && file_type & boost::filesystem::block_file
        )
    {
        return true;
    }

    return false;
}

bool Match::matchSize(const bfp &path)
{
    //默认匹配byte大小
    uint64_t file_size = boost::filesystem::file_size(path);

    return (file_size >= MatchData::low_limit_size) && (file_size <= MatchData::up_limit_size);
    
}

bool Match::matchNameSkip(const bfp &path)
{
    //获取文件名
    std::string real_name = path.filename().string();

    //没找到则返回false
    if(MatchData::match.find(real_name) == MatchData::match.end()) return false;

    //找到了返回flase
    if(MatchData::skip.find(real_name) != MatchData::skip.end()) return false;

    return true;
}

//对于权限，分为绝对权限和相对权限
//绝对权限，则根据owner，group，orther划分
//相对权限，根据当前用户和文件的关系，
//如当前用户对于a文件是owner，b文件是group，
//那么就按照owner和group分别查找ab

//目前不考虑
/*
bool Match::matchPermission(const bfp & path)
{
    return false;
}
*/
