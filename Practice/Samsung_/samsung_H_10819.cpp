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
ll mem[110][10010];
ll cost[110],favor[110],money,n;
ll dp(ll pos,ll balance){
    if(pos>=n){
        return 0;
    }
    if(mem[pos][balance]!=-1){
        return mem[pos][balance];
    }
    ll res=dp(pos+1,balance);
    if(cost[pos]<=balance){
        res=max(res,dp(pos+1,balance-cost[pos])+favor[pos]);
    }
    return mem[pos][balance]=res;
}
int main()
{
    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    while(scanf("%lld%lld",&money,&n)!=EOF)
    {
        for(ll i=0; i<n; i++)
        {
            cin>>cost[i];
            cin>>favor[i];
        }
        if(money>1800)money+=200;
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=money; j++)
            {
                mem[i][j]=-1;
            }
        }
        ll ans=dp(0,money);
        cout<<ans<<"\n";
    }
    return 0;
}
