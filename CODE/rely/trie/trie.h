#ifndef _trie_h_
#define _trie_h_

#include <map>
#include <string>

struct node
{
   std::map<char,struct node *> son;

   bool end = false;

};
typedef struct node node;

class Trie{
 
public:
   Trie():root(new node){};
	void insert(const std::string & s );
   bool find(const std::string & s)const;
   void out()const;
private:
   node *root;
};

#endif



