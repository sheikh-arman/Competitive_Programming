// https://leetcode.com/problems/stone-game-v

class Solution {
public:
    int mem[510][510],n;
    int cum[510];
    int dp(int i,int j,vector<int>& stoneValue){
        if(i>=j){
            return 0;
        }
        if(mem[i][j]!=-1){
            return mem[i][j];
        }
        int ans=0;
        for(int k=i;k<j;k++){
            int left=cum[k];
            if(i>0)left-=cum[i-1];
            int right=cum[j]-cum[k];
            int res=0;
            if(left>right){
                res=right+(dp(k+1,j,stoneValue));
            }
            else if(left<right){
                res=left+dp(i,k,stoneValue);
            }
            else{
                res=left+max(dp(i,k,stoneValue),dp(k+1,j,stoneValue));
            }
            ans=max(ans,res);
        }
        return mem[i][j]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=stoneValue[i];
            cum[i]=sum;
            for(int j=0;j<n;j++){
                mem[i][j]=-1;
            }
        }
        int ans=dp(0,n-1,stoneValue);
        return ans;
    }
};