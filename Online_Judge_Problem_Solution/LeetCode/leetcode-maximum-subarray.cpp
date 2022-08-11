// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=0,res=INT_MIN,ck=0;
        for(int i:nums){
            ans+=i;
            if(ans<0){
                ans=0;
            }
            else{
                res=max(res,ans);ck=1;
            }
        }
        if(ck==0){
            res=INT_MIN;
            for(int i:nums){
                res=max(res,i);
            }
        }
        return res;
    }
};