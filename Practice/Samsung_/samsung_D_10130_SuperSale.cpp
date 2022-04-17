#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define sf(n) scanf("%lld",&n);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define nl cout<<"\n";
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
#define MAX 2000010
#define T(n) printf("test : %d\n",n);
ll price[1003],weight[1033];
ll mem[1010][33],product;
ll dp(ll pos, ll balance)
{
    if(pos>=product)
    {
        return 0;
    }
    if(mem[pos][balance]!=-1)
    {
        return mem[pos][balance];
    }
    ll ans=dp(pos+1,balance);
    if(weight[pos]<=balance)
    {
        ans=max(ans,dp(pos+1,balance-weight[pos])+price[pos]);
    }
    return mem[pos][balance]=ans;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>product;
        for(ll i=0; i<product; i++)
        {
            cin>>price[i]>>weight[i];
        }
        for(ll i=0; i<=product; i++)
        {
            for(ll j=0; j<=32; j++)
            {
                mem[i][j]=-1;
            }
        }
        ll query;
        cin>>query;
        ll ans=0;
        for(ll i=0; i<query; i++)
        {
            ll capacity;
            cin>>capacity;
            ans+=dp(0,capacity);
        }
        cout<<ans<<"\n";
    }
    return 0;
}




