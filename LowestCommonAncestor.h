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

    TreeNode *noRecursiveToLCA(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        //todo 能否用非递归的方式，求得本题的解？
        //后序遍历，左右根，

        return nullptr;
    }

    stack<TreeNode *> findNode(TreeNode *root, TreeNode *p)
    {
        TreeNode *flag = nullptr;
        stack<TreeNode *> postStack;
        stack<TreeNode *> listStack;
        postStack.push(root);
        TreeNode *cur = nullptr;
        TreeNode *pre = nullptr;
        while(!postStack.empty())
        {
            cur = postStack.top();
            //如果是叶子节点
            if(( cur->left == nullptr && cur->right == nullptr ) ||
               ( ( pre == cur->right || pre == cur->left) && pre ))
            {
                if(!cur->left && !cur->right)
                {
                    if(cur->val == p->val)
                    {
                        flag = cur;
                        listStack.push(flag);
                    }
                    postStack.pop();
                    pre = cur;
                }
                    //如果左右节点皆已遍历过
                else if(pre && (cur->left == pre || cur->right == pre))
                {
                    if(flag == cur->left)
                    {
                        flag = cur;
                        listStack.push(flag);
                    }
                    if(flag == cur->right)
                    {
                        flag = cur;
                        listStack.push(flag);
                    }
                    postStack.pop();
                    pre = cur;
                }
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
        return listStack;
    }
};