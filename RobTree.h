//
// Created by yanchao on 2019/1/6.
// leetcode 337 打家劫舍 III

#ifndef TREE_ROBTREE_H
#define TREE_ROBTREE_H

#endif //TREE_ROBTREE_H
class RobTree
{
public:
    int robTree(TreeNode *root)
    {
        if(root==nullptr)
            return 0;
        if(!root->left && !root->right)
            return root->val;

        int countT = root->val;  //根节点偷
        int countF = 0;          //根节点不偷

        int c1 = root->left != nullptr ? robTree(root->left->left) + robTree(root->left->right) : 0;
        int c2 = root->right != nullptr ? robTree(root->right->left) + robTree(root->right->right) : 0;

        return max(c1+c2+root->val, robTree(root->left) + robTree(root->right));
    }
};

//打家劫舍的数组版本，以及环形链表版本都是用的dp的思想
// ，即前n-2和前n-3户可偷盗的金额 分别加上当前的金额或者前一户的金额

