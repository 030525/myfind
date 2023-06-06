#ifndef _find_h_
#define _find_h_

#include <boost/filesystem.hpp>

namespace bf = boost::filesystem;
using bfp = boost::filesystem::path;

bool find_content();

inline bool filter_find_hidden(bool find_hidden);

bool find_from_path(const bfp & path,
                    const std::vector<std::string> & file_name,const std::vector<std::string> & content,const std::vector<std::string> &  skip,
                    size_t size ,boost::filesystem::perms perms,int depth,bool find_hidden);

#endif



