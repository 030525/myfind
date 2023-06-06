#include "find.h"


namespace bf = boost::filesystem;
using bfp = boost::filesystem::path;

bool find_content()
{
    return true;
}

inline bool filter_hide(const bf::directory_iterator & iter)
{
    return iter->path().filename().string()[0] == '.';
}

bool find_from_path(const bfp & path,
                    const std::vector<std::string> & file_name,const std::vector<std::string> & content,const std::vector<std::string> &  skip,
                    size_t size ,boost::filesystem::perms perms,int depth = INT32_MAX,bool find_hidden = false)
{
     for (const auto& entry : bf::directory_iterator(path)) 
     {
     }
     return true;
}