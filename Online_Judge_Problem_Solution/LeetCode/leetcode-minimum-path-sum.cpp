// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int dp[202][202],N,M;
    int grids(int i,int j,vector<vector<int>>& grid)
    {
        if(i>=N||j>=M)
        {
            return INT_MAX;
        }
        if(i==N-1&&j==M-1)
        {
            return grid[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j]=min(grids(i+1,j,grid),grids(i,j+1,grid))+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        N=grid.size();
        M=grid[0].size();
        for(int i=0; i<=N; i++)
        {
            for(int j=0; j<=M; j++)
            {
                dp[i][j]=-1;
            }
        }
        int ans=grids(0,0,grid);
        return ans;
    }
};