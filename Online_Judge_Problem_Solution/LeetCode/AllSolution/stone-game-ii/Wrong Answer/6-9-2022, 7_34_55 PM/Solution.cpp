// https://leetcode.com/problems/stone-game-ii

class Solution {
public:
     int mem[110][110],n;
    int dp(int l,int m,vector<int>& V){
        if(l>=n){
            return 0;
        }
        if(mem[l][m]!=-1){
            return mem[l][m];
        }
        int ans=INT_MIN;
        int ma=2*m;
        int sum=0;
        for(int j=l;j<min(j+ma,n);j++){
            sum+=V[j];
            ans=max(ans,sum-dp(j+1,(j-l)+1,V));
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
        int ans=dp(0,1,piles);
        cout<<ans<<" x\n";
        int sum=0;
        for(int i:piles){
            sum+=i;
        }
        cout<<sum<<" x\n";
        sum-=ans;
        ans+=sum/2;
        return ans;
    }
};