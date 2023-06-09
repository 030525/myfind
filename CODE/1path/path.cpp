#include "path.h"
#include "../rely/time/time.h"
std::vector<std::string> Path::getPath() const
{
    std::vector<std::string> ret(paths);

    if(ret.size() == 0)
    {
        ret.push_back(Path::default_path);
    }

    return std::move(ret);
}




