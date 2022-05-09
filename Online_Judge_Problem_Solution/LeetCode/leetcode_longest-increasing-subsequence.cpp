 class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>V;
        int siz=nums.size();
        for(int i=0;i<siz;i++){
            int pos=lower_bound(V.begin(),V.end(),nums[i])-V.begin();
            int s=V.size();
            if(pos>=s){
                V.push_back(nums[i]);
            }
            else{
                V[pos]=nums[i];
            }
        }
        int ans=V.size();
        return ans;
    }
};