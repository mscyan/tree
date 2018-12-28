//
// Created by yanchao on 2018/12/28.
// leetcode 104 二叉树的最大深度

#ifndef TREE_MAXDEPTH_H
#define TREE_MAXDEPTH_H

#endif //TREE_MAXDEPTH_H

class MaxDepth
{
public:
    int maxDepth(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        int len = 0;
        stack<TreeNode *> nodeStack;
        nodeStack.push(root);
        while(!nodeStack.empty())
        {
            len ++;
            stack<TreeNode*> tmpStack;
            while(!nodeStack.empty())
            {
                TreeNode *t = nodeStack.top();
                if(t->left)
                    tmpStack.push(t->left);
                if(t->right)
                    tmpStack.push(t->right);
                nodeStack.pop();
            }
            nodeStack = tmpStack;
        }
        return len;
    }
    int  getDepth(TreeNode *root);

};
int MaxDepth::getDepth(TreeNode *root)
{
    if(root == nullptr)
        return 0;
    int l = getDepth(root->left);
    int r = getDepth(root->right);
    return (l > r ? l : r ) + 1;
}
