// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int siz=nums.size();
        int ans=0;
        for(int i=0;i<siz;i++){
            if(nums[i]==i)continue;
            while(nums[i]<siz&&nums[i]!=nums[nums[i]]){
                swap(nums[i],nums[nums[i]]);
            }
        }
        while(ans<siz){
            if(nums[ans]==ans){
                ans++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};