#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
vector< pair<ll,ll> >edj[1000010];
ll ar[1000100];
bitset<1000010>color;
ll dfs(ll node)
{
	//cout<<node<<" "<<ar[node]<<" x\n";
    color[node]=true;
    ll ans=0;
    for(auto i:edj[node])
    {
        ll child=i.first;
        ll cost=i.second;
        if(color[child]==false)
        {
            color[child]=true;
            ll x=dfs(child);
            ar[node]+=min(x,cost);
        }
    }
    //cout<<node<<" "<<ar[node]<<" x\n";
    return ar[node];
}
int main()
{
    //freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,z;
        cin>>n>>z;
        for(ll i=0; i<n-1; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            edj[u].PB({v,w});
            edj[v].PB({u,w});
        }
        for(ll i=1; i<=n; i++)
        {
            cin>>ar[i];color[i]=false;
        }
        ll ans=dfs(z);
        cout<<ans<<"\n";
    }
    return 0;
}

