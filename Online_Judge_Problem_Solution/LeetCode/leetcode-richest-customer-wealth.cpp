// https://leetcode.com/problems/richest-customer-wealth

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        int n=accounts.size();
        for(int i=0;i<n;i++){
            int tm=0;
            for(int j:accounts[i]){
                tm+=j;
            }
            ans=max(ans,tm);
        }
        return ans;
    }
};