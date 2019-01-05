//
// Created by yanchao on 2019/1/5.
// leetcode 96 不同的二叉搜索树

#ifndef TREE_NUMTREES_H
#define TREE_NUMTREES_H

#endif //TREE_NUMTREES_H
class NumTrees
{
public:
    int numTrees(int n)
    {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;

        int dp[n+1];
        for(int i=0;i<n+1;i++)
        {
            dp[i] = 0;
        }
        dp[1] = 1;
        dp[0] = 1;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i] = dp[i] + dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};