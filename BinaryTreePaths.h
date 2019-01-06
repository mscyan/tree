//
// Created by yanchao on 2019/1/6.
// leetcode 257 二叉树的所有路径

#ifndef TREE_BINARYTREEPATHS_H
#define TREE_BINARYTREEPATHS_H

#endif //TREE_BINARYTREEPATHS_H
#include <string>
using namespace std;
class BinaryTreePaths
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if(root == nullptr)
            return rv;
        dfs(root, to_string(root->val));
        return rv;
    }

    void dfs(TreeNode *root, string s)
    {
        if(!root->left && !root->right)
        {
            rv.push_back(s);
        }
        if(root->left)
        {
            string ts = s + "->" + to_string(root->left->val);
            dfs(root->left, ts);
        }
        if(root->right)
        {
            string ts = s + "->" + to_string(root->right->val);
            dfs(root->right, ts);
        }
    }
private:
    vector<string> rv;
};