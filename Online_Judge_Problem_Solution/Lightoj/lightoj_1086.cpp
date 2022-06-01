/*
    Sk arman Hossain
    University of Barisal

    Problem : lightoj 1086
    Solution : euler path + floyed warshal + bitmast dp
 */
#include<bits/stdc++.h>
#define nl cout<<"\n";
#define N 200001
#define PR pair<ll,ll>
#define sf1(n) cin>>n
#define sf2(n, m) cin>>n>>m
#define sf3(n, m,k ) cin>>n>>m>>k
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define minus1 printf("-1\n");
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTr(v) sort(v.begin(),v.end(),greater<long long int>())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
ll dis[20][20];
ll deg[20];
ll mem[20][1<<17],siz;
vector<ll>V;
ll bit_set(ll n,ll pos)
{
    return (n|(1<<pos));
}
bool bit_ck(ll n,ll pos)
{
    return (bool)(n&(1<<pos));
}
ll dp(ll i,ll mask)
{
    if(mask==(1<<siz)-1)
    {
        return 0;
    }
    if(mem[i][mask]!=-1)
    {
        return mem[i][mask];
    }
    ll ans=INT_MAX;
    for(ll j=0; j<siz; j++)
    {
        ll tm_mask=mask;
        if(i!=j)
        {
            if(!bit_ck(mask,j))
            {
                ll sum=dis[V[i]][V[j]];
                tm_mask=bit_set(mask,j);
                if(tm_mask!=(1<<siz)-1)
                {
                    for(ll k=0; k<siz; k++)
                    {
                        if(k!=j&&k!=i&&!bit_ck(tm_mask,k))
                        {
                            ll tm_mask2=bit_set(tm_mask,k);
                            ll xx=dp(k,tm_mask2)+dis[V[i]][V[j]];
                            ans=min(xx,ans);
                        }
                    }
                }
                else
                {
                    ans=min(ans,sum);
                }
                //cout<<""<<V[i]<<" "<<V[j]<<" "<<dis[V[i]][V[j]]<<" x\n";
            }
        }
    }
    //cout<<i<<" "<<mask<<" "<<ans<<" fu\n";
    return mem[i][mask]=ans;
}
int main()
{
    //  cout<<(1<<2);
    fast;
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        V.clear();
        ll n,m;
        cin>>n>>m;
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=n; j++)
            {
                dis[i][j]=INT_MAX;
            }
            deg[i]=0;
        }
        ll sum=0;
        for(ll i=0; i<m; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            dis[u][v]=min(w,dis[u][v]);
            dis[v][u]=dis[u][v];
            sum+=w;
            deg[u]++;
            deg[v]++;
        }
        for(ll k=1; k<=n; k++)
        {
            for(ll i=1; i<=n; i++)
            {
                for(ll j=1; j<=n; j++)
                {
                    ll tm=dis[i][k]+dis[k][j];
                    dis[i][j]=min(dis[i][j],tm);
                }
            }
        }
        for(ll i=1; i<=n; i++)
        {
            if(deg[i]%2!=0)
            {
                V.PB(i);
            }
        }
        siz=V.size();
        for(ll i=0; i<=siz; i++)
        {
            for(ll j=0; j<=(1<<siz); j++)
            {
                mem[i][j]=-1;
            }
        }
        ll ans=0;
        if(siz)
        {
            ans=dp(0,1);
        }
        ans+=sum;
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
/*
    1
    5 6
    1 2 3
    2 3 4
    3 4 5
    1 4 10
    1 3 12
    2 5 8

    ans=57



*/


