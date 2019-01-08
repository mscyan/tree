//
// Created by yanchao on 2019/1/7.
// leetcode 105 先/后序+中序 -> 构造二叉树

#ifndef TREE_BUILDTREE_H
#define TREE_BUILDTREE_H

#endif //TREE_BUILDTREE_H
class BuildTree
{
public:
    //先序+中序->二叉树
    TreeNode *buildTree1(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *root = nullptr;
        if(preorder.empty())
            return root;
        if(preorder.size() == 1)
        {
            root = new TreeNode(preorder[0]);
            return root;
        }
        int val = preorder[0];
        int rootIndex = 0;
        root = new TreeNode(val);
        for(int i=0;i<inorder.size();i++)
        {
            if(val == inorder[i])
            {
                rootIndex = i;
                break;
            }
        }
        vector<int> preVrder;
        for(int i=rootIndex+1;i<preorder.size();i++)
        {
            preVrder.push_back(preorder[i]);
        }
        vector<int> inVrder;
        for(int i=rootIndex+1;i<preorder.size();i++)
        {
            inVrder.push_back(inorder[i]);
        }
        root->right = buildTree1(preVrder, inVrder);

        vector<int> preVrder2;
        for(int i=0;i<rootIndex;i++)
        {
            preVrder2.push_back(preorder[i+1]);
        }
        vector<int> inVrder2;
        for(int i=0;i<rootIndex;i++)
        {
            inVrder2.push_back(inorder[i]);
        }
        root->left = buildTree1(preVrder2, inVrder2);
        return root;
    }

    TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder)
    {
        TreeNode *root = nullptr;
        if(inorder.size() == 0)
            return root;
        if(inorder.size() == 1)
        {
            root = new TreeNode(inorder[0]);
            return root;
        }

        //求得中序序列中 根节点的index
        int val = postorder[postorder.size()-1];
        root = new TreeNode(val);
        int rootIndex = 0;
        for(int i=0;i<inorder.size();i++)
        {
            if(val == inorder[i])
            {
                rootIndex = i;
                break;
            }
        }
        //初始化左序列和右序列
        vector<int> inVrder;
        vector<int> postVrder;
        for(int i=0;i<rootIndex;i++)
        {
            inVrder.push_back(inorder[i]);
        }
        for(int i=0;i<rootIndex;i++)
        {
            postVrder.push_back(postorder[i]);
        }

        vector<int> inVrder2;
        vector<int> postVrder2;
        for(int i=rootIndex+1;i<inorder.size();i++)
        {
            inVrder2.push_back(inorder[i]);
        }
        for(int i=rootIndex+1;i<inorder.size();i++)
        {
            postVrder2.push_back(postorder[i-1]);
        }

        root->left = buildTree2(inVrder, postVrder);
        root->right = buildTree2(inVrder2, postVrder2);
        return root;
    }
};

//先序和中序 唯一判断一棵二叉树
//待续...

//疑问：为何仅有先序+中序以及后序+中序才可以确定一棵二叉树
//先序的第一个节点是根节点，后序的最后一个节点是根节点，
//中序可以根据以上根节点，确定左子树和右子树
//如果仅有先序和后序，不能唯一确定，因为无法确定根节点
//比如先序1 2 3 后序 3 2 1，可以确定2棵以上的二叉树，显然不能唯一确定
