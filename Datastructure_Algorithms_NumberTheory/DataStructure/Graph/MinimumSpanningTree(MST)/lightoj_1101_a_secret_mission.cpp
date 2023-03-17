/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
    Date:
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define sf(n) scanf("%lld",&n);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define nl cout<<"\n";
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
#define MAX 2000010
#define T(n) printf("test : %d\n",n);
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
vector<pair<ll,ll>>edj[50010];
ll rep[50010];
ll Find(ll node){
    return (node==rep[node]?node:rep[node]=Find(rep[node]));
}
ll label[50010];
ll sparse[50010][20];
ll Max_value[50010][20];
void dfs(ll node){
    for(auto i:edj[node]){
        ll u=i.first;
        ll w=i.second;
        if(label[u]==-1){
            label[u]=label[node]+1;
            sparse[u][0]=node;
            Max_value[u][0]=w;
            dfs(u);
        }
    }
}
void pre_compute(ll siz){
    for(ll j=1;(1<<j)<=siz;j++){
        for(ll i=1;i<=siz;i++){
            sparse[i][j]=sparse[sparse[i][j-1]][j-1];
            Max_value[i][j]=max(Max_value[i][j-1],Max_value[sparse[i][j-1]][j-1]);
        }  
    }
}
ll query(ll u,ll v)
{
    if(label[u]<label[v])swap(u,v);
    ll ma=Max_value[u][0];
    ll lg;
    for(lg=0; (1<<lg)<=label[u]; lg++);
    lg--;
    if(label[u]!=label[v])
    {
        for(ll i=lg; i>=0; i--)
        {
            if(label[u]-(1<<i)>=label[v])
            {
                ma=max(ma,Max_value[u][i]);
                u=sparse[u][i];
            }
        }
    }
    if(u==v)
    {
        return ma;
    }
    if(u!=v)
    {
        for(ll i=lg; i>=0; i--)
        {
            if(sparse[u][i]!=-1&&sparse[u][i]!=sparse[v][i])
            {
                ma=max(ma,Max_value[u][i]);
                ma=max(ma,Max_value[v][i]);
                u=sparse[u][i];
                v=sparse[v][i];
            }
        }
    }
    ma=max(ma,Max_value[u][0]);
    ma=max(ma,Max_value[v][0]);
    return ma;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<=n;i++){
            label[i]=-1;
            rep[i]=i;
            edj[i].clear();
            for(ll j=0;j<19;j++){
                sparse[i][j]=-1;
                Max_value[i][j]=0;
            }
        }
        vector< pair< pair<ll,ll> , ll> > V;
        for(ll i=0;i<m;i++){
            ll u,v,w;
            cin>>u>>v>>w;
            V.PB({{w,u},v});
        }
        VST(V);
        for(ll i=0;i<m;i++){
            ll u,v,w;
            u=V[i].first.second;
            v=V[i].second;
            w=V[i].first.first;
            if(Find(u)!=Find(v)){
                rep[Find(v)]=Find(u);
                edj[u].PB({v,w});
                edj[v].PB({u,w});
            }
        }
        label[1]=0;
        sparse[1][0]=1;
        dfs(1);
        pre_compute(n);
        ll qry;
        cin>>qry;
        cout<<"Case "<<test<<":\n";
        for(ll i=0;i<qry;i++){
            ll u,v;
            cin>>u>>v;
            ll ans=query(u,v);
            cout<<ans<<"\n";
        }
    }
    return 0;
 ///*****************************  ALHAMDULILLAH  *****************************/
}





