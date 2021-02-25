/*
    Sk arman Hossain
    University of Barisal

    Problem :   Lightoj 1080
    Solution : segment tree with lazy propagation
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
double PI = 2 * acos(0.0);
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
#define N 100010
ll SET(ll NUM,ll POS)
{
    return NUM | (1<<POS);
}
bool isOn(ll NUM,ll POS)
{
    return (bool)(NUM & (1<<POS));
}
ll tree[3*N],ar[N+10],n;
ll build(ll n,ll b,ll e)
{
    if(b==e)
    {
        return tree[n]=0;
    }
    ll l=n*2;
    ll r=n*2+1;
    ll mid=(b+e)/2;
    ll hi=build(l,b,mid);
    hi=build(r,mid+1,e);
    return tree[n]=0;
}
bool query(ll n,ll b,ll e,ll i,ll j,ll carry)
{
    if(b>j||e<i)
    {
        return false;
    }
    if(b>=i&&e<=j)
    {
        carry+=tree[n];
        carry%=2;
        if(carry==0)
        {
            return ar[i];
        }
        else
        {
            return !ar[i];
        }
    }
    ll l=n*2;
    ll r=(n*2) + 1;
    ll mid=(e+b)/2;
    ll tm=carry+tree[n];
    tm%=2;
    bool p=query(l,b,mid,i,j,tm);
    bool q=query(r,mid+1,e,i,j,tm);
    return p|q;
}
ll update(ll n,ll b,ll e,ll x,ll y)
{
    if(b>y||e<x)
    {
        return 0;
    }
    if(b>=x&&e<=y)
    {
        tree[n]+=1;
        return tree[n];
    }
    ll l=n*2;
    ll r=n*2+1;
    ll mid=(b+e)/2;
    ll hi= update(l,b,mid,x,y);
    hi=update(r,mid+1,e,x,y);
    return tree[n];
}

int main()
{
    fast;
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        string s;
        cin>>s;
        n=s.size();
        for(ll i=0; i<n; i++)
        {
            ar[i+1]=s[i]-'0';
        }
        ll x=build(1,1,n);
        ll q;
        cout<<"Case "<<test<<":\n";
        cin>>q;
        for(ll i=0; i<q; i++)
        {
            char c;
            cin>>c;
            if(c=='I')
            {
                ll a,b;
                cin>>a>>b;
                ll x=update(1,1,n,a,b);
            }
            else
            {
                ll a;
                cin>>a;
                bool ans=query(1,1,n,a,a,0);
                cout<<ans<<"\n";
            }
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

