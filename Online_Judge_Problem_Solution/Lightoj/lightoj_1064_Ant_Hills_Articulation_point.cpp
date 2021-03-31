/*
    Sk arman Hossain
    University of Barisal
    Problem name : loj 1064
    Solution : dfs (articulation point)
 */
#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
vector<ll>edj[10010];
ll start[10010];
ll en[10010],cnt;
bitset<10010>color,ap;
void dfs_ap(ll node,ll parent)
{
    ll child=0;
    start[node]=cnt;
    en[node]=cnt++;
    ll siz=edj[node].size();
    color[node]=true;
    for(ll i=0; i<siz; i++)
    {
        ll tm=edj[node][i];
        if(color[tm]==false)
        {
            child++;
            color[tm]=true;
            dfs_ap(tm,node);
            en[node]=min(en[tm],en[node]);
            if (parent == -1 && child > 1)
            {
                ap[node] = true;
            }
            if(parent != -1&& start[node]<=en[tm])
            {
                ap[node]=true;
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
    //freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            color[i]=false;
            ap[i]=false;
        }
        for(ll i=0; i<m; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
        }
        for(ll i=1; i<=n; i++)
        {
            if(color[i]==false)
            {
                dfs_ap(i,-1);
            }
        }

        ll cnt=0;
        for(ll i=1; i<=n; i++)
        {
            if(ap[i]==true)cnt++;
        }
        cout<<"Case "<<test<<": "<<cnt<<"\n";
    }
    return 0;
}

