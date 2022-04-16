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
ll mem[110][50010],n,sum;
vector<ll>coin;
ll dp(ll pos, ll val)
{
    if(pos>=n)
    {
        ll another_cost=sum-val;
        ll res=abs(another_cost-val);
        return res;
    }
    if(mem[pos][val]!=-1)
    {
        return mem[pos][val];
    }
    ll cost=dp(pos+1,val);
    cost=min(cost,dp(pos+1,val+coin[pos]));
    return mem[pos][val]=cost;
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
        coin.clear();
        sum=0;
        cin>>n;
        if(n==0)
        {
            cout<<"0\n";
            continue;
        }
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            coin.PB(a);
            sum+=a;
        }
        if(n==1)
        {
            cout<<coin[0]<<"\n";
            continue;
        }
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=sum; j++)
            {
                mem[i][j]=-1;
            }
        }
        ll ans=dp(0,0);
        cout<<ans<<"\n";
    }
    return 0;
}





