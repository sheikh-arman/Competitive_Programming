/*
    Author : SK Arman Hossain
    University of Barishal
    Problem: UVA-12926_Trouble in Terrorist Town
    Solution:Topological Sort + DFS
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ending[5009],cnt=0;
bitset<5009>color;
bitset<5009>edge[5009];
vector<ll>edj[5009],trans_edj[5009];
vector<pair<ll,ll>>V;
void top_sort(ll node)
{
    color[node]=true;
    cnt++;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            top_sort(i);
        }
    }
    ending[node]=cnt++;
}
void dfs(ll node)
{
    color[node]=true;
    for(ll i:trans_edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            dfs(i);
        }
    }
}
int main()
{
    ll n,e;
    while(scanf("%lld%lld",&n,&e)!=EOF)
    {
        cnt=1;
        V.clear();
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            trans_edj[i].clear();
            color[i]=false;
            for(ll j=0; j<=n; j++)edge[i][j]=false;
        }
        for(ll i=0; i<e; i++)
        {
            ll u,v;
            scanf("%lld%lld",&u,&v);
            edge[u][v]=true;
        }
        ll cost;
        scanf("%lld",&cost);
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=n; j++)
            {
                if(edge[i][j]==false&&i!=j)
                {
                    edj[i].push_back(j);
                    trans_edj[j].push_back(i);
                }
            }
        }
        for(ll i=1; i<=n; i++)
        {
            if(color[i]==false)
            {
                top_sort(i);
            }
        }
        for(ll i=1; i<=n; i++)
        {
            V.push_back({ending[i],i});
        }
        sort(V.begin(),V.end());
        for(ll i=0; i<=n; i++)color[i]=false;
        ll ans=0;
        for(ll i=n-1; i>=0; i--)
        {
            if(color[V[i].second]==false)
            {
                ans++;
                dfs(V[i].second);
            }
        }
        printf("%lld\n",cost*ans);
    }
}

