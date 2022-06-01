/*
    Sk arman Hossain
    University of Barisal

    Problem name :
    Algorithm :
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
//ll big_mod(ll base,ll power,ll Mod){if(power==0){return 1;}else if(power%2==1){ll p1=base%Mod;ll p2=(big_mod(base,power-1,Mod))%Mod;return (p1*p2)%Mod;}else if(power%2==0){ll p1=(big_mod(base,power/2,Mod))%mod;return (p1*p1)%Mod;}}
class PAIR
{
public:
    ll first;
    ll second;
    ll third;
};



//vector<ll>prime_list;
//bool prime_ck[10000001];
//void seive()
//{
//    prime_ck[0]=prime_ck[1]=1;
//    prime_list.push_back(2);
//    for(int i=4; i<=100000; i+=2)
//    {
//        prime_ck[i]=1;
//    }
//    for(int i=3; i<=100000; i+=2)
//    {
//        if(prime_ck[i]==0)
//        {
//            prime_list.push_back(i);
//            for(int j=i+i; j<=100000; j+=i+i)
//            {
//                prime_ck[j]=1;
//            }
//        }
//    }
//}


//bool operator<(const nod& t1, const nod& t2)
//{
//    return (t1.x1 < t2.x1||t1.y1<t2.y1);
//}


/*
int rep[200010];
void initial(int n){
    for(int i=1;i<=n;i++){
        rep[i]=i;
    }
}
int find_representative(int node){
    if(rep[node]==node){
        return node;
    }
    else{
        rep[node]=find_representative(rep[node]);
        return rep[node];
    }
}
void joint_node(int nodex,int nodey){
    int u=find_representative(nodex);
    int v=find_representative(nodey);
    if(u!=v){
        rep[u]=v;
    }
}
*/
/*
vector<ll>nod[200100],V3;
ll label[200100]={-1};
void dfs(ll node){
    for(ll i=0;i<nod[node].size();i++){
        ll x=nod[node][i];
        if(label[x]==-1){
            label[x]=label[node]+1;
            dfs(x);
        }
    }
}
*/
/*
vector<ll>nod[200100],v3;
ll label[200100]={-1};
void bfs(ll node){
    memset(label,-1,sizeof(label));
    queue<ll>q;
    q.push(node);
    while(!q.empty()){
        ll x;
        x=q.front();
        q.pop();
        ll siz=nod[x].size();
        for(ll i=0;i<siz;i++){
            ll tmp=nod[x][i];
            if(label[tmp]==-1){
                label[tmp]=label[x]+1;
                q.push(tmp);
            }
        }
    }
}

void graph_input(ll edge){
    for(ll i=0;i<edge;i++){
        ll a,b;
        scanf("%lld %lld",&a,&b);
        nod[a].push_back(b);
        nod[b].push_back(a);
    }
}*/
//
//bool cmp(ll a,ll b){
//    return a<b;
//}
//
vector<ll>V,V2,V3;
//bool cmp(PR a,PR b){
//    if(a.first!=b.first){
//        return a.first<b.first;
//    }
//    if(a.second!=b.second){
//        return a.second<b.second;
//    }
//
//}
//emplace_back()

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
    s_tree[n]=min(s_tree[l],s_tree[r]);
    return s_tree[n];
}
ll query(ll n,ll b,ll e,ll i,ll j)
{
    if(b>j||e<i)
    {
        return INT_MAX;
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
    return min(p,q);
}
int main()
{
    ///freopen("input.txt","r",stdin);
    ll tcase=1;
    ll cnt=0;
    sf1(tcase);
    while(tcase--)
    {
        memset(ar,0,sizeof(ar));
        memset(s_tree,0,sizeof(s_tree));
        ll n,q,a,b;
        scanf("%lld%lld",&n,&q);
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&ar[i]);
        }
        segmentTree(1, 1, n);
        printf("Case %lld:\n",++cnt);
        for(int i=0; i<q; i++)
        {
            scanf("%lld%lld",&a,&b);
            ll x=query(1,1,n,a,b);
            printf("%lld\n",x);
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

