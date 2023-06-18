#ifndef _match_h_
#define _match_h_

#include "../args/MatchData.h"
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

class Match : private MatchData{

public:
	bool match(const boost::filesystem::path & path)
    {
        
    }
private:

};

#endif



