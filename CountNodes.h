//
// Created by yanchao on 2019/1/3.
// leetcode 222 完全二叉树的节点个数

#ifndef TREE_COUNTNODES_H
#define TREE_COUNTNODES_H

#endif //TREE_COUNTNODES_H
class CountNodes
{
public:
    int countNodes(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        int ll = getDepth(root->left);
        int rl = getDepth(root->right);
        if(ll == rl)
            return (1<<ll) + countNodes(root->right);
        else
            return (1<<rl) + countNodes(root->left);
    }
    //对于完全二叉树而言，不必左右遍历，只需要判断子节点即可获取高度。
    int getDepth(TreeNode *root)
    {
        int depth = 0;
        while(root)
        {
            depth ++;
            root = root->left;
        }
        return depth;
    }
};
