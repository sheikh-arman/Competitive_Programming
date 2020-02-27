#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
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

int s_tree[200001*3],ar[200001];
int segmentTree(int n,int b,int e)
{
    if(b==e)
    {
       s_tree[n]=ar[b];
       return ar[b];
    }
    int l=n*2;
    int r=n*2+1;
    int mid=(b+e)/2;
    segmentTree(l,b,mid);
    segmentTree(r,mid+1,e);
    s_tree[n]=min(s_tree[l],s_tree[r]);
    return s_tree[n];
}
int query(int n,int b,int e,int i,int j)
{
    if(b>j||e<i)
    {
        return INT_MAX;
    }
    if(b>=i&&e<=j)
    {
        return s_tree[n];
    }
    int l=n*2;
    int r=(n*2) + 1;
    int mid=(e+b)/2;
    int p=query(l,b,mid,i,j);
    int q=query(r,mid+1,e,i,j);
    return min(p,q);
}
int main()
{
    ///freopen("input.txt","r",stdin);
    ll tcase=1;
    int cnt=0;
    sf(tcase);
    while(tcase--)
    {
        memset(ar,0,sizeof(ar));
        memset(s_tree,0,sizeof(s_tree));
        int n,q,a,b;
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&ar[i]);
        }
        segmentTree(1, 1, n);
        printf("Case %d:\n",++cnt);
        for(int i=0; i<q; i++)
        {
            scanf("%d%d",&a,&b);
            int x=query(1,1,n,a,b);
            printf("%d\n",x);
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

