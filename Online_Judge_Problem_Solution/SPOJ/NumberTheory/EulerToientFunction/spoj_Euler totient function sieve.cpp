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
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
int dx[]= {0,0,1,1};
int dy[]= {1,1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
void totient(ll n,ll m)
{
    ll toten[m-n+2];
    ll totenvalue[m-n+2];
    for(ll i=0; i<=m-n; i++)
    {
        toten[i]=totenvalue[i]=i+n;
    }
    if(n==1)
        toten[0]=1;
    int sq=sqrt(m)+1;
    for(ll i=2; i<=sq; i++)
    {
        ll prime=i;
        ll base=(n/prime);
        base*=prime;
        if(base<n)
            base+=prime;
        for(ll j=base; j<=m; j+=prime)
        {
            if(totenvalue[j-n]%prime==0&&totenvalue[j-n]>=prime)
            {
                ll tem=totenvalue[j-n];
                while(totenvalue[j-n]%prime==0)
                {
                    totenvalue[j-n]/=prime;
                }
                toten[j-n]-=toten[j-n]/prime;
            }

        }
    }
    for(ll i=0; i<=m-n; i++)
    {
        if(totenvalue[i]>1)
        {
            toten[i]-=toten[i]/totenvalue[i];
        }
        printf("%lld\n",toten[i]);
    }
}
int main()
{
    ///freopen("input.txt","r",stdin);
    ll n,m;
    sffl(n,m);
    totient(n,m);
///*****************************  ALHAMDULILLAH  *****************************/
}

