//
// Created by yanchao on 2019/1/7.
//

#ifndef TREE_NTREENODE_H
#define TREE_NTREENODE_H

#endif //TREE_NTREENODE_H
#include <vector>
using namespace std;
template <typename T>
struct NTreeNode
{
    T val;
    T size;
    vector<NTreeNode* > children;
    bool isEnd = false;
    NTreeNode<T>() : size(0) {}

    NTreeNode<T>(T val) : val(val), size(1)
    {
        vector<NTreeNode*> children;
        this->children = children;
    }
};
