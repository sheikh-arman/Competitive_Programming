// https://leetcode.com/problems/maximum-erasure-value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=0;
        int ar[10010];
        for(int i=0;i<=10000;i++){
            ar[i]=0;
        }
        int ans=0,sum=0;
        while(right<n){
            while(ar[nums[right]]>0){
                sum-=nums[left];
                ar[nums[left]]=0;
                left++;
            }
           sum+=nums[right];
           ar[nums[right]]=1;
           right++;
           ans=max(ans,sum);
        }
        return ans;
    }
};
