// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int pos2=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        vector<int>V;
        if(pos>=nums.size()){
            V.push_back(-1);
            V.push_back(-1);
        }
        else{
            if(nums[pos]==target){
                V.push_back(pos);
                V.push_back(pos2-1);
            }
            else{
                V.push_back(-1);
                V.push_back(-1);
            }
        }
        return V;
    }
};