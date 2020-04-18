/*
    Author : SK Arman Hossain
    University of Barishal
    Problem: Euler path editorial
    Solution: DFS
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 200001
ll degree[N+10];
map<pair<ll,ll>,bool>mp;
vector<ll>edj[N+10],V;
void dfs(ll node)
{
    for(ll i:edj[node])
    {
        if(mp[ {node,i}]==true)
        {
            mp[ {node,i}]=false;
            mp[ {i,node}]=false;
            dfs(i);
        }
    }
    V.push_back(node);
}
int main()
{
    ll tcase;
    cin>>tcase;
    for(ll TEST=1; TEST<=tcase; TEST++)
    {
        ll n,e;
        cin>>n>>e;
        mp.clear();
        V.clear();
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            degree[i]=0;
        }
        for(ll i=0; i<e; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].push_back(v);
            edj[v].push_back(u);
            mp[ {u,v}]=1;
            mp[ {v,u}]=1;
            degree[u]++;
            degree[v]++;
        }
        ll od=0,ck=0,source;
        for(ll i=1; i<=n; i++)
        {
            if(degree[i]&1){
                    od++;source=i;
            }
        }
        if(od<=2)
            dfs(source);
        else
            ck=1;
        if(!ck)
        {
            reverse(V.begin(),V.end());
            for(ll i:V)
            {
                cout<<i<<" ";
            }
            cout<<"\n";
        }
        else
        {
            cout<<"NO Euler Path\n";
        }

    }
}
/*
1
7 8
1 2
2 3
2 5
2 8
3 4
4 5
5 8
5 7
*/
