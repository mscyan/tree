//
// Created by yanchao on 2018/12/28.
// leetcode 230 二叉搜索树中的第k小的元素

#ifndef TREE_KTHSMALLEST_H
#define TREE_KTHSMALLEST_H

#endif //TREE_KTHSMALLEST_H
class KthSmallest
{
public:
    // k总是有效的，无需判断k是否无效
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> v;
        TreeNode *p = root;
        stack<TreeNode*> inStack;
        while(!inStack.empty() || p)
        {
            while(p)
            {
                inStack.push(p);
                p = p->left;
            }
            if(!inStack.empty())
            {
                TreeNode *tmp = inStack.top();
                v.push_back(tmp->val);
                inStack.pop();
                p = tmp->right;
            }
        }
        for(int i : v)
        {
            cout<<i<<" ";
        }
        return v[k-1];
    }

    int kthSmallest2(TreeNode *root, int k)
    {
        TreeNode *p = root;
        stack<TreeNode *> inStack;
        int count = 1;
        while( !inStack.empty() || p)
        {
            while(p)
            {
                inStack.push(p);
                p = p->left;
            }
            if(!inStack.empty())
            {
                TreeNode *t = inStack.top();
                if(k == count)
                    return t->val;
                count ++;
                p = t->right;
                inStack.pop();
            }
        }
    }
};