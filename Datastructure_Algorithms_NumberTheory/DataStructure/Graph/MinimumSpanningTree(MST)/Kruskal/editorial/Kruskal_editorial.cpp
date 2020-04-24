/*
    Sk arman Hossain
    University of Barisal

    Problem name : Minimum Spanning Tree editorial
    Solution : Kruskal with DSU
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define N 200002
ll rep[N+10];
ll node_cnt[N+10];
vector< pair<ll,pair<ll,ll> > > edj;
vector< pair<ll,pair<ll,ll> > > minimum_spanning_tree;
ll min_cost;
ll parent(ll n)
{
    return (rep[n]==n)?n:rep[n]=parent(rep[n]);
}
void joint(ll u,ll v,ll val)
{
    ll repu=parent(u);
    ll repv=parent(v);
    if(repu!=repv)
    {
        if(node_cnt[repu]>node_cnt[repv])
        {
            node_cnt[repu]+=node_cnt[repv];
            rep[repv]=repu;
            min_cost+=val;
            minimum_spanning_tree.push_back({val,{u,v}});
        }
        else
        {
            node_cnt[repv]+=node_cnt[repu];
            rep[repu]=repv;
            min_cost+=val;
            minimum_spanning_tree.push_back({val,{u,v}});
        }
    }
}
void kruskal(ll m)
{
    sort(edj.begin(),edj.end());
    for(ll i=0; i<m; i++)
    {
        joint(edj[i].second.first,edj[i].second.second,edj[i].first);
    }
}
int main()
{
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        edj.clear();
        minimum_spanning_tree.clear();
        min_cost=0;
        ll n,m;
        cin>>n>>m;
        for(ll i=0; i<=n; i++)
        {
            rep[i]=i;
            node_cnt[i]=1;
        }
        for(ll i=0; i<m; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            edj.push_back({w,{u,v}});
        }
        kruskal(m);
        cout<<"Sum of minimum spannimg tree is: "<<min_cost<<"\nEdge of tree are:\n";
        for(ll i=0;i<n-1;i++){
            cout<<minimum_spanning_tree[i].second.first<<" "<<minimum_spanning_tree[i].second.second<<" "<<minimum_spanning_tree[i].first<<"\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}



