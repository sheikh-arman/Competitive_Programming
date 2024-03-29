// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int siz=nums.size();
        int ans=0;
        for(int i=0;i<siz;i++){
            if(nums[i]==i||nums[i]<0||nums[i]>siz)continue;
            while(nums[i]>=0&&nums[i]<siz&&nums[i]!=nums[nums[i]]){
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