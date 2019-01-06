//
// Created by yanchao on 2019/1/6.
// leetcode 129 求根到叶子节点数字之和

#ifndef TREE_SUMNUMBERS_H
#define TREE_SUMNUMBERS_H

#endif //TREE_SUMNUMBERS_H
#include <map>
#include <vector>
class SumNumbers
{
public:
    int sumNumbers(TreeNode *root)
    {
        vector<int> v;
        if(root == nullptr)
            return 0;
        dfs(root, root->val);

        return count;
    }

    void dfs(TreeNode *r, int val)
    {
        if(!r->left && !r->right)
        {
            count += val;
        }
        if(r->left)
            dfs(r->left, val * 10 + r->left->val);
        if(r->right)
            dfs(r->right, val * 10 + r->right->val);
    }
private:
    map<TreeNode *, int> r;
    int count = 0;
};