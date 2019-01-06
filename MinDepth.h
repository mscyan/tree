//
// Created by yanchao on 2019/1/6.
//

#ifndef TREE_MINDEPTH_H
#define TREE_MINDEPTH_H

#endif //TREE_MINDEPTH_H
class MinDepth
{
public:
    int minDepth(TreeNode *root)
    {
        int r = 0;
        if(root == nullptr)
            return 0;

        if(root->left)
        {
            r = minDepth(root->left);
        }
        if(root->right)
        {
            int t = minDepth(root->right);
            if(r == 0)
                r = t;
            else
                r = t < r ? t : r;
        }
        return r + 1;
    }
};