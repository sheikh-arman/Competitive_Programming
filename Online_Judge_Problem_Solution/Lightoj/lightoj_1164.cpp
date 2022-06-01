#include<bits/stdc++.h>
#define nl printf("\n");
#define N 100101
#define mp pair<ll,ll>
#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d %d",&n,&m)
#define sfl(n) scanf("%lld", &n)
#define sfu(n) scanf("%llu", &n)
#define sffl(n, m) scanf("%lld %lld",&n,&m)
#define pfn(n) printf("%d\n",n)
#define pf(n) printf("%d ",n)
#define pfl(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define yes printf("YES\n")
#define no printf("NO\n")
#define pb push_back
#define pi 3.1415926536
#define vst(v) sort(v.begin(),v.end())
#define fori(n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<ll>v,v2,v3;
vector<ll> :: iterator it1,it2;
struct tree{
    ll sum,prop;
}s_tree[N*4];
int segmentTree(int n,int b,int e)
{
    if(b==e)
    {
       s_tree[n].sum=0;
       s_tree[n].prop=0;
       return 0;
    }
    int l=n*2;
    int r=n*2+1;
    int mid=(b+e)/2;
    segmentTree(l,b,mid);
    segmentTree(r,mid+1,e);
    s_tree[n].sum=0;
    s_tree[n].prop=0;
    return s_tree[n].sum;
}
ll query(int n,int b,int e,int i,int j,ll carry)
{
    if(b>j||e<i)
    {
        return 0;
    }
    if(b>=i&&e<=j)
    {
        return s_tree[n].sum+carry*(e-b+1);
    }
    int l=n*2;
    int r=(n*2) + 1;
    int mid=(e+b)/2;
    ll p=query(l,b,mid,i,j,carry+s_tree[n].prop);
    ll q=query(r,mid+1,e,i,j,carry+s_tree[n].prop);
    return p+q;
}
int update(int n,int b,int e,int x,int y,ll v){
    if(b>y||e<x)
    {
        return 0;
    }
    if(b>=x&&e<=y)
    {
       s_tree[n].sum+=((e-b+1)*v);
       s_tree[n].prop+=v;
       return s_tree[n].sum;
    }
    int l=n*2;
    int r=n*2+1;
    int mid=(b+e)/2;
    update(l,b,mid,x,y,v);
    update(r,mid+1,e,x,y,v);
    s_tree[n].sum=s_tree[l].sum+s_tree[r].sum + s_tree[n].prop*(e-b+1);
    return s_tree[n].sum;
}
int main()
{
    ///freopen("input.txt","r",stdin);
    ll tcase=1;
    int cnt=0;
    sf(tcase);
    while(tcase--)
    {
        //memset(ar,0,sizeof(ar));
        memset(s_tree,0,sizeof(s_tree));
        int n,q,a,b,c,l,r,v;
        ll ans;
        scanf("%d%d",&n,&q);
        segmentTree(1, 1, n);
        printf("Case %d:\n",++cnt);
        for(int i=0; i<q; i++)
        {
            scanf("%d",&a);
            if(a==0){
                scanf("%d%d%d",&l,&r,&v);
                update(1,1,n,l+1,r+1,v);
            }
            else{
                scanf("%d%d",&b,&c);
                 ans=query(1,1,n,b+1,c+1,0);
                printf("%lld\n",ans);
            }
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
