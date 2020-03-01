/*
    Sk arman Hossain
    University of Barisal

    Problem name : dev skill DCP-19: Multiplication Interval
    Algorithm : segment tree
 */
#include<bits/stdc++.h>
#define nl printf("\n");
#define N 100101
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
ll ar[N],ar_for_1[N];
struct st
{
    ll val;
    ll pos;
};
st count_1[N*4],s_tree[N*4];
st MAX(st a,st b)
{
    if(a.val>=b.val)
    {
        return a;
    }
    else
    {
        return b;
    }
}
st MIN(st a,st b)
{
    if(a.val<=b.val)
    {
        return a;
    }
    else
    {
        return b;
    }
}
st segmentTree(ll n,ll b,ll e)
{
    if(b==e)
    {
        s_tree[n].val=ar[b];
        s_tree[n].pos=b;
        return s_tree[n];
    }
    ll l=n*2;
    ll r=n*2+1;
    ll mid=(b+e)/2;
    st p=segmentTree(l,b,mid);
    st q=segmentTree(r,mid+1,e);
    s_tree[n]=MIN(p,q);
    return s_tree[n];
}
st query(ll n,ll b,ll e,ll i,ll j)
{
    if(b>j||e<i)
    {
        st xx;
        xx.val=LONG_MAX;
        xx.pos=0;
        return xx;
    }
    if(b>=i&&e<=j)
    {
        return s_tree[n];
    }
    ll l=n*2;
    ll r=(n*2) + 1;
    ll mid=(e+b)/2;
    st p=query(l,b,mid,i,j);
    st q=query(r,mid+1,e,i,j);
    return MIN(p,q);
}
st segmentTree_for_1(ll n,ll b,ll e)
{
    if(b==e)
    {
        count_1[n].val=ar_for_1[b];
        count_1[n].pos=b;
        return count_1[n];
    }
    ll l=n*2;
    ll r=n*2+1;
    ll mid=(b+e)/2;
    st p=segmentTree_for_1(l,b,mid);
    st q=segmentTree_for_1(r,mid+1,e);
    count_1[n]=MAX(p,q);
    return count_1[n];
}
st query_for_1(ll n,ll b,ll e,ll i,ll j)
{
    if(b>j||e<i)
    {
        st xx;
        xx.val=INT_MIN;
        xx.pos=0;
        return xx;
    }
    if(b>=i&&e<=j)
    {
        ll tm=count_1[n].pos;
        ll value=count_1[n].val;
        ll dif=abs(i-tm)+1;
        count_1[n].val=min(value,dif);
        return count_1[n];
    }
    ll l=n*2;
    ll r=(n*2) + 1;
    ll mid=(e+b)/2;
    st p=query_for_1(l,b,mid,i,j);
    st q=query_for_1(r,mid+1,e,i,j);
    return MAX(p,q);
}
int main()
{
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    sf1(tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n,q,a,b;
        scanf("%lld%lld",&n,&q);
        ll cnt=0;
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&ar[i]);
            if(ar[i]==1)
            {
                cnt++;
                ar_for_1[i]=cnt;
            }
            else
            {
                cnt=0;
                ar_for_1[i]=0;
            }
        }
        st x2=segmentTree(1, 1, n);
        x2=segmentTree_for_1(1, 1, n);
        printf("Case %lld:\n",test);
        for(ll i=0; i<q; i++)
        {
            scanf("%lld%lld",&a,&b);
            st x=query(1,1,n,a,b);
            if(x.val==0)
            {
                printf("0 %lld %lld\n",a,b);
            }
            else if(x.val==1)
            {
                st tm=query_for_1(1,1,n,a,b);
                ll ans=tm.pos;
                printf("1 %lld %lld\n",(ll)(ans-tm.val+1),ans);
            }
            else
            {
                ll ans=x.pos;
                printf("%lld %lld %lld\n",x.val,ans,ans);
            }
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
//test
//1
//8 1
//1 2 1 1 2 1 1 5
//4 7
//Case 1:
//1 6 7


