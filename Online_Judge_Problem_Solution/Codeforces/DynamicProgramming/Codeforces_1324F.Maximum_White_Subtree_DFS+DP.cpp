
/*
    Sk arman Hossain
    University of Barisal

    Problem : Codeforces 1324F. Maximum White Subtree
    Solution : DFS + DP
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
vector<ll>edj[200010];
ll ar[200010];
ll cnt[200010];
void dfs(ll node,ll parent=-1){
    if(ar[node]==1)cnt[node]=1;
    else cnt[node]=-1;
    for(ll i:edj[node]){
        if(i!=parent){
            dfs(i,node);
            if(cnt[i]>0)
                cnt[node]+=cnt[i];
        }
    }
}
void dfs2(ll node,ll parent,ll val){
    if(val<0)val=0;
    if(cnt[node]<=0)cnt[node]+=val;
    else {
        cnt[node]=max(cnt[node],val);
    }
    for(ll i:edj[node]){
        if(i!=parent){
            dfs2(i,node,cnt[node]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        for(ll i=1;i<=n;i++){
            cin>>ar[i];
        }
        for(ll i=1;i<n;i++){
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
        }
        dfs(1);
        dfs2(1,-1,0);
        for(ll i=1;i<=n;i++){
            cout<<cnt[i]<<" ";
        }nl;


    }
///*****************************  ALHAMDULILLAH  *****************************/
}

