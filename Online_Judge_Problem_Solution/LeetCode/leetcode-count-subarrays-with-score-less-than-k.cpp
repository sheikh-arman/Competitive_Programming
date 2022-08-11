// https://leetcode.com/problems/count-subarrays-with-score-less-than-k

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long int n=nums.size(),ans=0,sum=0;
        int left=0,right=0;
        while(right<n){
            if((sum+nums[right])*((right-left)+1)<k){
                ans+=(right-left)+1;
                sum+=nums[right];
                right++;
            }
            else{
                if(left==right){
                    left++;right++;
                }
                else{
                    sum-=nums[left];
                    left++;
                }
            }
           // cout<<ans<<" "<<sum<<" "<<left<<" "<<right<<" x\n";
        }
        return ans;
    }
};