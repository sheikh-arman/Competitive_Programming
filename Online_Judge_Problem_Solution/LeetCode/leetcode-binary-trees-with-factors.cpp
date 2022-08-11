// https://leetcode.com/problems/binary-trees-with-factors

typedef long long int ll;
ll mod=1e9+7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        ll dp[n];
        for(int i=0;i<n;i++)dp[i]=0;
        sort(arr.begin(),arr.end(),greater<int>());
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        dp[n-1]=1;
        ll ans=1;
        for(int i=n-2;i>=0;i--){
            int num=arr[i];
            for(int j=i+1;j<n;j++){
                if(num%arr[j]==0&&mp.count(num/arr[j])){
                    int sec=mp[num/arr[j]];
                    if(j==sec){
                        dp[i]+=(dp[j]*dp[j]);
                    }
                    else{
                        dp[i]+=((dp[j]*dp[sec])%mod);
                    }
                }
                if(dp[i]>=mod)dp[i]%=mod;
            }
            dp[i]+=1;
            ans+=dp[i];
            if(dp[i]>=mod)dp[i]%=mod;
            if(ans>=mod)ans%=mod;
        }
        return ans;
    }
};