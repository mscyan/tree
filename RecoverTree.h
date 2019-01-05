//
// Created by yanchao on 2019/1/3.
// leetcode 99 恢复二叉搜索树

#ifndef TREE_RECOVERTREE_H
#define TREE_RECOVERTREE_H

#endif //TREE_RECOVERTREE_H
#include <algorithm>
class RecoverTree
{
public:
    TreeNode *recoverTree(TreeNode *root)
    {
        if(root== nullptr)
            return nullptr;

        //中序遍历二叉树
        stack<TreeNode *> inStack;
        TreeNode *p = root;
        int cur = 0;
        int pre = -2147483647;
        vector<int> orderedVector;
        while(!inStack.empty() || p)
        {
            while(p)
            {
                inStack.push(p);
                p = p->left;
            }
            if(!inStack.empty())
            {
                p = inStack.top();
                inStack.pop();
                orderedVector.push_back(p->val);
                p = p->right;
            }
        }
        sort(orderedVector.begin(), orderedVector.end());
        auto it = 0;
        p = root;
        while(!inStack.empty() || p)
        {
            while(p)
            {
                inStack.push(p);
                p = p->left;
            }
            if(!inStack.empty())
            {
                p = inStack.top();
                inStack.pop();
                p->val = orderedVector[it++];
//                cout<<p->val<<" ";
                p = p->right;
            }
        }
        return root;
    }

    TreeNode *recoverTree2(TreeNode *root)
    {
        if(root == nullptr)
            return nullptr;

        TreeNode *p = root;
        vector<TreeNode*> nodes;
        stack<TreeNode *> inStack;

        while(!inStack.empty() || p)
        {
            while(p)
            {
                inStack.push(p);
                p = p->left;
            }
            if(!inStack.empty())
            {
                p = inStack.top();
                inStack.pop();
                nodes.push_back(p);
                p = p->right;
            }
        }
        TreeNode *node1 = nullptr;
        TreeNode *node2 = nullptr;
        for(int i=0;i<nodes.size()-1;i++)
        {
            if(nodes[i]->val > nodes[i+1]->val)
            {
                node1 = nodes[i];
                break;
            }
        }
        for(int i=(nodes.size()-1);i>=1;i--)
        {
            if(nodes[i]->val < nodes[i-1]->val)
            {
                node2 = nodes[i];
                break;
            }
        }
        cout<<endl<<node1->val<<" "<<node2->val<<endl;
        int tmp = node1->val;
        node1->val = node2->val;
        node2->val = tmp;

        return root;
    }
};
//注意审题：只有两个节点位置是错误的，并非是恢复整棵树；