#ifndef _model_h_
#define _model_h_

#include <map>

template<typename K,typename V>
class Model{

public:
	void insert(K && k,V && v);
    std::multimap<K,V> getData()const;
private:
    std::multimap<K,V> _map;
};

#endif

template <typename K, typename V>
inline void Model<K, V>::insert(K && k, V && v)
{
    _map.insert(std::move(k),std::move(v));
}

template <typename K, typename V>
inline std::multimap<K, V> Model<K, V>::getData() const
{
    return std::multimap<K, V>(_map);
}
