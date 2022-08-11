// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int siz=nums.size();
        int mem[siz+10];
        for(int i=0;i<=siz;i++)mem[i]=9999999;
        mem[0]=0;
        for(int i=0;i<siz-1;i++){
            int val=nums[i];
            for(int j=i+1;j<=min(i+val,siz-1);j++){
                mem[j]=min(mem[j],mem[i]+1);
            }
        }
        return mem[siz-1];
    }
};