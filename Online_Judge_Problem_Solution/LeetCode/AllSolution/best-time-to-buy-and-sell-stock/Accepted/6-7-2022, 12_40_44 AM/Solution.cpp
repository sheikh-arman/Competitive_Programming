// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int dp[n];
        dp[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i]=max(prices[i],dp[i+1]);
        }
        for(int i=0;i<n-1;i++){
            ans=max(ans,dp[i+1]-prices[i]);
        }
        return ans;
    }
};