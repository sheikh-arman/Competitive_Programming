// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    int mem[2010][2010],n,m;
    string str,pat;
    int dp(int i,int j){
        if(i>=n&&j>=m){
            return 1;
        }
        if(i>=n||j>=m){
            return 0;
        }
        if(mem[i][j]!=-1){
            return mem[i][j];
        }
        int ans=0;
        if(str[i]==pat[j]){
            ans=dp(i+1,j+1);
        }
        else{
            if(pat[j]=='*'){
                ans|=dp(i+1,j+1);
                ans|=dp(i+1,j);
            }
            else if(pat[j]=='?'){
                ans|=dp(i+1,j+1);
            }
            else{
                ans=0;
            }
        }
        return mem[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        n=s.size();
        m=p.size();
        str=s;
        pat=p;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                mem[i][j]=-1;
            }
        }
        int ans=dp(0,0);
        return ans>0;
    }
};