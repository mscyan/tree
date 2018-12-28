//
// Created by yanch on 2018/11/18.
//

#ifndef TREE_TREESTRUCT_H
#define TREE_TREESTRUCT_H

#endif //TREE_TREESTRUCT_H
#include <iostream>
#include <stack>
// 树节点-二叉链表
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//树的三种遍历（递归与非递归两种方式）
//非递归解法讲的非常好的一篇博客
// https://blog.csdn.net/zgaoq/article/details/79089819

class Tree
{
public:
    void recursivePreOrderTree(TreeNode* root);
    void recursiveInOrderTree(TreeNode* root);
    void recursivePostOrderTree(TreeNode *root);

    void noRecursivePreOrderTree(TreeNode *root);
    void noRecursiveInOrderTree(TreeNode *root);
    void noRecursivePostOrderTree(TreeNode *root);

    std::stack<TreeNode*> preStack;
    std::stack<TreeNode*> inStack;
    std::stack<TreeNode*> postStack;
};
//先序遍历 递归
void Tree::recursivePreOrderTree(TreeNode *root) {
    if(root == NULL)
        return ;
    std::cout<<root->val<<" ";
    recursivePreOrderTree(root->left);
    recursivePreOrderTree(root->right);
}
//中序遍历 递归
void Tree::recursiveInOrderTree(TreeNode *root) {
    if(root == NULL)
        return ;
    recursiveInOrderTree(root->left);
    std::cout<<root->val<<" ";
    recursiveInOrderTree(root->right);
}
//后序遍历 递归
void Tree::recursivePostOrderTree(TreeNode *root) {
    if(root == NULL)
        return ;
    recursivePostOrderTree(root->left);
    recursivePostOrderTree(root->right);
    std::cout<<root->val<<" ";
}

//先序遍历 非递归
void Tree::noRecursivePreOrderTree(TreeNode *root) {
    // 用栈模拟 递归的执行过程
    if(root == nullptr)
        return;
    preStack.push(root);
    while(!preStack.empty())
    {
        TreeNode *tmp = preStack.top();
        std::cout<<tmp->val<<" ";
        preStack.pop();
        if(tmp->right != nullptr)
            preStack.push(tmp->right);
        if(tmp->left != nullptr)
            preStack.push(tmp->left);
    }
}

//中序遍历 非递归
void Tree::noRecursiveInOrderTree(TreeNode *root) {
    if(root == nullptr)
        return;
    TreeNode *p = root;
    while( !inStack.empty() || p)
    {
        while(p != nullptr)
        {
            inStack.push(p);
            p = p->left;
        }
        if( !inStack.empty())
        {
            p = inStack.top();
            inStack.pop();
            std::cout<<p->val<<"-";
            p = p->right;
        }
    }
}

//后序遍历 非递归
void Tree::noRecursivePostOrderTree(TreeNode *root) {
    if(root == nullptr)
        return;

//    TreeNode *p = root;
    postStack.push(root);
    TreeNode *cur = nullptr;
    TreeNode *pre = nullptr;
    while(!postStack.empty())
    {
        cur = postStack.top();
        if( ( cur->left == nullptr && cur->right == nullptr ) ||
                ( ( pre == cur->right || pre == cur->left) && pre ) )
        {
            std::cout<<cur->val<<" ";
            pre = cur;
            postStack.pop();
        }
        else
        {
            if(cur->right)
                postStack.push(cur->right);
            if(cur->left)
                postStack.push(cur->left);
        }
    }
}
