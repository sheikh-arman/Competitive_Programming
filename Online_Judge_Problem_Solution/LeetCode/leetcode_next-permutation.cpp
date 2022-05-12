class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int siz=nums.size(),ck=1;
        for(int i=1;i<siz;i++){
            if(nums[i]>nums[i-1]){
                ck=0;break;
            }
        }
        if(ck){
            for(int i=0;i<siz/2;i++){
                swap(nums[i],nums[siz-i-1]);
            }
        }
        else{
            next_permutation(nums.begin(),nums.end());
        }
    }
};
