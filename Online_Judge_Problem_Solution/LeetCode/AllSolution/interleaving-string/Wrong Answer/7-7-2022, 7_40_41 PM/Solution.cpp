// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    int mem[110][110];
    int dp(int i,int j,string s1,string s2,string s3){
        if(i<s1.size()&&j<s2.size()){
            if(s3[i+j]!=s1[i]&&s3[i+j]!=s2[j]){
              return 0;
            }
        }
        if(i>=s1.size()&&j>=s2.size()){
            return 1;
        }
        if(mem[i][j]!=-1){
            return mem[i][j];
        }
        int ans=0;
        if(i<s1.size()&&s3[i+j]==s1[i]){
            ans=dp(i+1,j,s1,s2,s3);
        }
        if(j<s2.size()&&s3[i+j]==s2[j]){
            ans|=dp(i,j+1,s1,s2,s3);
        }
        return mem[i][j]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                mem[i][j]=-1;
            }
        }
        int ans=dp(0,0,s1,s2,s3);
        return (bool)ans;
    }
};