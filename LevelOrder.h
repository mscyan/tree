//
// Created by yanchao on 2018/12/27.
//

#ifndef TREE_LEVELORDER_H
#define TREE_LEVELORDER_H

#endif //TREE_LEVELORDER_H

#include <vector>
using namespace std;
#include <algorithm>
class LevelOrder
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int> > rv;
        if(root==nullptr)
            return rv;
        stack<TreeNode *> nodeStack;
        nodeStack.push(root);
        bool flag = true;
        while(!nodeStack.empty())
        {
            vector<int> r;
            stack<TreeNode *> tmpStack;
            while(!nodeStack.empty())
            {
                r.push_back(nodeStack.top()->val);

                if(nodeStack.top()->left)
                    tmpStack.push(nodeStack.top()->left);
                if(nodeStack.top()->right)
                    tmpStack.push(nodeStack.top()->right);
                nodeStack.pop();
            }
            if(!flag)
            {
                reverse(r.begin(), r.end());
            }
            rv.push_back(r);
            while(!tmpStack.empty())
            {
                nodeStack.push(tmpStack.top());
                tmpStack.pop();
            }
            flag = !flag;
        }
        return rv;
    }
};
