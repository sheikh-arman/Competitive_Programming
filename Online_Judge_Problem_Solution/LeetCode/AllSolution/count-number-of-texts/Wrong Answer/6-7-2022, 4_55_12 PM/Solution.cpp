// https://leetcode.com/problems/count-number-of-texts

class Solution {
public:
    long long mem[100010];
    string s;
    int n,mod=1e9+7;
    int dp(int i) {
        if (i>=n) return 1;
        if (mem[i]!=-1) return  mem[i];
        int ans = 0;
        if(i+1<n&&s[i+1]==s[i]){
            ans+=dp(i+2);if(ans>=mod)ans%=mod;
            if(i+2<n&&s[i+2]==s[i]){
                ans+=dp(i+3);if(ans>=mod)ans%=mod;
                if(i+3<n&&s[i+3]==s[i]){
                    ans+=dp(i+4);if(ans>=mod)ans%=mod;
                    if(s[i]=='7'||s[i]=='9'){
                        if(i+4<n&&s[i]==s[i+4]){
                            ans+=dp(i+5);if(ans>=mod)ans%=mod;
                        }
                    }
                }
            }
        }
        ans+=dp(i+1);
        if(ans>=mod)ans%=mod;
        return mem[i]=ans;
    }
    int countTexts(string pressedKeys) {
        s=pressedKeys;
        n=s.size();
        for(int i=0;i<=n;i++)mem[i]=-1;
        long long ans=dp(0);
        return (int)ans;
    }
};