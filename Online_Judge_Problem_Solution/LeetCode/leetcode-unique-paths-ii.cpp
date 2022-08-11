// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int dp[101][101],N,M;
    int grid(int i,int j,vector<vector<int>>& obstacleGrid)
    {
        if(i>=N||j>=M)
        {
            return 0;
        }
        if(obstacleGrid[i][j]==1)return 0;
        if(i==N-1&&j==M-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j]=grid(i+1,j,obstacleGrid)+grid(i,j+1,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        N=obstacleGrid.size();
        M=obstacleGrid[0].size();
        for(int i=0; i<=N; i++)
        {
            for(int j=0; j<=M; j++)
            {
                dp[i][j]=-1;
            }
        }
        int ans=grid(0,0,obstacleGrid);
        return ans;
    }
};