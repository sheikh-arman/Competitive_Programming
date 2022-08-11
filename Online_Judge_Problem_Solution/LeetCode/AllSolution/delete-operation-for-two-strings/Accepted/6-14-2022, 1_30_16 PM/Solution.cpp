// https://leetcode.com/problems/delete-operation-for-two-strings

class Solution {
public:
    int mem[1010][1010],n,m;
    string s,t;
    int dp(int l,int r){
        if(l>=n||r>=m){
            int cost=(n-l)+(m-r);
            return cost;
        }
        if(mem[l][r]!=-1){
            return mem[l][r];
        }
        int ans=INT_MAX;
        if(s[l]==t[r]){
            ans=dp(l+1,r+1);
        }
        else{
            ans=min(ans,dp(l+1,r)+1);
            ans=min(ans,dp(l,r+1)+1);
        }
       return mem[l][r]=ans;
    }
    int minDistance(string word1, string word2) {
        s=word1;
        t=word2;
        n=s.size();
        m=t.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                mem[i][j]=-1;
            }
        }
        int ans=dp(0,0);
        return ans;
    }
};