// https://leetcode.com/problems/longest-ideal-subsequence

class Solution {
public:
    int mem[100010][30];
    int n;
    string ss;
    int dp(int i,int last,int k){
        if(i>=n){
            return 0;
        }
        if(mem[i][last]!=-1){
            return mem[i][last];
        }
        int ans=0;
        if(last==26){
            ans=1+dp(i+1,ss[i]-'a',k);
        }
        else{
            int val=ss[i]-'a';
            if(abs(val-last)<=k){
                ans=1+dp(i+1,val,k);
            }
        }
        ans=max(ans,dp(i+1,last,k));
        return mem[i][last]=ans;
    }
    int longestIdealString(string s, int k) {
        ss=s;
        n=s.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<=26;j++){
                mem[i][j]=-1;
            }
        }
        int ans=dp(0,26,k);
        return ans;
    }
};