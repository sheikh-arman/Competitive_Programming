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
#define pb push_back
#define pi 3.1415926536
#define vst(v) sort(v.begin(),v.end())
#define fori(n) for(int i=0;i<n;i++)
//void FastIO() {ios_base:: sync_with_stdio(false); cin.tie(0); cout.precision(20);}
int dx[]= {0,0,1,1};
int dy[]= {1,1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<int>v,v3;
vector<int> :: iterator it1,it2;
int k,sum,ans[1000000];
class qu
{
public:
    int l,r,id;
};
vector<qu>query;
void Add(int x)
{
    sum+=v[x];
}
void Remove(int x)
{
    sum -= v[x];
}
bool cmp(qu a,qu b){
    int block_a=a.l/k;
    int block_b=b.l/k;
    if(block_a==block_b)
        return a.r<b.r;
    return block_a<block_b;

}
int main()
{
    ///freopen("input.txt","r",stdin);
    int tcase;
    ///while(1){
    int n,cnt=0,q,a,l=0,r=-1;
    sf(n);
    k=sqrt(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a);
        v.pb(a);
    }
    sf(q);
    for(int i=0; i<q; i++)
    {
        int l1,r1;
        sff(l1,r1);
        query.pb({l1,r1,i});
        //cout<<query[i].l<<endl;
    }
    sort(query.begin(),query.end(),cmp);
    for(int i=0; i<q; i++)
    {
        while(l>query[i].l)
            Add(--l);
        while(r<query[i].r)
            Add(++r);
        while(l<query[i].l)
            Remove(l++);
        while(r>query[i].r)
            Remove(r--);
        ans[query[i].id]=sum;
    }
    for(int i=0;i<q;i++){
        printf("%d %d\n",i+1,ans[i]);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

