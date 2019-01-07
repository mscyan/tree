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
//        vector<NTreeNode<char> *> childs = root->children;
        bool hasWord = startWith(word);
        if(!hasWord)
        {
//            NTreeNode<char> *newNode = new NTreeNode<char>(word[0]);
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
                    for(int j=i;j<word.length();j++)
                    {
                        p->size ++;
                        NTreeNode<char> *tmp = new NTreeNode<char>(word[j]);
                        p->children.push_back(tmp);
                        p = p->children[p->children.size()-1];
                    }
                    return ;
                }
            }
        }
        cout<<root->size<<endl;
    }

    bool startWith(string prefix)
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