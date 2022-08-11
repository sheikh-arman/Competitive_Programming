// https://leetcode.com/problems/paint-house-iii

class Solution {
public:
    int dp[101][101][21];
    
    int solve(int i,int t,int pre, vector<int>& house, vector<vector<int>>& cost){

        if(i>=cost.size()&&t==0)return 0;
        if((i>=cost.size()&&t!=0)||t<0||i>=cost.size())return INT_MAX;
        if(dp[i][t][pre]!=-1)return dp[i][t][pre];
        
        if(house[i]!=0){
            if(pre!=house[i])return dp[i][t][pre]=solve(i+1,t-1,house[i],house,cost);
            else return dp[i][t][pre]=solve(i+1,t,house[i],house,cost);
        }
        
        int a=INT_MAX,b=INT_MAX;
        if(t>0){
            for(int j=0;j<cost[0].size();j++){
                if(j+1!=pre){
                    int x=solve(i+1,t-1,j+1,house,cost);
                    if(x!=INT_MAX)x+=cost[i][j];
                    a=min(a,x);
                }
            }
        }

        b=solve(i+1,t,pre,house,cost);
        if(b!=INT_MAX)b+=cost[i][pre-1];
        
        
        return dp[i][t][pre]=min(a,b);
    }
    int minCost(vector<int>& house, vector<vector<int>>& cost, int m, int n, int target) {
        
        memset(dp,-1,sizeof(dp));
        int ans=INT_MAX;
        
        if(house[0]!=0){
            ans=solve(1,target-1,house[0],house,cost);
        }
        else{
            for(int j=0;j<cost[0].size();j++){
                int x=solve(1,target-1,j+1,house,cost);
                if(x!=INT_MAX)x+=cost[0][j];
                ans=min(ans,x);
            }
        }

        if(ans==INT_MAX)ans=-1;
        return ans;
        
    }
};