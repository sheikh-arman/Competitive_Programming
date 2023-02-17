#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll mod=100000007;
ll SET(ll NUM,ll POS)
{
    return NUM | (1<<POS);
}
bool isOn(ll NUM,ll POS)
{
    return (bool)(NUM & (1<<POS));
}
ll dp[10010];
ll ar[110];
int main()
{
    //freopen("1input.txt","r",stdin);
    //fast;
    ll tcase=1;
    //cin>>tcase;
    scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n,k;
        //cin>>n>>k;
        scanf("%lld%lld",&n,&k);
        for(ll i=1; i<=n; i++)
        {
            //  cin>>ar[i];
            scanf("%lld",&ar[i]);
        }
        for(ll j=0; j<=k; j++)
        {
            dp[j]=0;
        }
        dp[0]=1;
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=k; j++)
            {
                if(j-ar[i]>=0)
                {
                    dp[j]+=dp[j-ar[i]];
                    if(dp[j]>=mod)dp[j]%=mod;
                }
            }
        }
        // cout<<"Case "<<test<<": "<<dp[k]<<"\n";
        printf("Case %lld: %lld\n",test,dp[k]);
    }
    return 0;
}

