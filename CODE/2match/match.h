#ifndef _match_h_
#define _match_h_

#include "../args/MatchData.h"
class Match : private MatchData{

public:
	Match(MatchData && _data):MatchData(std::move(_data))
    {}
private:

};

#endif



