#ifndef _match_h_
#define _match_h_

#include "../args/MatchData.h"
#include <boost/filesystem.hpp>

using bfp = boost::filesystem::path;

class Match : private MatchData{

public:
	bool match(const bfp & path);
private:
    bool matchNameSkip(const bfp & path);//比较文件名称
    bool matchType(const bfp & path);//比较文件类型
    bool matchPermission(const bfp & path);//比较文件权限
};

#endif



