// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int peak=0;
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=(left+right)/2;
            if(nums[mid]>nums[mid+1]){
                right=mid;
            }
            else{
                left=mid+1;
                peak=left;
            }
        }
        return peak;
    }
};