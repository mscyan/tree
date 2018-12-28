//
// Created by yanch on 2018/11/27.
// leetcode 98 验证二叉搜索树
//

#ifndef TREE_ISVALIDBST_H
#define TREE_ISVALIDBST_H

#endif //TREE_ISVALIDBST_H
//#include "TreeStruct.h"
#include <vector>
using namespace std;
class IsValidBST
{
public:
    bool isValidBST(TreeNode *root)
    {
        vector<int> tv;
        if(root == NULL)
            return true;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while( !s.empty() || p )
        {
            while(p)
            {
                s.push(p);
                p = p->left;
            }

            if(!s.empty())
            {
                p = s.top();
                s.pop();
                tv.push_back(p->val);
                p = p->right;
            }
        }
        for(int i=0;i<tv.size()-1;i++)
            if(tv[i] >= tv[i+1])
                return false;
        return true;
    }
};