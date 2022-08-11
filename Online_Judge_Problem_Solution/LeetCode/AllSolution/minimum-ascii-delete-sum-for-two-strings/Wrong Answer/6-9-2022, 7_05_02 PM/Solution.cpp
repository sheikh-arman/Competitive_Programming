// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings

class Solution {
public:
    int mem[1010][1010],n,m;
    string s,t;
    int ars[1010],arl[1010];
    int dp(int l,int r){
        if(l>=n||r>=m){
            int cost=ars[l]+arl[r];
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
            ans=dp(l+1,r)+(int)s[l];
            ans=min(ans,dp(l,r+1)+(int)s[r]);
        }
       return mem[l][r]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        s=s1;
        t=s2;
        n=s.size();
        m=t.size();
        ars[n]=0;
        arl[m]=0;
        int sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=(int)s[i];
            ars[i]=sum;
        }
        sum=0;
        for(int i=m-1;i>=0;i--){
            sum+=(int)t[i];
            arl[i]=sum;
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                mem[i][j]=-1;
            }
        }
        int ans=dp(0,0);
        return ans;
    }
};