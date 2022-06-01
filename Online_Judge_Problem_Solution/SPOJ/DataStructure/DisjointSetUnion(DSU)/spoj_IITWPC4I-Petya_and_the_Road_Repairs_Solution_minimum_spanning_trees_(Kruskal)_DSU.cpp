/*
    Sk arman Hossain
    University of Barisal

    Problem name : IITWPC4I - Petya and the Road Repairs
    Solution : Kruskal with DSU
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define N 200002
ll rep[N+10];
ll node_cnt[N+10];
bitset<N+10>milkman;
vector< pair<ll,pair<ll,ll> > > edj;
ll min_cost;
ll parent(ll n){
    return (rep[n]==n)?n:rep[n]=parent(rep[n]);
}
void joint(ll u,ll v,ll val){
    ll repu=parent(u);
    ll repv=parent(v);
    if(repu!=repv){
        if(!milkman[repu]||!milkman[repv]){
            if(node_cnt[repu]>node_cnt[repv]){
                node_cnt[repu]+=node_cnt[repv];
                rep[repv]=repu;
                milkman[repu]=milkman[repu]|milkman[repv];
                min_cost+=val;
            }
            else{
                node_cnt[repv]+=node_cnt[repu];
                rep[repu]=repv;
                milkman[repv]=milkman[repu]|milkman[repv];
                min_cost+=val;
            }
        }
    }
}
void kruskal(ll m){
    for(ll i=0;i<m;i++){
        joint(edj[i].second.first,edj[i].second.second,edj[i].first);
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
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<=n;i++){
            milkman[i]=0;
            rep[i]=i;
            node_cnt[i]=1;
        }
        for(ll i=1;i<=n;i++){
            ll a;
            cin>>a;
            milkman[i]=(bool)a;
        }
        for(ll i=0;i<m;i++){
            ll u,v,w;
            cin>>u>>v>>w;
            edj.push_back({w,{u,v}});
        }
        sort(edj.begin(),edj.end());
        kruskal(m);
        ll ck=1;
        for(ll i=1;i<=n&&ck;i++){
            ll re=parent(i);
            if(!milkman[re]){
                ck=0;
            }
        }
        if(ck){
            cout<<min_cost<<"\n";
        }
        else{
            cout<<"impossible\n";
        }




    }

///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
