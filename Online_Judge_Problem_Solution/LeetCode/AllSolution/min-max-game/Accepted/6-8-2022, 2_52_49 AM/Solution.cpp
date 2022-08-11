// https://leetcode.com/problems/min-max-game

class Solution {
public:
    int sol(int i,int j,vector<int>& nums,int status){
        if(i==j)return nums[i];
        int mid=(i+j)/2;
        int p=sol(i,mid,nums,0);
        int q=sol(mid+1,j,nums,1);
        if(status==0)return min(p,q);
        else return max(p,q);
    }
    int minMaxGame(vector<int>& nums) {
        int n=nums.size();
        int ans=sol(0,n-1,nums,0);
        return ans;
    }
};