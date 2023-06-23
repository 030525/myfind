#include "match.h"

using bfp =  boost::filesystem::path;
using bff = boost::filesystem::file_type;
using mt = MatchData::TYPE;

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

bool Match::matchNameSkip(const bfp & path)
{
    //获取文件名
    std::string real_name = path.filename().string();

    //在name中匹配
    auto iter = MatchData::match.find(real_name);

    //没找到则返回false
    if(iter == MatchData::match.end()) return false;

    //在skip中匹配
    auto iter = MatchData::skip.find(real_name);

    //找到了返回flase
    if(iter != MatchData::skip.end()) return false;

    return true;
}

bool Match::matchPermission(const bfp & path)
{

}
