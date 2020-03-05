
/*
    Sk arman Hossain
    University of Barisal

    Problem name : toph Answer the Queries
    Algorithm : Segment Tree + Binary Search
 */
#include<bits/stdc++.h>
#define nl printf("\n");
#define N 20001
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
vector<ll>cnt_pos[200010];
vector<ll>cnt_neg[200010];
ll s_tree[N*3],ar[N];
ll segmentTree(ll n,ll b,ll e)
{
    if(b==e)
    {
       s_tree[n]=ar[b];
       return ar[b];
    }
    ll l=n*2;
    ll r=n*2+1;
    ll mid=(b+e)/2;
    segmentTree(l,b,mid);
    segmentTree(r,mid+1,e);
    s_tree[n]=max(s_tree[l],s_tree[r]);
    return s_tree[n];
}
ll query(ll n,ll b,ll e,ll i,ll j)
{
    if(b>j||e<i)
    {
        return INT_MIN;
    }
    if(b>=i&&e<=j)
    {
        return s_tree[n];
    }
    ll l=n*2;
    ll r=(n*2) + 1;
    ll mid=(e+b)/2;
    ll p=query(l,b,mid,i,j);
    ll q=query(r,mid+1,e,i,j);
    return max(p,q);
}
int main()
{
    // fast;
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    sf1(tcase);
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        for(ll i=0;i<=200000;i++){
            cnt_neg[i].clear();
            cnt_pos[i].clear();
        }
        ll n,q,a,b;
        scanf("%lld%lld",&n,&q);

        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&ar[i]);
            if(ar[i]<0){
                ll tm=abs(ar[i]);
                cnt_neg[tm].PB(i);
            }
            else{
                cnt_pos[ar[i]].PB(i);
            }
        }
        segmentTree(1, 1, n);
        printf("Case %lld:\n",test);
        for(ll i=0; i<q; i++)
        {
            ll ans;
            scanf("%lld%lld",&a,&b);
            a++;b++;
            ll x=query(1,1,n,a,b);
            if(x<0){
                x=abs(x);
                ll pos1=lower_bound(cnt_neg[x].begin(),cnt_neg[x].end(),a)-cnt_neg[x].begin();
                ll pos2=upper_bound(cnt_neg[x].begin(),cnt_neg[x].end(),b)-cnt_neg[x].begin();
                ans=pos2-pos1;
            }
            else{

                ll pos1=lower_bound(cnt_pos[x].begin(),cnt_pos[x].end(),a)-cnt_pos[x].begin();
                ll pos2=upper_bound(cnt_pos[x].begin(),cnt_pos[x].end(),b)-cnt_pos[x].begin();
            //printf("%lld %lld %lld %lld %lld \n",x,pos1,pos2,cnt_pos[x][pos1],cnt_pos[x][pos2]);
                ans=pos2-pos1;
            }
            printf("%lld\n",ans);
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

