// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int mem[30010][4],n;
    vector<int>V;
    int dp(int i, int status){
        if(i>=n){
            return 0;
        }
        if(mem[i][status]!=-1){
            return mem[i][status];
        }
        int ans=INT_MIN;
        if(status){
               ans=dp(i+1,0)+V[i];
        }
        else{
            ans=dp(i+1,1)-V[i];
        }
        ans=max(ans,dp(i+1,status));
        return mem[i][status]=ans;
    }
    int maxProfit(vector<int>& prices) {
        V=prices;
        n=V.size();
        int ma=0;
        for(int i:prices){
            ma=max(ma,i);
        }
        for(int i=0;i<=n;i++){
           
                for(int k=0;k<2;k++){
                    mem[i][k]=-1;
                }
            
        }
        int ans=dp(0,0);
        return ans;
    }
};