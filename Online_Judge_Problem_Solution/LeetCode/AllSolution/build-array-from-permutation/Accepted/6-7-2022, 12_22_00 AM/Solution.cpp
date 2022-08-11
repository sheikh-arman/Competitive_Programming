// https://leetcode.com/problems/build-array-from-permutation

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ar(n);
        for(int i=0;i<n;i++){
            ar[i]=nums[nums[i]];
        }
        return ar;
    }
};