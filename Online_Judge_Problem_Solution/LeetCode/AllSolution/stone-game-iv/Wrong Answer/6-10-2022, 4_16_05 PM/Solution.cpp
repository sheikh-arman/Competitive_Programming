// https://leetcode.com/problems/stone-game-iv

class Solution {
public:
    bool winnerSquareGame(int n) {
        int dp[n+10];
        dp[0]=0;
        dp[1]=1;
        dp[2]=0;
        dp[3]=0;
        vector<int>V;
        for(int i=1;;i++){
            if(i*i>n){
                break;
            }
            V.push_back(i*i);
        }
        for(int i=4;i<=n;i++){
            int ck=0;
            for(int j:V){
                if(j>i)break;
                if(dp[i-j]==0){
                    ck=1;
                }
            }
            dp[i]=ck;
        }
        return dp[n]>0;
    }
};