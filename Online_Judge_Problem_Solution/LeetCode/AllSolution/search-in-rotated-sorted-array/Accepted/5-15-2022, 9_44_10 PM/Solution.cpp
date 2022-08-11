// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pos=-1,pivot=0;
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]>=nums[0]){
                left=mid+1;
            }
            else{
                pivot=mid;
                right=mid-1;
            }
        }
       // cout<<pivot<<" t\n";
        left=0;right=pivot-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                pos=mid;break;
            }
            if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        left=pivot;right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                pos=mid;break;
            }
            if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return pos;
    }
};