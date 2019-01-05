//
// Created by yanchao on 2019/1/5.
// leetcode 96 不同的二叉搜索树

#ifndef TREE_NUMTREES_H
#define TREE_NUMTREES_H

#endif //TREE_NUMTREES_H
class NumTrees
{
public:
    vector<int> t = {0,1};
    int numTrees(int n)
    {
        if(n == 0)
            return 1;
        if(n == 1)
            return 1;

        else
        {
            if(n >= t.size())
            {
                int count = 0;
                for(int i=0;i<n;i++)
                {
                    count += (numTrees(i) * numTrees(n-1-i));
                }
                t.push_back(count);
                return count;
            }
            else
            {
                return t[n];
            }
        }
    }
};
//要点：一棵树根节点确定的情况下，可能的形态数量 应该是左右子树的个数相乘