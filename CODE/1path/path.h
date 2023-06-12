#ifndef _path_h_
#define _path_h_

#include "../args/PathData.h"

class Path : private PathData{

public:
    Path(PathData && _pathdata):PathData(std::move(_pathdata))
    {}

	std::vector<std::string> getPath()const;

    inline std::string getDefaultPath()const
    {
        return default_path;
    }
};



#endif



