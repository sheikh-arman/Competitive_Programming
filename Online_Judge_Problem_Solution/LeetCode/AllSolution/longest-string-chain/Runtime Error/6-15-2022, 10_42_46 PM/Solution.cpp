// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    bool static cmp(string s1,string s2){
        return (int)s1.size()<=(int)s2.size();
    }
    bool ck(string s1,string s2){
        int len1=s1.size();
        int len2=s2.size();
        if(len2>len1+1||len1>=len2){
            return 0;
        }
        bool ck1=1;
        int cc=0;
        int left=0,right=0;
        while(left<len1&&right<len2){
            if(s1[left]==s2[right]){
                left++;right++;
            }
            else{
                if(cc==0){
                    right++;
                }
                else{
                    return 0;
                }
                cc=1;
            }
        }
        return 1;
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