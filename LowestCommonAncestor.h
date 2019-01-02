//
// Created by yanchao on 2018/12/28.
// leetcode 236 二叉树的最近公共祖先
// 区别于235，本题中非二叉搜索树

#ifndef TREE_LOWESTCOMMONANCESTOR_H
#define TREE_LOWESTCOMMONANCESTOR_H

#endif //TREE_LOWESTCOMMONANCESTOR_H
class LowestCommonAncestor1
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == nullptr)
            return root;
        if(root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        return left && right ? root : left == nullptr ? right : left;
    }

    //非递归求解过程
    TreeNode *lowestCommonAncestor1(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == nullptr)
            return root;
        if(root == p || root == q)
            return root;

        TreeNode *r = nullptr;
        stack<TreeNode *> pList = noRecursiveToGetList(root, p);
        stack<TreeNode *> qList = noRecursiveToGetList(root, q);
        while(!pList.empty() && !qList.empty())
        {
            if(pList.top() == qList.top())
            {
                r = pList.top();
                pList.pop();
                qList.pop();
            }
            else if(pList.size() > 0 && qList.size() > 0  && pList.top() != qList.top())
            {
                break;
            }
        }
        return r;
    }
private:
    stack<TreeNode*> noRecursiveToGetList(TreeNode *root, TreeNode *targetNode)
    {
        //todo 能否用非递归的方式，求得本题的解？
        stack<TreeNode*> nodes;
        TreeNode *pre = nullptr;
        TreeNode *cur = nullptr;
        stack<TreeNode*> postStack;
        postStack.push(root);
        TreeNode *flag = nullptr;

        while(!postStack.empty())
        {
            cur = postStack.top();
            //如果是叶子节点
            if(cur->left == nullptr && cur->right == nullptr)
            {
                if(cur->val == targetNode->val)
                {
                    //找到了这个节点，从此节点开始返回
                    nodes.push(cur);
                    flag = cur;
                }
                postStack.pop();
                pre = cur;
            }
                //如果左右节点皆已访问过
            else if(pre && (pre == cur->left || pre == cur->right))
            {
                if(cur->val == targetNode->val)
                {
                    flag = cur;
                    nodes.push(flag);
                }
                if(flag == cur->left && flag != nullptr)
                {
                    flag = cur;
                    nodes.push(flag);
                }
                if(flag == cur->right && flag != nullptr)
                {
                    flag = cur;
                    nodes.push(flag);
                }
                postStack.pop();
                pre = cur;
            }
                //
            else
            {
                if(cur->right)
                    postStack.push(cur->right);
                if(cur->left)
                    postStack.push(cur->left);
            }
        }

        return nodes;
    }
};