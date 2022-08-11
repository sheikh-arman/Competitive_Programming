// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int last=lower_bound(nums.begin(),nums.end(),target+1)-nums.begin();
        int siz=nums.size();
        vector<int>ans;
        ans.push_back(-1);
        ans.push_back(-1);
        if(first<siz){
            if(nums[first]==target){
                ans[0]=first;
                ans[1]=last-1;
            }
        }
        return ans;
    }
};