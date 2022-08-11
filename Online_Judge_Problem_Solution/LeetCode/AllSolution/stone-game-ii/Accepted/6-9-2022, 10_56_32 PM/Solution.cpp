// https://leetcode.com/problems/stone-game-ii

class Solution {
public:
    int mem[110][110],n;
    int cum[110];
    int dp(int l,int m){
        if(l>=n){
            return 0;
        }
        if(mem[l][m]!=-1){
            return mem[l][m];
        }
        int ans=0;
        int ma=2*m;
        int cnt=1;
        for(int j=l;j<min(l+ma,n);j++){
            ans=max(ans,cum[l]-dp(j+1,max(cnt,m)));
            cnt++;
        }
        return mem[l][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                mem[i][j]=-1;
            }
        }
        cum[n]=0;
        int sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=piles[i];
            cum[i]=sum;
        }
        int ans=dp(0,1);
        return ans;
    }
};