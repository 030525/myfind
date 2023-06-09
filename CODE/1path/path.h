#ifndef _path_h_
#define _path_h_

#include <vector>
#include <string>

class Path{

public:
    Path(std::vector<std::string> && _path):paths(std::move(_path))
    {

    }

	std::vector<std::string> getPath()const;

    inline std::string getDefaultPath()const
    {
        return default_path;
    }

private:
    std::vector<std::string> paths;
    std::string default_path;
};



#endif



