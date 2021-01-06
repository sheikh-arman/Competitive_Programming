/*
    Sk arman Hossain
    University of Barisal
    Problem name :
    Algorithm :
 */
#include<bits/stdc++.h>
#define nl printf("\n");
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
typedef long long int ll;
typedef unsigned long long int ull;
ll dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
ll dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
using namespace std;
#define N 200100
vector<ll>edj[N];
bool color[N];
ll label[N];
ll sparse[N][20];
ll parent[N];
ll pre_cal_sub[N];
ll pre_cal_add[N];
void dfs(ll node)
{
    color[node]=false;
    ll siz=edj[node].size();
    for(ll i=0; i<siz; i++)
    {
        ll tm=edj[node][i];
        if(color[tm]==true)
        {
            color[tm]=false;
            label[tm]=label[node]+1;
            parent[tm]=node;
            sparse[tm][0]=node;
            dfs(tm);
        }
    }
}
void pre_process(ll n)
{
    for(ll j=1; (1<<j)<=n; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            sparse[i][j]=sparse[sparse[i][j-1]][j-1];
        }
    }
}
ll query(ll u,ll v)
{
    if(label[u]<label[v])
        swap(u,v);
    ll lg=0;
    for(lg=0; (1<<lg)<=label[u]; lg++)
    {

    }
    lg--;
    if(label[u]!=label[v])
    {
        for(ll i=lg; i>=0; i--)
        {
            if(label[u]-(1<<i)>=label[v])
            {
                u=sparse[u][i];
            }
        }
    }
    //printf("%lld %lld p\n",label[u],label[v]);
    if(u==v)
    {
        return u;
    }
   // printf("%lld %lld t\n",label[u],label[v]);
    for(ll i=lg; i>=0; i--)
    {
        if(sparse[u][i]!=-1&&sparse[u][i]!=sparse[v][i])
        {
            u=sparse[u][i];
            v=sparse[v][i];
        }
    }
    return parent[u];

}
ll nth_parent(ll u,ll nth)
{
    ll lg=0;
    for(lg=0; (1<<lg)<=label[u]; lg++)
    {

    }
    lg--;
    ll nth_parent_label=nth;
    if(label[u]!=nth_parent_label)
    {
        for(ll i=lg; i>=0; i--)
        {
            if(label[u]-(1<<i)>=nth_parent_label)
            {
                u=sparse[u][i];
            }
        }
    }
    return u;
}
ll sum=0;
ll res[N];
bitset<200010>ck;
void sol(ll node,ll add,ll sub){
    add+=pre_cal_add[node];
    sub+=pre_cal_sub[node];
    res[node]+=sum;
    res[node]+=add;
    res[node]-=sub;
    ck[node]=1;
    for(ll i:edj[node]){
        if(ck[i]==0){
            ck[i]=1;
            sol(i,add,sub);
        }
    }
}
int main()
{
    // fast;
    //freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,e;
        sf1(n);
        for(ll i=0;i<=n;i++){
            edj[i].clear();
            color[i]=true;
            label[i]=-1;
            memset(sparse[i],-1,sizeof(sparse[i]));
        }
        vector<PR>V;
        for(ll i=0; i<n-1; i++)
        {
            ll u,v;
            sf2(u,v);
            edj[u].PB(v);
            edj[v].PB(u);
            V.PB({u,v});
        }
        label[1]=0;
        parent[1]=1;
        dfs(1);
        pre_process(n);
        ll qq;
        //printf("Case %lld:\n",test);
        sf1(qq);
        sum=0;
        for(ll i=0; i<qq; i++)
        {
            ll st,e_no,val,u,v;
            sf1(st);
            sf2(e_no,val);
            if(st==1){
                u=V[e_no-1].first;
                v=V[e_no-1].second;
            }
            else{
                v=V[e_no-1].first;
                u=V[e_no-1].second;
            }
            ll lc=query(u,v);
            if(lc==u||lc==v){
                if(lc==u){
                    pre_cal_sub[v]+=val;
                    sum+=val;
                }
                else{
                    ll nth_pa=nth_parent(u,label[v]+1);
                    pre_cal_add[nth_pa]+=val;
                }
            }
            else{
                pre_cal_sub[v]+=val;
                sum+=val;
            }
        }
        sol(1,pre_cal_add[1],pre_cal_sub[1]);
        for(ll i=1;i<=n;i++){
            printf("%lld\n",res[i]);
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
