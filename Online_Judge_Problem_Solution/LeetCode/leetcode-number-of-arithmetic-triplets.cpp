// https://leetcode.com/problems/number-of-arithmetic-triplets

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int siz=nums.size(),ans=0;
        for(int i=0;i<siz-2;i++){
            for(int j=i+1;j<siz-1;j++){
                for(int k=j+1;k<siz;k++){
                    if((nums[j]-nums[i]==diff)&&(nums[k]-nums[j]==diff)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};