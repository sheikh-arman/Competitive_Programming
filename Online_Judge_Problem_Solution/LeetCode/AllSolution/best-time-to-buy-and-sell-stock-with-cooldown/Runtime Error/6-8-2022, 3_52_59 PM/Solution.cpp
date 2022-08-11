// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    int mem[5010][4][4],n;
    vector<int>V;
    int dp(int i, int last, int status){
        if(i>=n){
            return 0;
        }
        if(mem[i][last][status]!=-1){
            return mem[i][last][status];
        }
        int ans=INT_MIN;
        if(status){
               ans=dp(i+2,0,0)+V[i];
        }
        else{
            ans=dp(i+1,V[i],1)-V[i];
        }
        ans=max(ans,dp(i+1,last,status));
        return mem[i][last][status]=ans;
    }
    int maxProfit(vector<int>& prices) {
        V=prices;
        n=V.size();
        int ma=0;
        for(int i:prices){
            ma=max(ma,i);
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=2;j++){
                for(int k=0;k<2;k++){
                    mem[i][j][k]=-1;
                }
            }
        }
        int ans=dp(0,0,0);
        return ans;
    }
};