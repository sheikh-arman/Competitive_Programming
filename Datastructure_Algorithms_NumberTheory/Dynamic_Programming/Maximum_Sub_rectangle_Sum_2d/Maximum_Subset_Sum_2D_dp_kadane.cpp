#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define sf(n) scanf("%lld",&n);
#define YES printf("YES\n");
#define NO printf("NO\n");
#define nl printf("\n");
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll mat[110][110];
ll cum_sum[110][110];
ll max_sub_rec(ll n,ll m)
{
    for(ll i=0; i<=n; i++)cum_sum[i][0]=0;
    for(ll j=1; j<=m; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            cum_sum[i][j]=cum_sum[i-1][j]+mat[i][j];
        }
    }
    ll ans=-1111111111;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=i; j<=n; j++)
        {
            ll sum=0;
            for(ll k=1; k<=m; k++)
            {
                ll val=cum_sum[j][k]-cum_sum[i-1][k];
                sum+=val;
                ans=max(sum,ans);
                if(sum<0)sum=0;
            }
        }
    }
    return ans;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    // cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=n; j++)
            {
                cin>>mat[i][j];
            }
        }
        ll ans=max_sub_rec(n,n);
        cout<<ans<<"\n";
    }
    return 0;
}
