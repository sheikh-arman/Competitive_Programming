/*
    Sk arman Hossain
    University of Barisal

    Problem name : https://www.codechef.com/problems/TREETR
    Algorithm : graph_linear with dfs + segment tree
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
#define N 100010
ll starting[N];
ll tree[3*N];
ll ending[N];
ll ar[N];
ll value[N],cnt;
bitset<N>color;
vector<ll>edj[100010];
void dfs(ll node)
{
    color[node]=true;
    starting[node]=++cnt;
    for(ll i:edj[node]){
        if(color[i]==false){
            color[i]==true;
            dfs(i);
        }
    }
    ending[node]=cnt;
}
ll build(ll n,ll b ,ll e){
    if(b==e){
        return tree[n]=ar[b];
    }
    ll p=build(n*2,b,(b+e)/2);
    ll q=build(n*2+1,(b+e)/2+1,e);
    return tree[n]=p+q;
}
ll query(ll n,ll b,ll e,ll l,ll r){
    if(b>=l&&e<=r){
        return tree[n];
    }
    else if(e<l||b>r){
        return 0;
    }
    ll p=query(n*2,b,(b+e)/2,l,r);
    ll q=query(n*2+1,(b+e)/2+1,e,l,r);
    return p+q;
}
ll update(ll n,ll b,ll e,ll l,ll r){
    if(b>=l&&e<=r){
        return tree[n]=ar[b];
    }
    else if(e<l||b>r){
        return tree[n];
    }
    ll p=update(n*2,b,(b+e)/2,l,r);
    ll q=update(n*2+1,(b+e)/2+1,e,l,r);
    return tree[n]=p+q;
}
int main()
{
    ///freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        sf1(n);
        for(ll i=0; i<n; i++)
        {
            ll a;
            sf1(a);
            value[i+1]=(a*a);
        }
        for(ll i=0; i<n-1; i++)
        {
            ll a,b;
            sf2(a,b);
            edj[a].PB(b);
            edj[b].PB(a);
        }
        cnt=0;
        dfs(1);
        for(ll i=1;i<=n;i++){
            ar[starting[i]]=value[i];
        }
        ll bu=build(1,1,n);
        ll q;
        sf1(q);
        for(ll i=0; i<q; i++)
        {
            ll a;
            sf1(a);
            if(a==1)
            {
                ll b,c;
                sf2(b,c);
                ar[starting[b]]=c*c;
                ll updat=update(1,1,n,starting[b],starting[b]);
            }
            else
            {
                ll b;
                sf1(b);
                ll ans=query(1,1,n,starting[b],ending[b]);
                printf("%lld\n",ans);
            }
        }
       // printf("%lld\n");
        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}



