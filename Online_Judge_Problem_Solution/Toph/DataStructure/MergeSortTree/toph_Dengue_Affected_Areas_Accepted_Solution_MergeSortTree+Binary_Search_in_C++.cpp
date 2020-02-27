/*
    Sk arman Hossain
    University of Barisal

    Problem name : toph Dengue Affected Areas
    Algorithm : MergeSortTree+BinarySearch
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
vector<ll>tree[500010];
ll ar[100010];
ll mi,ma,ans;
void merg(vector<ll>v1,vector<ll>v2,ll n)
{
    ll siz1=v1.size();
    ll siz2=v2.size();
    ll left=0,right=0;
    tree[n].clear();
    while(left<siz1&&right<siz2)
    {
        if(v1[left]<=v2[right])
        {
            tree[n].PB(v1[left]);
            left++;
        }
        else
        {
            tree[n].PB(v2[right]);
            right++;
        }
    }
    while(left<siz1)
    {
        tree[n].PB(v1[left]);
        left++;
    }
    while(right<siz2)
    {
        tree[n].PB(v2[right]);
        right++;
    }
}
ll build(ll n,ll b,ll e)
{
    if(b==e)
    {
        tree[n].PB(ar[b]);
        return 0;
    }
    ll left=2*n;
    ll right=2*n+1;
    ll mid=(b+e)/2;
    ll p=build(left,b,mid);
    ll q=build(right,mid+1,e);
    merg(tree[left],tree[right],n);
    return 1;
}
ll query(ll n,ll b,ll e,ll i,ll j,ll p,ll q)
{
    if(b>j||e<i)
    {
        return 0;
    }
    if(b>=i&&e<=j)
    {
        ll pos=lower_bound(tree[n].begin(),tree[n].end(),p)-tree[n].begin();
        ll pos2=upper_bound(tree[n].begin(),tree[n].end(),q)-tree[n].begin();
        //printf("%lld %lld\n",pos,pos2);
        ll siz=tree[n].size();

        if(pos<siz)
        {

            if(pos2==siz)
            {
                pos2--;
            }
            if(tree[n][pos2]>q)
            {
                pos2--;
            }
            if(pos2-pos+1>0)
            {
                ma=max(tree[n][pos2],ma);
                mi=min(tree[n][pos],mi);
            }
            ans+=pos2-pos+1;
        }
        return 0;
    }
    ll left=2*n;
    ll right=2*n+1;
    ll mid=(b+e)/2;
    ll xx=query(left,b,mid,i,j,p,q);
    ll yy=query(right,mid+1,e,i,j,p,q);
    return 1;
}
int main()
{
    ///freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n,q;
        sf2(n,q);
        for(ll i=0; i<n; i++)
        {
            ll a;
            sf1(a);
            ar[i+1]=a;
        }
        ll tt=build(1,1,n);
        for(ll i=0; i<q; i++)
        {
            ma=-1;
            mi=LONG_MAX;
            ans=0;
            ll a,b,c,d;
            sf2(a,b);
            sf2(c,d);
            ll ttt=query(1,1,n,a,b,c,d);
            if(mi==LONG_MAX)mi=-1;
            printf("%lld %lld %lld\n",ans,mi,ma);
        }
        //printf("%lld\n");
        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


