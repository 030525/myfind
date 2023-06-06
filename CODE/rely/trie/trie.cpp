#include "trie.h"

void Trie::insert(const std::string &s)
{
    node * now = root;
    std::map<char,node *>::iterator iter;
    for (char c : s) 
    {
        iter = now->son.find(c);

        if (iter == now->son.end()) 
        {
            node* newNode = new node();
            now->son[c] = newNode;
            now = newNode; 
        } 
        else 
        {
            now = iter->second;
        }
    }

    now->end = true;
}

bool Trie::find(const std::string &s)const
{
    node * now = root;
    std::map<char,node *>::iterator iter;

    for (char c : s) 
    {
        iter = now->son.find(c);

        if (iter == now->son.end()) 
        {
            return false;
        } 
        else 
        {
            now = iter->second;
        }
    }
    
    return true;
}

void Trie::out() const
{
}
