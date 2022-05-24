class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int mem[n+10][3];
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                 mem[i][j]=0;
            }
        }
        mem[0][0]=0;
        mem[0][1]=nums[0];
        for(int i=1;i<n;i++){
            mem[i][0]=max(mem[i-1][0],mem[i-1][1]);
            mem[i][1]=max(mem[i-1][0]+nums[i],mem[i-1][1]);
        }
        int ans=0;
        ans=max(ans,max(mem[n-1][0],mem[n-1][1]));
        return ans;
    }
};
