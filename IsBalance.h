//
// Created by yanchao on 2018/12/28.
// leetcode 110 是否是平衡二叉树

#ifndef TREE_ISBALANCE_H
#define TREE_ISBALANCE_H

#endif //TREE_ISBALANCE_H
class IsBalanced
{
public:
    bool isBalanced(TreeNode *root)
    {
        getDepth(root);
        return ans;
    }
private:
    bool ans = true;
    int getDepth(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        int l = getDepth(root->left);
        int r = getDepth(root->right);
        if(abs( l - r ) > 1)
            ans = false;
        return ( l > r ? l : r) + 1;
    }
};