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
void joint(ll u,ll v,ll val)
{
    ll repu=Find(u);
    ll repv=Find(v);
    if(repu!=repv)
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
        min_cost=0;
        ll n,sum=0;
        cin>>n;
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=n; j++)
            {
                ll u,v,w;
                u=i;
                v=j;
                if(u>v)swap(u,v);
                cin>>w;
                if(u!=v&&w>0)
                    edj.push_back({w,{u,v}});
                sum+=w;
            }
        }

        for(ll i=0; i<=n; i++)
        {
            rep[i]=i;
            node_cnt[i]=1;
        }
        ll siz=edj.size();
        kruskal(siz);
        ll ans=sum-min_cost;
        set<ll>st;
        for(ll i=1;i<=n;i++){
			st.insert(Find(i));
        }
        if((ll)st.size()>1)ans=-1;
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
