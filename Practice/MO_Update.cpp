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
#define maxn 110000
int a[101000],Q,cnt[101000];
const int k = 5500;
struct query
{
    int l, r, t, id;
} q[100100];
struct update
{
    int x, pre, now;
} u[100100];
//bool cmp(query &a, query &b)
//{
//    int block_a = a.l / k, block_b = b.l / k;
//    if(block_a == block_b) return a.r < b.r;
//    return block_a < block_b;
//}
bool cmp(query &a, query &b)
{
    int l1 = a.l / k, l2 = b.l / k,
        r1 = a.r / k, r2 = b.r / k;
    // Left blocks differ, they aren't in same group,
    // first comes who have smaller left block.
    if(l1 != l2) return l1 < l2;
    // So here we have same Left Block, but if Right Blocks aren't equal,
    // then who have right block smaller comes first.
    if(r1 != r2) return r1 < r2;
    // Now we have l1 == l2 and r1 == r2,
    // So both a and b query is in same group,
    // sort them based on time.
    return a.t < b.t;
}
int l = 0, r = -1, t=0,angry[101000],last[101000];
ll sum,ans[101000];
void Add(int x)
{

    x = a[x];
    ll an=x;
    an*=angry[cnt[x]];
    sum-=an;
    cnt[x]++;
    an=x;
    an*=angry[cnt[x]];
    sum+=an;
    //cout<<sum<<" x\n";
}
void Remove(int x)
{

    x = a[x];
    ll an=x;
    an*=angry[cnt[x]];
    sum-=an;
    cnt[x]--;
    an=x;
    an*=angry[cnt[x]];
    sum+=an;
}
void apply(int x, int y)
{
    if(l <= x && x <= r)    // l, r is the l, r from MO's algo
    {
        Remove(x);
        a[x] = y;
        Add(x);
    }
    else a[x] = y;
}
int main()
{
    // do stuff, take input etc...
    int n;
    sf(n);
    //k=sqrt(n);
    for(int i=0; i<n; i++)
    {
        sf(a[i]);
        last[i]=a[i];
    }
    for(int i=1; i<=n; i++)
    {
        sf(angry[i]);
        angry[i]+=angry[i-1];
    }
    sf(Q);
    int cnt_up=0,id=0,idx=0;
    for(int i = 0; i < Q; i++)
    {
        int typ;
        sf(typ);
        if(typ==1)
        {
            int x,y;
            sff(x,y);
            q[id].l = x-1;
            q[id].r = y-1;
            q[id].id = id;
            q[id].t = idx;
            id++;
        }
        else
        {
            int x,y;
            sff(x,y);
            x--;
            u[++idx] = {x, last[x], y};
            last[x] = y;
        }
    }
    Q=id;
    sort(q, q+Q, cmp);
    for(int i = 0; i < Q; i++)
    {
        while(t < q[i].t) t++, apply(u[t].x, u[t].now); // Forward Update
        while(t > q[i].t) apply(u[t].x, u[t].pre), t--; // Reverse Update
        while(l > q[i].l) Add(--l);
        while(r < q[i].r) Add(++r);
        while(l < q[i].l) Remove(l++);
        while(r > q[i].r) Remove(r--);
        ans[q[i].id] = sum;
    }
    //cout<<Q<<" x\n";
    for(int i=0; i<Q; i++)
    {
        printf("%lld\n",ans[i]);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
