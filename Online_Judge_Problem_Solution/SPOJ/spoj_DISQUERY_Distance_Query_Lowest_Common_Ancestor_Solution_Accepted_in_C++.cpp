

/*
    Sk arman Hossain
    University of Barisal

    Problem name : Spoj LCA
    Algorithm : Lowest Common Ancestor
 */
#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define PR pair<ll,ll>
#define sf1(n) scanf("%lld", &n)
#define sf2(n, m) scanf("%lld %lld",&n,&m)
#define sf3(n, m,k ) scanf("%lld %lld %lld",&n,&m,&k)
#define pfn(n) printf("%d\n",n)
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
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<ll>edge[100010],position[100010],euler;
ll parent[100010];
ll cnt=0;
map<PR,ll>edj;
struct stt
{
    ll fir;
    ll sec;
} Tree[310010];

vector<ll>dis_euler;
ll LCA_Tree[310010];
ll map_labeling_pos[100010];
ll map_labeling_val[100010];
ll first[100010];
void dfs(ll node)
{
    cnt++;
    ll m=euler.size();
    map_labeling_pos[node]=m;
    map_labeling_val[m]=node;
    ll siz=edge[node].size();
    first[m]=euler.size();
    euler.PB(m);
    dis_euler.PB(edj[ {node,parent[node]}]);
    for(ll i=0; i<siz; i++)
    {
        if(parent[edge[node][i]]==-1)
        {
            //label[edge[node][i]]=label[node]+1;
            parent[edge[node][i]]=node;
            dfs(edge[node][i]);
            euler.PB(m);
            dis_euler.PB(edj[ {edge[node][i],node}]);
        }
    }
}
ll build(ll n,ll b, ll e)
{
    if(b==e)
    {
        LCA_Tree[n]=euler[b-1];
        return LCA_Tree[n];
    }
    ll left=n*2;
    ll right=n*2+1;
    ll mid=(b+e)/2;
    ll p=build(left,b,mid);
    ll q=build(right,mid+1,e);
    LCA_Tree[n]=min(p,q);
    return LCA_Tree[n];
}
ll query(ll n,ll b,ll e,ll l,ll r)
{
    if(e<l||b>r)
    {
        return LONG_MAX;
    }
    if(b>=l&&e<=r)
    {
        return LCA_Tree[n];
    }
    ll left=n*2;
    ll right=n*2+1;
    ll mid=(b+e)/2;
    ll p=query(left,b,mid,l,r);
    ll q=query(right,mid+1,e,l,r);
    return min(p,q);
}

stt dis_build(ll n,ll b, ll e)
{
    if(b==e)
    {
        if(b==1)
        {
            Tree[n].fir=LONG_MAX;
            Tree[n].sec=LONG_MIN;
        }
        else
        {
            Tree[n].fir=dis_euler[b-1];
            Tree[n].sec=dis_euler[b-1];
        }

        return Tree[n];
    }
    ll left=n*2;
    ll right=n*2+1;
    ll mid=(b+e)/2;
    stt p=dis_build(left,b,mid);
    stt q=dis_build(right,mid+1,e);
    Tree[n].fir=min(p.fir,q.fir);
    Tree[n].sec=max(p.sec,q.sec);
    return Tree[n];
}
stt dis_query(ll n,ll b,ll e,ll l,ll r)
{
    if(e<l||b>r)
    {
        stt st;
        st.fir=LONG_MAX;
        st.sec=LONG_MIN;
        return st;
    }
    if(b>=l&&e<=r)
    {
        return Tree[n];
    }
    ll left=n*2;
    ll right=n*2+1;
    ll mid=(b+e)/2;
    stt p=dis_query(left,b,mid,l,r);
    stt q=dis_query(right,mid+1,e,l,r);
    stt ss;
    ss.fir=min(p.fir,q.fir);
    ss.sec=max(p.sec,q.sec);
    return ss;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        sf1(n);
        for(ll i=0; i<=n; i++)
        {
            parent[i]=-1;
        }
        for(ll i=0; i<n-1; i++)
        {
            ll a,b,c;
            sf3(a,b,c);
            edge[a].PB(b);
            edge[b].PB(a);
            edj[ {a,b}]=c;
            edj[ {b,a}]=c;
        }
        edj[ {1,1}]=0;
        parent[1]=1;
        dfs(1);
        ll xx=build(1,1,euler.size());
        stt xx2=dis_build(1,1,euler.size());
        ll q;
        printf("Case %lld:\n",test);
        sf1(q);
        for(ll i=0; i<q; i++)
        {
            ll a,b;
            sf2(a,b);
            ll l=first[map_labeling_pos[a]];
            ll r=first[map_labeling_pos[b]];
            if(l>r)swap(l,r);
            ll ans=query(1,1,euler.size(),l+1,r+1);
            ans=map_labeling_val[ans];
            ll lca=first[map_labeling_pos[ans]];
            stt an=dis_query(1,1,dis_euler.size(),lca+1,l+1);
            stt an2=dis_query(1,1,dis_euler.size(),lca+1,r+1);
            printf("%lld %lld\n",min(an.fir,an2.fir),max(an.sec,an2.sec));
        }

        // printf("%d\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


