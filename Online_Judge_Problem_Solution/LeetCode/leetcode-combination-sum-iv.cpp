// https://leetcode.com/problems/combination-sum-iv

class Solution {
public:
    int mem[1010];
    int dp(int n,vector<int>& nums){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(mem[n]!=-1){
            return mem[n];
        }
        int ans=0;
        int siz=nums.size();
        for(int i=0;i<siz;i++){
            ans+=dp(n-nums[i],nums);
        }
        return mem[n]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        for(int i=0;i<=1000;i++){
            mem[i]=-1;
        }
        int ans=dp(target,nums);
        return  ans;
    }
};