#ifndef _MatchData_h_
#define _MatchData_h_

#include <unordered_set>
#include <string>

class MatchData
{
public:
    enum class TYPE{
        NONE = 0,
        FILE = 1,
        DIRECTORY = 2,
        LINK = 4,
        BLOCK = 8,
        CHARACTER = 16,
        SOCKETS =32,
        ALL = FILE | DIRECTORY | LINK | BLOCK | CHARACTER | SOCKETS
    };

    friend MatchData::TYPE operator | (const MatchData::TYPE & a,const MatchData::TYPE & b)
    {
        return static_cast<MatchData::TYPE>(static_cast<int>(a) | static_cast<int>(b));
    }

    friend int operator & (const MatchData::TYPE & a,const MatchData::TYPE & b)
    {
        return (static_cast<int>(a) & static_cast<int>(b));
    }


public:

    void setMatch(std::unordered_set<std::string> && _match)
    {
        match = std::move(_match);
    }

    void setSkip(std::unordered_set<std::string> && _skip)
    {
        skip = std::move(_skip);
    }

    void setType(TYPE _type)
    {
        type = _type;
    }

protected:
    std::unordered_set<std::string> match;
    
    //find_hidden可以放在skip里，那么默认就是全部查找
    std::unordered_set<std::string> skip;

    //以kb为单位
    //0kb-2048G
    int low_limit_size = -1;
    int up_limit_size = INT32_MAX;

    TYPE type;
};



#endif



