// https://leetcode.com/problems/stone-game

class Solution {
public:
    int mem[505][505][3],n;
    int dp(int l,int r,int status,vector<int>& V){
        if(l>r){
            return 0;
        }
        if(mem[l][r][status]!=-1){
            return mem[l][r][status];
        }
        int ans=0;
        ans=V[l]-dp(l+1,r,1-0,V);
        ans=max(ans,V[r]-dp(l,r-1,1-0,V));
        return mem[l][r][status]=ans;
    }
    bool stoneGame(vector<int>& piles) {
        n=piles.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<2;k++){
                    mem[i][j][k]=-1;
                }
            }
        }
        int ans=dp(0,n-1,0,piles);
        return ans>0;
    }
};