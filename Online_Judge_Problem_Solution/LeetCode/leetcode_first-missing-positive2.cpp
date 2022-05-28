class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int siz=nums.size()+1;
        int ans=1;
        nums.push_back(999999);
        nums.push_back(999999);
        for(int i=siz-1;i>0;i--){
            nums[i]=nums[i-1];
        }
        for(int i=1;i<=siz;i++){
            if(nums[i]==i||nums[i]<=0||nums[i]>siz)continue;
            while(nums[i]>0&&nums[i]<=siz&&nums[i]!=nums[nums[i]]){
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
