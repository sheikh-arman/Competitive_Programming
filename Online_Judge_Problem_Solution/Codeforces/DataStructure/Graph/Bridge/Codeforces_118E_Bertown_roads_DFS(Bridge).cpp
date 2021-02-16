

/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution : dfs(bridge)
 */
#include<bits/stdc++.h>
#define nl cout<<"\n";
#define PR pair<ll,ll>
#define sf1(n) cin>>n
#define sf2(n, m) cin>>n>>m
#define sf3(n, m,k ) cin>>n>>m>>k
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define minus1 printf("-1\n");
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTr(v) sort(v.begin(),v.end(),greater<long long int>())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 200001
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;

vector<ll>edj[100010];
vector<pair<ll,ll> >bridge;
ll start[100010];
ll en[100010],cnt;
ll color[100010];
ll ck;
void dfs_bridge_find(ll node,ll parent)
{
    start[node]=en[node]=cnt++;
    ll siz=edj[node].size();
    color[node]=true;
    for(ll i=0; i<siz; i++)
    {
        ll tm=edj[node][i];
        if(color[tm]==false)
        {
            color[tm]=true;
            dfs_bridge_find(tm,node);
            en[node]=min(en[tm],en[node]);
            if(tm[en]>start[node]){
                ck=0;return;
            }
        }
        else if(tm!=parent)
        {
            en[node]=min(start[tm],en[node]);
        }
    }
}

map<PR,int>mp;
void dfs(ll node,ll parent){
    color[node]=true;
    for(ll i:edj[node]){
        if(color[i]==false){
            color[i]=true;
            mp[{node,i}]=1;
            dfs(i,node);
        }
        else{
            if(parent!=i){
                if(mp.count({node,i})==0&&mp.count({i,node})==0){
                    mp[{node,i}]=1;
                }
            }
        }
    }
}
int main()
{
    fast;
    //freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        vector<PR>V;
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<=n;i++){
            color[i]=false;
            edj[i].clear();
        }
        for(ll i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
            V.PB({u,v});
        }
        ck=1;
        cnt=1;
        dfs_bridge_find(1,-1);
        if(ck){
            for(ll i=0;i<=n;i++)color[i]=false;
            dfs(1,-1);
            ll siz=V.size();
            for(ll i=0;i<m;i++){
                ll u=V[i].first,v=V[i].second;
                if(mp[{u,v}]==1){
                    cout<<u<<" "<<v<<"\n";
                }
                else{
                    cout<<v<<" "<<u<<"\n";
                }
            }
        }
        else{
            cout<<"0\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}





