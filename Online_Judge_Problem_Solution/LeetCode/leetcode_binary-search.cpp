
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len=nums.size();
        int left=0,right=len-1;
        int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                ans=mid;break;
            }
            if(nums[mid]>target){
                right=mid-1;
            }   
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};