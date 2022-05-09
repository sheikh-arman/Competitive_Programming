/*
    Sk arman Hossain
    University of Barisal

    Problem: 62. Unique Paths
    Solution : dp
 */
class Solution
{
public:
    int dp[300][300],N,M;
    int grid(int i,int j)
    {
        if(i>=N||j>=M)
        {
            return 0;
        }
        if(i==N-1&&j==M-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j]=grid(i+1,j)+grid(i,j+1);
    }
    int uniquePaths(int m, int n)
    {
        N=m;
        M=n;
        for(int i=0; i<=N; i++)
        {
            for(int j=0; j<=M; j++)
            {
                dp[i][j]=-1;
            }
        }
        int ans=grid(0,0);
        return ans;
    }
};
