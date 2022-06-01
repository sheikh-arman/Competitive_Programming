/*
    Sk arman Hossain
    University of Barisal
    Problem name : uva 11504 dominos
    Algorithm : Topological Sort + dfs
 */
#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define PR pair<ll,ll>
#define sf1(n) scanf("%lld", &n)
#define sf2(n, m) scanf("%lld %lld",&n,&m)
#define sf3(n, m,k ) scanf("%lld %lld %lld",&n,&m,&k)
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES printf("YES\n")
#define NO printf("NO\n")
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
vector<ll>nod[200100];
vector<PR>top_sort;
bool color[200010];
ll cnt=0;
void topological_sort(ll node)
{
    cnt++;
    color[node]=false;
    for(ll i=0; i<nod[node].size(); i++)
    {
        ll x=nod[node][i];
        if(color[x]==true)
        {
            color[x]=false;
            topological_sort(x);
            //cnt++;
        }
    }
    top_sort.PB({cnt,node});
    cnt++;
}
void dfs(ll node)
{
    color[node]=false;
    for(ll i=0; i<nod[node].size(); i++)
    {
        ll x=nod[node][i];
        if(color[x]==true)
        {
            color[x]=false;
            dfs(x);
        }
    }
}
void graph_input(ll edge)
{
    for(ll i=0; i<edge; i++)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        nod[a].push_back(b);
    }
}
int main()
{
    ///freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;
    sf1(tcase);
    for(ll test=1; test<=tcase; test++)
    {
        top_sort.clear();
        cnt=0;
        ll n,e;
        sf2(n,e);
        for(ll i=0; i<=n; i++)
        {
            color[i]=true;
            nod[i].clear();
        }
        graph_input(e);
        for(ll i=1; i<=n; i++)
        {
            if(color[i]==true)
            {
                topological_sort(i);
            }
        }
        VST(top_sort);
        ll ans=0;
        for(ll i=0; i<=n; i++)
            color[i]=true;
        for(ll i=n-1; i>=0; i--)
        {

            if(color[top_sort[i].ss]==true)
            {
                //printf("%lld \n",V})
                ans++;
                dfs(top_sort[i].ss);
            }
        }
        printf("%lld\n",ans);
        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

