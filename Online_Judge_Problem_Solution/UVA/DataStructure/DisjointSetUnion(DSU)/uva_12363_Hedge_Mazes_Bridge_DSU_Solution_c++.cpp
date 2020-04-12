/*
Author:SK Arman HOSSAIN

Problem:UVA 12363
Solution: Bridge and DSU

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>edj[10010];
vector<pair<ll,ll> >bridge;
ll start[10010];
ll rep[10010];
ll COUNT[10010];
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
ll fin(ll node)
{
    if(node==rep[node])
    {
        return node;
    }
    else
    {
        rep[node]=fin(rep[node]);
        return rep[node];
    }
}
void joint(ll u,ll v)
{
    ll repu=fin(u);
    ll repv=fin(v);
    if(repu!=repv)
    {
        if(COUNT[repu] > COUNT[repv]){
            COUNT[repu]+=COUNT[repv];
            rep[repv]=repu;
        }
        else{
            COUNT[repv]+=COUNT[repu];
            rep[repu]=repv;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll n,m,q;
    while(cin>>n>>m>>q && (n||m||q))
    {
        for(ll i=0; i<=n; i++)
        {
            color[i]=false;
            edj[i].clear();
            rep[i]=i;
            COUNT[i]=1;
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
        for(ll i=1; i<=n; i++)
        {
            if(color[i]==false)
            {
                color[i]=true;
                dfs_bridge_find(i,-1);
            }
        }
        ll siz=bridge.size();
        for(ll i=0;i<siz;i++){
            joint(bridge[i].first,bridge[i].second);
        }
        for(ll i=1; i<=q; i++)
        {
            ll a,b;
            cin>>a>>b;
            ll ra=fin(a);
            ll rb=fin(b);
            if(ra==rb)
            {
                cout<<"Y\n";
            }
            else
            {
                cout<<"N\n";
            }
        }
        cout<<"-\n";
    }
}


/*

16 16 4
1 2
2 3
4 5
5 6
6 7
6 8
8 5
9 10
10 11
11 12
12 10
13 14
14 15
15 16
16 17
16 13
4 7
4 5
1 3
1 4
*/
/*
8 8 10
4 3
2 3
4 2
1 4
4 7
2 5
3 8
3 6
*/
