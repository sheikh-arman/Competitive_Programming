class Solution
{
    typedef long long int ll;
public:
    ll coinChange(vector<int>& coins, int amount)
    {
        ll n=coins.size();
        ll dp[amount+1];
        for(ll i=0; i<=amount; i++)
        {
            dp[i]=INT_MAX;
        }
        dp[0]=0;
        for(ll i=0; i<=amount; i++)
        {
            if(dp[i]==INT_MAX)continue;
            for(ll j=0; j<n; j++)
            {
                ll val=coins[j]+i;
                ll cnt=dp[i]+1;
                if(val<=amount)
                {
                    dp[val]=min(dp[val],cnt);
                }
            }
        }
        ll ans=dp[amount];
        if(dp[amount]==INT_MAX)
        {
            ans=-1;
        }
        return ans;
    }
};