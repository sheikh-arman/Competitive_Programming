// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    bool static cmp(string& s1,string& s2){
        return s1.size()<s2.size();
    }
    bool ck(string s1,string s2){
        int len2=s2.size();
        int cnt = 0, cntr = 0;
        for(int i = 0; i < s2.size(); i++){
            if(s2[i] != s1[cnt++]){
                cntr++; cnt--;
            }
        }
        return cntr == 1;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        int dp[n+6];
        for(int i=0;i<=n;i++){
             dp[i]=1;
        }
        int ans=1;
        for(int i=n-2;i>=0;i--){
            int ma=0;
            for(int j=i+1;j<n;j++){
                 if(words[j].size()-words[i].size()>1){
                      break;
                }
                if(words[j].size() == words[i].size())continue;
                if(ck(words[i],words[j])){
                    ma=max(ma,dp[j]);
                }
            }
            dp[i]=ma+1;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};