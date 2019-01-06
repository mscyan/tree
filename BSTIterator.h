//
// Created by yanchao on 2019/1/6.
// leetcode 173 二叉搜索树迭代器

#ifndef TREE_BSTITERATOR_H
#define TREE_BSTITERATOR_H

#endif //TREE_BSTITERATOR_H
#include <queue>
class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        tree = root;

        //中序遍历，得到队列;
        stack<TreeNode *> inStack;
        TreeNode *p = root;
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
                nodeQueue.push(p->val);
                p = p->right;
            }
        }
    }

    int next()
    {
        if(hasNext())
        {
            int tmp = nodeQueue.front();
            nodeQueue.pop();
            return tmp;
        }
        else
        {
            return 0;
        }
    }

    bool hasNext()
    {
        return !nodeQueue.empty();
    }
private:
    TreeNode *tree;
    queue<int> nodeQueue;
};

class BSTIterator2
{
public:
    BSTIterator2(TreeNode *root)
    {
        p = root;
        while(p)
        {
            inStack.push(p);
            p = p->left;
        }
    }

    int next()
    {
        TreeNode *tmp = inStack.top();
        inStack.pop();

        TreeNode *right = tmp->right;
        while(right)
        {
            inStack.push(right);
            right = right->left;
        }

        return tmp->val;
    }

    bool hasNext()
    {
        return !inStack.empty();
    }
private:
    stack<TreeNode *> inStack;
    int value = 0;
    TreeNode *p;
};

//两种解法，或者说是两种方案

//一种是构造函数执行时，就执行中序遍历算法，得到对应的队列，
// 后续进行next操作时，本质上是对队列进行操作；
// 实际：leetcode结果仅击败了1%的用户，原因在于算法1是构造
// 函数中执行中序算法，但本题中肯定有并未遍历完全的情况，等
// 于说我浪费了很多的时间，所以需要将时间复杂度均摊，这样在解
// 题时效率更高，实际的使用中，也肯定会更快！

//另一种构造函数只初始化tree字段，每次执行next的时候再执行
// 一步中序，并非完全执行，这样执行中序遍历的时间等于说是均摊了
// 均摊算法1 失败，通过率61/62，预测是由于多调用了hasNext，
// 导致了多余的遍历计算，使得结果不一样；
// 实际：leetcode中击败10%的用户，待优化算法；
