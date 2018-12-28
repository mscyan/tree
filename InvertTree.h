//
// Created by yanchao on 2018/12/28.
// leetcode 226 翻转二叉树

#ifndef TREE_INVERTTREE_H
#define TREE_INVERTTREE_H

#endif //TREE_INVERTTREE_H
class InvertTree
{
public:
    TreeNode* invertTree(TreeNode *root)
    {
        if(root == nullptr)
            return nullptr;

        TreeNode *toor = root;
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        toor->left = invertTree(r);
        toor->right = invertTree(l);
        return toor;
    }
};