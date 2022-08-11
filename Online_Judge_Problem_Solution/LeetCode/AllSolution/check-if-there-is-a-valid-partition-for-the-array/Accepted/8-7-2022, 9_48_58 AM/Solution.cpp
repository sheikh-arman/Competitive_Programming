// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array

class Solution {
public:
    int n;
    int mem[100010];
    bool dp(int i,vector<int>& nums){
        if(i>=n){
            return 1;
        }
        if(mem[i]!=-1){
            return (bool)mem[i];
        }
        bool ans=0;
        if(n-i>2){
            if(nums[i]==nums[i+1]&&nums[i]==nums[i+2]){
                ans|=dp(i+3,nums);
            }
            else if(nums[i]==nums[i+1]-1&&nums[i]==nums[i+2]-2){
                ans|=dp(i+3,nums);
            }
        }
        if(n-i>=2){
            if(nums[i]==nums[i+1]){
                ans|=dp(i+2,nums);
            }
        }
        return mem[i]=(int)ans;
    }
    bool validPartition(vector<int>& nums) {
        n=nums.size();
        for(int i=0;i<=n;i++){
            mem[i]=-1;
        }
        bool ans=dp(0,nums);
        return ans;
    }
};
// 4 4 4 5 6 6 6
//[579611,579611,579611,731172,731172,496074,496074,496074,151416,151416,151416]