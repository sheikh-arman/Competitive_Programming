// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    int mem[5010][1010][4],n;
    vector<int>V;
    int dp(int i,int last, int status){
        if(i>=n){
            return 0;
        }
        if(mem[i][last][status]!=-1){
            return mem[i][last][status];
        }
        int ans=0;
        if(status){
            if(V[i]>last){
                ans=dp(i+2,0,0)+(V[i]-last);
            }
        }
        else{
            ans=dp(i+1,V[i],1);
        }
        ans=max(ans,dp(i+1,last,status));
        return mem[i][last][status]=ans;
    }
    int maxProfit(vector<int>& prices) {
        V=prices;
        n=V.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=1000;j++){
                for(int k=0;k<2;k++){
                    mem[i][j][k]=-1;
                }
            }
        }
        int ans=dp(0,0,0);
        return ans;
    }
};