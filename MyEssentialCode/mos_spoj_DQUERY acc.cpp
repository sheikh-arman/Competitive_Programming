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
#define maxn 31000
int a[maxn],Q,cnt[2001000],k;
struct query{
  int l, r, id;
} q[2001000];
;
bool cmp(query &a, query &b) {
  int block_a = a.l / k, block_b = b.l / k;
  if(block_a == block_b) return a.r < b.r;
  return block_a < block_b;
}
int l = 0, r = -1, sum = 0, ans[2001000];
void Add(int x) {
  x = a[x];
  cnt[x]++;
  if(cnt[x] == 1) sum++;
}
void Remove(int x) {
  x = a[x];
  cnt[x]--;
  if(cnt[x] == 0) sum--;
}
int main() {
  // do stuff, take input etc...
  int n,ax;
    sf(n);
    k=sqrt(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&ax);
        a[i]=ax;
    }
    sf(Q);
    for(int i = 0; i < Q; i++) {
            int x,y;
           sff(x,y);
        q[i].l=x-1;q[i].r=y-1;
       q[i].id = i;
  }
  sort(q, q+Q, cmp);
  for(int i = 0; i < Q; i++) {
    while(l > q[i].l) Add(--l);
    while(r < q[i].r) Add(++r);
    while(l < q[i].l) Remove(l++);
    while(r > q[i].r) Remove(r--);
    ans[q[i].id] = sum;
  }
  for(int i=0;i<Q;i++){
    printf("%d\n",ans[i]);
  }
///*****************************  ALHAMDULILLAH  *****************************/
}
