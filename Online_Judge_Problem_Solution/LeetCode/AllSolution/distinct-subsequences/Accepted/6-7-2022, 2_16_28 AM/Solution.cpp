// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    int mem[1010][1010];
    int n,m;
    string str,pattern;
    int dp(int i,int j){
        if(j>=m){
            return 1;
        }
        if(i>=n){
            return 0;
        }
        if(mem[i][j]!=-1){
            return mem[i][j];
        }
        int ans=0;
        if(str[i]==pattern[j]){
            ans+=dp(i+1,j+1);
        }
        ans+=dp(i+1,j);
        return mem[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        str=s;
        pattern=t;
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