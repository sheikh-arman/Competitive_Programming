// https://leetcode.com/problems/find-triangular-sum-of-an-array

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(1){
            if((int)nums.size()==1)break;
            int n=nums.size();
            for(int i=1;i<n;i++){
                nums[i-1]=(nums[i-1]+nums[i])%10;
            }
            nums.pop_back();
        }
        return nums[0];
    }
};