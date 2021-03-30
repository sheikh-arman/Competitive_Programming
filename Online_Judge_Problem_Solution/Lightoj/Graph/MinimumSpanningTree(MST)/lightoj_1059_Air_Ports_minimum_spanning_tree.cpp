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
//ll edj[55][55];
ll min_cost;
ll Find(ll n)
{
    return (rep[n]==n)?n:rep[n]=Find(rep[n]);
}
void joint(ll u,ll v,ll val,ll A)
{
    ll repu=Find(u);
    ll repv=Find(v);
    if(repu!=repv)
    {
        if(val<A)
        {
            if(node_cnt[repu]>node_cnt[repv])
            {
                node_cnt[repu]+=node_cnt[repv];
                rep[repv]=repu;
                min_cost+=val;
            }
            else
            {
                node_cnt[repv]+=node_cnt[repu];
                rep[repu]=repv;
                min_cost+=val;
            }
        }
    }
}
void kruskal(ll m,ll A)
{
    sort(edj.begin(),edj.end());
    for(ll i=0; i<m; i++)
    {
        joint(edj[i].second.first,edj[i].second.second,edj[i].first,A);
    }
}
int main()
{
     ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        edj.clear();
        min_cost=0;
        ll n,m,A,sum=0;
        cin>>n>>m>>A;
        for(ll i=0; i<m; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            edj.push_back({w,{u,v}});
        }
        for(ll i=0; i<=n; i++)
        {
            rep[i]=i;
            node_cnt[i]=1;
        }
        kruskal(m,A);
        ll road=min_cost;
        set<ll>st;
        for(ll i=1; i<=n; i++)
        {
            st.insert(Find(i));
        }
        ll airport=st.size();
        road+=(airport*A);
        cout<<"Case "<<test<<": "<<road<<" "<<airport<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
