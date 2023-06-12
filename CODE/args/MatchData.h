#ifndef _MatchData_h_
#define _MatchData_h_

class MatchData
{
public:
    std::vector<std::string> match;
    
    //find_hidden可以放在skip里，那么默认就是全部查找
    std::vector<std::string> skip;

    int low_limit_size;
    int up_limit_size;

    bool file;
    bool directory;
    bool link;
    bool block;
    bool character;
    bool sockets;
};

#endif



