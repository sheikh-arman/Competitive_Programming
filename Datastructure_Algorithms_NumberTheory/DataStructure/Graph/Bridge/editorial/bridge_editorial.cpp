#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>edj[10010];
vector<pair<ll,ll> >bridge;
ll start[10010];
ll en[10010],cnt;
bitset<10010>color;
void dfs_bridge_find(ll node,ll parent)
{
    start[node]=en[node]=cnt++;
    ll siz=edj[node].size();
    color[node]=true;
    for(ll i=0; i<siz; i++)
    {
        ll tm=edj[node][i];
        if(color[tm]==false)
        {
            color[tm]=true;
            dfs_bridge_find(tm,node);
            en[node]=min(en[tm],en[node]);
            if(tm[en]>start[node]){
                bridge.push_back({tm,node});
            }
        }
        else if(tm!=parent)
        {
            en[node]=min(start[tm],en[node]);
        }
    }
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll n,m,q;
    while(cin>>n>>m && (n||m))
    {
        for(ll i=0; i<=n; i++)
        {
            color[i]=false;
            edj[i].clear();
        }
        bridge.clear();
        for(ll i=0; i<m; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[v].push_back(u);
            edj[u].push_back(v);
        }
        cnt=1;
        dfs_bridge_find(1,-1);
        ll siz=bridge.size();
        cout<<"Bridge are :\n";
        for(ll i=0;i<siz;i++){
            cout<<bridge[i].first<<" "<<bridge[i].second<<"\n";
        }
    }
}


