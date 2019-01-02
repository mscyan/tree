//
// Created by yanch on 2018/11/18.
//

#ifndef TREE_TREESTRUCT_H
#define TREE_TREESTRUCT_H

#endif //TREE_TREESTRUCT_H
#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
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
//private:
    void trimLeftTrailingSpaces(string &input) {
        input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
            return !isspace(ch);
        }));
    }

    void trimRightTrailingSpaces(string &input) {
        input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
            return !isspace(ch);
        }).base(), input.end());
    }

    TreeNode* stringToTreeNode(string input) {
        trimLeftTrailingSpaces(input);
        trimRightTrailingSpaces(input);
        input = input.substr(1, input.length() - 2);
        if (!input.size()) {
            return nullptr;
        }

        string item;
        stringstream ss;
        ss.str(input);

        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (true) {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();

            if (!getline(ss, item, ',')) {
                break;
            }

            trimLeftTrailingSpaces(item);
            if (item != "null") {
                int leftNumber = stoi(item);
                node->left = new TreeNode(leftNumber);
                nodeQueue.push(node->left);
            }

            if (!getline(ss, item, ',')) {
                break;
            }

            trimLeftTrailingSpaces(item);
            if (item != "null") {
                int rightNumber = stoi(item);
                node->right = new TreeNode(rightNumber);
                nodeQueue.push(node->right);
            }
        }
        return root;
    }

    string treeNodeToString(TreeNode* root) {
        if (root == nullptr) {
            return "[]";
        }

        string output = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                output += "null, ";
                continue;
            }

            output += to_string(node->val) + ", ";
            q.push(node->left);
            q.push(node->right);
        }
        return "[" + output.substr(0, output.length() - 2) + "]";
    }
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


//int main() {
//    string line;
//    while (getline(cin, line)) {
//        TreeNode* root = stringToTreeNode(line);
//        getline(cin, line);
//        TreeNode* p = stringToTreeNode(line);
//        getline(cin, line);
//        TreeNode* q = stringToTreeNode(line);
//
//        TreeNode* ret = Solution().lowestCommonAncestor(root, p, q);
//
//        string out = treeNodeToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}
//[3,5,1,6,2,0,8,null,null,7,4]