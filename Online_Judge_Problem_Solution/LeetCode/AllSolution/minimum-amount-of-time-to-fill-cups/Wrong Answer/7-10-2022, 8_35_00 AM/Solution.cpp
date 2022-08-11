// https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups

class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(),amount.end());
        int ans=amount[0];
        amount[2]-=ans;
        int mi=min(amount[1],amount[2]);
        ans+=mi;
        amount[1]-=mi;
        amount[2]-=mi;
        ans+=amount[1];
        ans+=amount[2];
        return ans;
    }
};