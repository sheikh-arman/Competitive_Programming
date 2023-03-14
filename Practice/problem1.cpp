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
vector<ll>edj[200010];
ll sparse[200010][22];
ll level[200010],start[200010],en[200010];
ll cnt;
void dfs(ll node,ll parent=-1){
    start[node]=cnt++;
    for(ll i:edj[node]){
        if(parent!=i){
            level[i]=level[node]+1;
            sparse[i][0]=node;
            dfs(i);
        }
    }
    en[node]=cnt++;
}
void pre_process(ll n){
    for(ll j=1;(1<<j)<=n;j++){
        for(ll i=1;i<=n;i++){
            sparse[i][j]=sparse[sparse[i][j-1]][j-1];
        }
    }
}
ll lca(ll u,ll v){
    if(level[u]<level[v])swap(u,v);
    ll lg=0;
    for(ll lg=0;(1<<lg)<=level[u];lg++);
    lg--;
    if(level[u]!=level[v]){
        for(ll i=lg;i>=0;i--){
            if(level[u]-(1<<i)>=level[v]){
                u=sparse[u][i];
            }
        }
    }
    if(u==v)return u;
    for(ll i=lg;i>=0;i--){
        if(sparse[u][i]!=-1&&sparse[u][i]!=sparse[v][i]){
            u=sparse[u][i];
            v=sparse[v][i];
        }
    }
    return sparse[u][0];
}
void clr(ll n){
    for(ll i=0;i<=n;i++){
        edj[i].clear();
        level[i]=0;
        for(ll j=0;j<22;j++){
            sparse[i][j]=-1;
        }
    }
    cnt=1;
}
void input_edge(ll m){
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        edj[u].push_back(v);
        edj[v].push_back(u);
    }
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
        



    }
    return 0;
 ///*****************************  ALHAMDULILLAH  *****************************/
}





