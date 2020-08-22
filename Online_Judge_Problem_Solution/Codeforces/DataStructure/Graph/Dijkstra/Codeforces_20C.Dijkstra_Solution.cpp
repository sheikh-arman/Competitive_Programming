/*
    Sk arman Hossain
    University of Barisal

    Problem name : Codeforces 20 C. Dijkstra?
    Solution : Dijkastra
 */
#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
map< pair<ll,ll>,ll>mp;
vector<ll>edj[100010];
priority_queue< pair<ll,ll> , vector<pair<ll,ll>> ,greater<pair<ll,ll> > >pq;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll n,m,w,u,v;
    cin>>n>>m;

    for(ll i=0; i<m; i++)
    {
        cin>>u>>v>>w;
        if(u==v)continue;
        if(mp.count({u,v})==0)
        {
            edj[u].PB(v);
            edj[v].PB(u);
            mp[{u,v}]=w;
            mp[{v,u}]=w;
        }
        else
        {
            mp[{u,v}]=min(w,mp[{u,v}]);
            mp[{v,u}]=min(w,mp[{u,v}]);
        }
    }
    ll weight[100010],pre[100010];
    for(ll i=0; i<=n; i++)
    {
        weight[i]=99999999999999;pre[i]=-1;
    }
   pq.push({0,1});
    weight[1]=0;
    while(!pq.empty()){
        pair<ll,ll> parent;
        parent=pq.top();
        pq.pop();
        for(ll i:edj[parent.second]){
            if(weight[i]>weight[parent.second]+mp[{parent.second,i}]){
                weight[i]=weight[parent.second]+mp[{parent.second,i}];
                pq.push({weight[i],i});
                pre[i]=parent.second;
            }
        }
    }
    if(pre[n]==-1){
        cout<<"-1\n";
    }
    else{
        vector<ll>V;
        while(pre[n]!=-1){
            V.PB(n);
            n=pre[n];
        }
        V.PB(1);
        reverse(V.begin(),V.end());
        for(ll i:V){
            cout<<i<< " ";
        }
        cout<<"\n";
    }
    return 0;
}
