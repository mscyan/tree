//
// Created by yanchao on 2018/12/28.
// leetcode 235 二叉搜索树的最近公共祖先

#ifndef TREE_LOWESTCOMMONANCESTER_H
#define TREE_LOWESTCOMMONANCESTER_H

#endif //TREE_LOWESTCOMMONANCESTER_H
class LowestCommonAncestor
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == nullptr)
            return nullptr;
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
