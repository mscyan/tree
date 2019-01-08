//
// Created by yanchao on 2019/1/7.
// 前缀树Trie  leetcode 208

#ifndef TREE_TRIE_H
#define TREE_TRIE_H

#endif //TREE_TRIE_H
#include "NTreeNode.h"
class Trie
{
public:
    Trie()
    {
        root = new NTreeNode<char>();
    }

    void insert(string word)
    {
        if(word.length() == 0)
        {
            return ;
        }
        bool hasWord = startsWith(word);
        //需要重新进入节点，并将末尾节点isEnd标为true；
        if(hasWord)
        {
            NTreeNode<char> *p = root;
            for(int i=0;i<word.length();i++)
            {
                vector<NTreeNode<char> *> children = p->children;
                for(auto t : children)
                {
                    if(t->val == word[i])
                    {
                        string ord = word.substr(i+1, word.length());
                        p = t;
                    }
                }
            }
            p->isEnd = true;
        }
        else if(!hasWord)
        {
            NTreeNode<char> *p = root;
            for(int i=0;i<word.length();i++)
            {
                vector<NTreeNode<char> *> children = p->children;
                bool has = false;
                for(auto t : children)
                {
                    if(t->val == word[i])
                    {
                        //表明存在这个字符
                        string ord = word.substr(i+1, word.length());
                        has = true;
                        p = t;
                    }
                }
                if(!has)
                {
                    //如果没有这个节点的话,表示不包含这个前缀
                    //此时需要重新构建子节点
                    p->size ++;
                    for(int j=i;j<word.length();j++)
                    {
                        NTreeNode<char> *tmp = new NTreeNode<char>(word[j]);
                        p->children.push_back(tmp);
                        p = p->children[p->children.size()-1];
                    }
                    p->isEnd = true;
                    return ;
                }
            }
        }
    }

    //search()函数主要是查找是否含有（匹配）这个word串，
    // 如果是前缀，但尾字符的children还包含其他节点，则返回false
    bool search(string word)
    {
        if(startsWith(word) == false)
            return false;
        else
        {
            NTreeNode<char> *p = root;
            for(int i=0;i<word.length();i++)
            {
                vector<NTreeNode<char> *> children = p->children;
                bool has = false;
                for(auto t : children)
                {
                    if(t->val == word[i])
                    {
                        //表明存在这个字符
                        string ord = word.substr(i+1, word.length());
                        has = true;
                        p = t;
                    }
                }
                if(!has)
                {
                    //如果没有这个节点的话,表示不包含这个前缀
                    return false;
                }
            }
            if(p->isEnd)
                return true;
            else
                return false;
        }
        return false;
    }

    bool startsWith(string prefix)
    {
        if(root->size == 0)
            return false;
        if(prefix.length() == 0)
            return true;
        // 遍历节点
        NTreeNode<char> *p = root;
        for(int i=0;i<prefix.length();i++)
        {
            vector<NTreeNode<char> *> children = p->children;
            bool has = false;
            for(auto t : children)
            {
                if(t->val == prefix[i])
                {
                    //表明存在这个字符
                    string ord = prefix.substr(i+1, prefix.length());
                    has = true;
                    p = t;
                }
            }
            if(!has)
            {
                //如果没有这个节点的话,表示不包含这个前缀
                return false;
            }
        }
        return true;
    }
private:
    NTreeNode<char> *root;
};