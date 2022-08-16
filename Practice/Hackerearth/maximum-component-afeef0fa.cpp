/*
    Sk arman Hossain
    University of Barisal

    Problem name : https://www.codechef.com/problems/TREETR
    Algorithm : graph_linear with dfs + segment tree
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
#define N 400005

ll ar[N+10];
ll rep[N+10];
ll cnt[N+10];
class seg
{
public:
    ll val,cnt;
};
seg tree[(4*N)+10];
ll Find(ll node)
{
    return (rep[node]==node?node:rep[node]=Find(rep[node]));
}
ll build(ll n,ll b,ll e)
{
    if(b==e)
    {
        tree[n].cnt=ar[b];
        return tree[n].val=b*tree[n].cnt;
    }
    ll p=build(n*2,b,(b+e)/2);
    ll q=build(n*2+1,(b+e)/2+1,e);
    tree[n].cnt=tree[n*2].cnt+tree[(n*2)+1].cnt;
    return tree[n].val=p+q;
}
ll query(ll n,ll b,ll e,ll cnt)
{
    if(cnt<=0)return 0;
    if(b==e)
    {
        return cnt*b;
    }
    ll left_va=tree[n*2].cnt;
    ll right_va=tree[(n*2)+1].cnt;
    ll ans=0;
    if(cnt>=right_va)
    {
        ans+=tree[(n*2)+1].val;
        ans+=query(n*2,b,(b+e)/2,cnt-right_va);
    }
    else
    {
        ans+=query(n*2+1,(b+e)/2+1,e,cnt);
    }
    return ans;
}
ll update(ll n,ll b,ll e,ll l,ll r)
{
    if(b>=l&&e<=r)
    {
        tree[n].cnt=ar[b];
        return tree[n].val=b*tree[n].cnt;
    }
    else if(e<l||b>r)
    {
        return tree[n].val;
    }
    ll p=update(n*2,b,(b+e)/2,l,r);
    ll q=update(n*2+1,(b+e)/2+1,e,l,r);
    tree[n].cnt=tree[n*2].cnt+tree[(n*2)+1].cnt;
    return tree[n].val=p+q;
}
ll n,m;
int main()
{
    ///freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    for(ll test=1; test<=tcase; test++)
    {

        sf2(n,m);
        for(ll i=0; i<=n; i++)
        {
            ar[i]=0;
            rep[i]=i;
            cnt[i]=1;
        }
        ar[1]=n;
        ll x=build(1,1,n);
        ll sum=n-1;
        for(ll i=1; i<=m; i++)
        {
            ll a;
            sf1(a);
            if(a==1)
            {
                ll u,v;
                sf2(u,v);
                u=Find(u);
                v=Find(v);
                if(u==v)continue;
                sum--;
                if(cnt[u]>cnt[v])swap(u,v);
                rep[u]=v;
                ll cntu=cnt[u];
                ll cntv=cnt[v];
                cnt[v]+=cnt[u];
                cnt[u]=0;

                ar[cntu]-=1;
                x=update(1,1,n,cntu,cntu);
                ar[cntv]-=1;
                x=update(1,1,n,cntv,cntv);
                cntv=cnt[v];
                ar[cntv]+=1;
                x=update(1,1,n,cntv,cntv);
            }
            else
            {
                ll k;
                sf1(k);
                if(k>=sum)
                {
                    printf("%lld\n",n);
                }
                else
                {
                    ll ans=query(1,1,n,k+1);
                    printf("%lld\n",ans);
                }
            }
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
