// https://leetcode.com/problems/maximum-difference-between-increasing-elements

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
        int ar[n];
        int ma=0;
        for(int i=n-1;i>=0;i--){
            ma=max(ma,nums[i]);
            ar[i]=ma;
        }
        int mi=INT_MAX;
        for(int i=0;i<n-1;i++){
            mi=min(mi,nums[i]);
            ans=max(ans,ar[i+1]-mi);
        }
        if(ans<=0)ans=-1;
        return ans;
    }
};