/*
    Sk arman Hossain
    University of Barisal

    Problem name :
    Algorithm :
 */
#include<bits/stdc++.h>
#define nl cout<<"\n";
#define N 200001
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
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define minus1 printf("-1\n")
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
#define N 200005
ll cnt_parent[N+10];
bitset<N+10>color;
vector<ll>edj[N+10];
ll starting[N+10];
ll cnt_node[N+10];
ll cnt;
void dfs(ll node){
    starting[node]=++cnt;
    color[node]=true;
    for(ll i:edj[node]){
        if(color[i]==false){
            color[i]=true;
            cnt_parent[i]=cnt_parent[node]+1;
            dfs(i);
        }
    }
    cnt_node[node]=cnt-starting[node]+1;
}
void dfs2(ll node){
    cnt++;
    color[node]=true;
    for(ll i:edj[node]){
        if(color[i]==false){
            if(cnt_parent[i]>cnt_parent[node]){
                color[i]=true;
                dfs2(i);
            }
        }
    }
}
bool cmp(PR a,PR b){
    if(a.first!=b.first){
        return a.first<b.first;
    }
    else{
        return cnt_node[a.second]>cnt_node[b.second];
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
   //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m,k;
        cin>>n>>k;
       for(ll i=0;i<=n;i++){
           edj[i].clear();color[i]=false;
       }
       for(ll i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        edj[u].PB(v);
        edj[v].PB(u);
       }
       dfs(1);
       vector<PR>V;
       for(ll i=1;i<=n;i++){
          color[i]=false;
          V.PB({cnt_parent[i]-cnt_node[i],i});
       }
       sort(V.begin(),V.end(),cmp);
       ll ans=0;
       for(ll i=n-k;i<n;i++){
          if(color[V[i].second]==false){
              cnt=0;
              dfs2(V[i].second);
              ans+=(cnt*cnt_parent[V[i].second]);
          }
       }
       cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

