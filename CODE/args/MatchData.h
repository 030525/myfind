#ifndef _MatchData_h_
#define _MatchData_h_

#include <vector>
#include <string>

enum class TYPE{
    FILE = 1,
    DIRECTORY = 2,
    LINK = 4,
    BLOCK = 8,
    CHARACTER = 16,
    SOCKETS =32,
    ALL = FILE | DIRECTORY | LINK | BLOCK | CHARACTER | SOCKETS
};

class FileType
{
    void setType()

    private:
        TYPE _type;
};


class MatchData
{
public:
    std::vector<std::string> getMatch()const
    {
        return std::move(match);
    }

    void setMatch(std::vector<std::string> && _match)
    {
        match = std::move(_match);
    }

    std::vector<std::string> getSkip()const
    {
        return std::move(skip);
    }

    void setSkip(std::vector<std::string> && _skip)
    {
        skip = std::move(_skip);
    }




private:
    std::vector<std::string> match;
    
    //find_hidden可以放在skip里，那么默认就是全部查找
    std::vector<std::string> skip;

    int low_limit_size = -1;
    int up_limit_size = INT32_MAX;

};

#endif



