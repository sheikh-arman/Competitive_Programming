#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 10000010
ll dp[MAX+10];
void seive()
{
    for(ll i=0; i<=MAX; i++)dp[i]=i;
    dp[0]=1;
    for(ll i=2; i<=MAX; i+=2)
    {
        dp[i]-=dp[i]/2;
    }
    for(ll i=3; i<=MAX; i+=2)
    {
        if(dp[i]==i)
        {
            for(ll j=i; j<=MAX; j+=i)
            {
                dp[j]-=dp[j]/i;
            }
        }
    }
    for(ll i=2; i<=MAX; i++)
    {
        dp[i]+=dp[i-1];
    }
}
int main()
{
    fast;
    // freopen("1input.txt","r",stdin);
    seive();
    ll tcase;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n, p;
        cin>>n>>p;
        ll ma=dp[n];
        ll ans=-1;
        if(p<=ma)
        {
            ans=n;
            ll left=1,right=n;
            while(left<right)
            {
                ll mid=(left+right)>>1;
                ll val=dp[n/mid];
                if(val>=p)
                {
                    ans=mid;
                    left=mid+1;
                }
                else
                {
                    right=mid;
                }
            }
            ll val=dp[n/right];
            if(val>=p)ans=right;
        }
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
    return 0;
}
