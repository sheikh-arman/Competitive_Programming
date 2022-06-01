/*
    Sk arman Hossain
    University of Barisal

    Problem name : uva 10099 The Tourist Guide
    Solution : data compression
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define N 110
ll rep[N+10];
ll siz[N+10];
vector<pair<ll,ll>>mst[110];
vector<pair<ll,pair<ll,ll> > >edj;
bitset<N+10>color;
ll Find(ll n){
    return (rep[n]==n)?n:rep[n]=Find(rep[n]);
}
void joint(ll u,ll v,ll w){
    ll ru=Find(u);
    ll rv=Find(v);
    if(ru!=rv){
        if(siz[ru]<siz[rv])
            swap(ru,rv);
        siz[ru]+=siz[rv];
        rep[rv]=ru;
        mst[u].push_back({v,w});
        mst[v].push_back({u,w});
    }
}
void kruskal(ll m){
    sort(edj.begin(),edj.end());
    reverse(edj.begin(),edj.end());
    for(ll i=0;i<m;i++){
        joint(edj[i].second.first,edj[i].second.second,edj[i].first);
    }
}
ll ans;
void dfs(ll node,ll mi,ll dist){
    color[node]=true;
    ll si=mst[node].size();
    for(ll i=0;i<si;i++){
        if(color[mst[node][i].first]==false){
                color[mst[node][i].first]=true;
            ll tm=min(mi,mst[node][i].second);
            if(mst[node][i].first==dist){
                ans=tm;return;
            }
            dfs(mst[node][i].first,tm,dist);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    /freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll tcase=1;
    ll n,m,cnt=1;
    //cin>>tcase;
    while(cin>>n>>m&&(n||m))
    {
        for(ll i=0;i<=n;i++){
            color[i]=false;
            mst[i].clear();
            siz[i]=1;
            rep[i]=i;
        }
        edj.clear();
        for(ll i=0;i<m;i++){
            ll u,v,w;
            cin>>u>>v>>w;
            edj.push_back({w,{u,v}});
        }
        kruskal(m);
        ll source,dis,val;
        cin>>source>>dis>>val;
        dfs(source,LONG_MAX,dis);
        ll result=(val/(ans-1))+(val%(ans-1)!=0);
        cout<<"Scenario #"<<cnt++<<"\n";
        cout<<"Minimum Number of Trips = ";
        cout<<result<<"\n\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
