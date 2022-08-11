// https://leetcode.com/problems/stone-game-iii

class Solution {
public:
    int mem[50010],n;
    int cum[50010];
    int dp(int l){
        if(l>=n){
            return 0;
        }
        if(mem[l]!=-1){
            return mem[l];
        }
        int ans=0;
        int cnt=1;
        for(int j=l;j<min(l+3,n);j++){
            ans=max(ans,cum[l]-dp(j+1));
            cnt++;
        }
        return mem[l]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        for(int i=0;i<=n;i++){
             mem[i]=-1;
        }
        cum[n]=0;
        int sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=stoneValue[i];
            cum[i]=sum;
        }
        int ans=dp(0);
        string s;
        int bob=sum-ans;
        if(ans>bob){
            s="Alice";
        }
        else if(bob>ans){
            s="Bob";
        }
        else{
            s="Tie";
        }
        return s;
    }
};