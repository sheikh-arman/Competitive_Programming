// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int mem[1010][110][3],n;
    vector<int>V;
    int dp(int i,int status,int k){
        if(i>=n){
            return 0;
        }
        if(mem[i][k][status]!=-1){
            return mem[i][k][status];
        }
        int ans=0;
        if(status){
            ans=dp(i+1,0,k)+V[i];
        }
        else{
            if(k>0){
                ans=dp(i+1,1,k-1)-V[i];
            }
        }
        ans=max(ans,dp(i+1,status,k));
        return mem[i][k][status]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        V=prices;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                for(int x=0;x<2;x++){
                    mem[i][j][x]=-1;
                }
            }
        }
        int ans=dp(0,0,k);
        return ans;
    }
};