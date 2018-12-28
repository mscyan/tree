//
// Created by yanchao on 2018/12/28.
// leetcode 236 二叉树的最近公共祖先
// 区别于235，本题中非二叉搜索树

#ifndef TREE_LOWESTCOMMONANCESTOR_H
#define TREE_LOWESTCOMMONANCESTOR_H

#endif //TREE_LOWESTCOMMONANCESTOR_H
class LowestCommonAncestor1
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == nullptr)
            return root;
        if(root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        return left && right ? root : left == nullptr ? right : left;
    }

    TreeNode *noRecursiveToLCA(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        //todo 能否用非递归的方式，求得本题的解？
        return nullptr;
    }
};