#include <iostream>
#include "TreeStruct.h"
#include "IsValidBST.h"                 //  leetcode 98  验证二叉搜索树
#include "IsSymmetric.h"                //  leetcode 101 对称二叉树
#include "LevelOrder.h"                 //  leetcode 102 二叉树的层次遍历
#include "MaxDepth.h"                   //  leetcode 104 二叉树的最大深度
#include "IsBalance.h"                  //  leetcode 110 是否是平衡二叉树
#include "InvertTree.h"                 //  leetcode 226 翻转二叉树
#include "LowestCommonAncester.h"       //  leetcode 235 二叉搜索树的最近公共祖先
#include "KthSmallest.h"                //  leetcode 230 二叉搜索树中第k小的元素
#include "LowestCommonAncestor.h"       //  leetcode 236 二叉树的最近公共祖先
#include "RightSideView.h"              //  leetcode 199 二叉树的右视图
#include "CountNodes.h"                 //  leetcode 222 完全二叉树的节点个数
#include "RecoverTree.h"                //  leetcode 99  恢复二叉搜索树
#include "NumTrees.h"                   //  leetcode 96  不同的二叉搜索树
#include "BSTIterator.h"                //  leetcode 173 二叉搜索树迭代器
#include "MinDepth.h"                   //  leetcode 111 二叉树的最小深度
#include "SumNumbers.h"                 //  leetcode 129 求根到叶子节点数字之和
#include "BinaryTreePaths.h"            //  leetcode 257 二叉树的所有路径
#include "RobTree.h"                    //  leetcode 337 打家劫舍 III
//#include "BuildTree.h"                  //  leetcode 105 先序+中序 -> 构造二叉树
#include "Trie.h"                       //  leetcode 208 前缀树
using namespace std;
#include <string>
#include <vector>
int main()
{
     TreeNode *root = new TreeNode(3);

     TreeNode *rl = new TreeNode(2);
     root->left = rl;
     TreeNode *rr = new TreeNode(3);
     root->right = rr;

//     TreeNode *rll = new TreeNode(1);
//     rl->left = rll;
     TreeNode *rlr = new TreeNode(3);
     rl->right = rlr;

//     TreeNode *rrl = new TreeNode(8);
//     rr->left = rrl;
     TreeNode *rrr = new TreeNode(1);
     rr->right = rrr;

//     TreeNode *rrll = new TreeNode(7);
//     rrl->left = rrll;
//     TreeNode *rrlr = new TreeNode(56);
//     rrl->right = rrlr;
//
//     TreeNode *rrrl = new TreeNode(9);
//     rrr->left = rrrl;
//     TreeNode *rrrr = new TreeNode(6);
//     rrr->right = rrrr;

//     IsValidBST so;
//     cout<<so.isValidBST(root);

//     IsSymmetric so;
//     cout<<so.isSymmetric(root);

//     LevelOrder so;
//     auto vecs = so.levelOrder(root);
//     for(const vector<int> &v : vecs)
//     {
//          for (int i : v) {
//               cout<< i <<" ";
//          }
//          cout<<endl;
//     }

//    MaxDepth so;
//    cout<<so.maxDepth(root)<<endl;
//    cout<<so.getDepth(root);

//     IsBalanced so;
//     cout<<so.isBalanced(root);

//     InvertTree so;
//     Tree tree;
//     tree.recursiveInOrderTree(root);
//     cout<<endl;
//     TreeNode *t = so.invertTree(root);
//     tree.recursiveInOrderTree(t);

//     KthSmallest so;
//     cout<<so.kthSmallest2(root, 3);

//     LowestCommonAncestor1 so;
////     TreeNode *p = new TreeNode(5);
////     TreeNode *q = new TreeNode(6);
////     TreeNode *r = so.lowestCommonAncestor1(root, p, q);
////     cout<<r->val<<" ";
//     Tree t;
//     TreeNode *ro = t.stringToTreeNode("[3,5,1,6,2,0,8,null,null,7,4]");
////     t.recursiveInOrderTree(ro);
//
//     TreeNode *p = new TreeNode(5);
//     TreeNode *q = new TreeNode(4);
//     TreeNode *r = so.lowestCommonAncestor1(ro, p, q);
//     cout<<r->val<<" ";

//     RightSideView so;
//     auto result = so.rightSideView(root);
//     for(int i=0;i<result.size();i++)
//     {
//          cout<<result[i]<<" ";
//     }

//     CountNodes so;
//     cout<<so.countNodes(root);

//     RecoverTree so;
//     Tree t;
//     t.noRecursiveInOrderTree(root);
//     cout<<endl;
//     so.recoverTree2(root);
//     t.noRecursiveInOrderTree(root);

//     NumTrees so;
//     cout<<so.numTrees(4)<<endl;

//    BSTIterator2 *so = new BSTIterator2(root);
//    while(so->hasNext())
//    {
//         cout<<so->next()<<" ";
//    }


//     TreeNode *r = new TreeNode(1);
//     TreeNode *l = new TreeNode(5);
//     r->right = l;
//     MinDepth so;
//     cout<<so.minDepth(r)<<endl;

//     SumNumbers so;
//     cout<<so.sumNumbers(root);


//     cout<<char(50)<<endl;
//     string s = "";
//     s += char(50);
//     cout<<s<<endl;
//     BinaryTreePaths so;
//     auto rv = so.binaryTreePaths(root);
//     cout<<rv[0]<<endl;
//     cout<<rv[1];


//     RobTree so;
//     cout<<so.robTree(root);

    //todo 构造二叉树

    Trie so;
//    so.insert("hello");
    so.insert("aple");
//    so.insert("application");
//    cout<<so.startsWith("hel")<<endl;
//    cout<<so.startsWith("as")<<endl;
//    cout<<so.startsWith("applica")<<endl;
//    cout<<so.startsWith("helloworld")<<endl;
//    cout<<so.startsWith("hello")<<endl;
//    cout<<so.startsWith("hellow")<<endl;
//    cout<<so.search("hello")<<endl;
//    cout<<so.search("hell")<<endl;
    so.insert("ap");
//    cout<<so.startsWith("app")<<endl;
    cout<<so.search("ap")<<endl;



//    Tree t;
//    t.recursivePreOrderTree(root);
//    cout<<endl;
//    t.recursiveInOrderTree(root);
//    cout<<endl;
//    t.recursivePostOrderTree(root);
//    cout<<endl;


//    t.noRecursivePreOrderTree(root);
//    cout<<endl;
//    t.noRecursiveInOrderTree(root);
//    cout<<endl;
//    t.noRecursivePostOrderTree(root);
//    cout<<endl;
    return 0;
}