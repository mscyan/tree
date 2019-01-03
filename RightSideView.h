//
// Created by yanchao on 2019/1/3.
// leetcode 199 二叉树的右视图

#ifndef TREE_RIGHTSIDEVIEW_H
#define TREE_RIGHTSIDEVIEW_H

#endif //TREE_RIGHTSIDEVIEW_H
class RightSideView
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> r;
        if(root == nullptr)
            return r;
        stack<TreeNode *> nodes;
        nodes.push(root);
        while(!nodes.empty())
        {
            stack<TreeNode *> tmp;
            while(!nodes.empty())
            {
                tmp.push(nodes.top());
                nodes.pop();
            }
            r.push_back(tmp.top()->val);
            while(!tmp.empty())
            {
                TreeNode *t = tmp.top();
                if(t->right)
                    nodes.push(t->right);
                if(t->left)
                    nodes.push(t->left);
                tmp.pop();
            }
        }

        return r;
    }
};
