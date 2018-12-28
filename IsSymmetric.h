//
// Created by yanch on 2018/11/27.
// leetcode 101 对称二叉树
//

#ifndef TREE_ISSYMMETRIC_H
#define TREE_ISSYMMETRIC_H

#endif //TREE_ISSYMMETRIC_H
using namespace std;
class IsSymmetric
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return true;
        if((root->left&&!root->right) || (!root->left&&root->right))
            return false;
        TreeNode *left = root->left;
        TreeNode *right = root->right;

        return isSym(left, right);
    }

    bool isSym(TreeNode *l, TreeNode *r)
    {
        if(l== nullptr && r== nullptr)
            return true;
        if((l&&!r) || (!l&&r))
            return false;
        if(l->val == r->val)
            return isSym(l->left, r->right) && isSym(l->right, r->left);
    }
};
