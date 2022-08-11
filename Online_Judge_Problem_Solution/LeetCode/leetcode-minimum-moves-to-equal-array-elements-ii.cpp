// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=n/2;
        int mid_val=nums[mid];
        if(n%2==0){
            mid_val=(nums[mid]+nums[mid-1])/2;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(mid_val-nums[i]);
        }
        return ans;
    }
};