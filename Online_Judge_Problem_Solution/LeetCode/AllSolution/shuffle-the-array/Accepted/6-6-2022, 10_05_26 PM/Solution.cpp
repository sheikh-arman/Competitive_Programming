// https://leetcode.com/problems/shuffle-the-array

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>V;
        for(int i=0;i<n;i++){
            V.push_back(nums[i]);
            V.push_back(nums[i+n]);
        }
        return V;
    }
};