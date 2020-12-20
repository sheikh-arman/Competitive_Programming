/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
#define nl cout<<"\n";
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
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define T(n) printf("test %d\n",n)
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
#define mod 1000000007
vector<ll>prime;
void seive()
{
    prime.PB(2);
    bitset<46440>ck;
    for(ll i=3; i<=46350; i+=2)
    {
        if(ck[i]==false)
        {
            prime.PB(i);
            for(ll j=i*i; j<=46350; j+=(i+i))
            {
                ck[j]=true;
            }
        }
    }
}
ll extended_euclidean(ll a, ll b, ll& x, ll& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
ll bigmod(ll n,ll po)
{
    if(po==0)
    {
        return 1;
    }
    if(po==1)
    {
        return n;
    }
    if(po%2==0)
    {
        ll p=bigmod(n,po/2);
        return ((p%mod)*(p%mod))%mod;
    }
    else
    {
        return ((bigmod(n,po-1)*n)%mod);
    }
}
ll fac(ll n,ll k)
{
    ll siz=prime.size();
    ll sq=sqrt(n+1);
    ll ans=1;
    for(ll i=0; i<siz&&prime[i]<=sq; i++)
    {
        if(n%prime[i]==0)
        {
            ll cnt=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }
            cnt*=k;
            ll x,y;
            ll g = extended_euclidean(prime[i]-1, mod, x, y);
            x = (x % mod + mod) % mod;
            ll tm=(((bigmod(prime[i],cnt+1)-1+mod)%mod)*(x%mod))%mod;
            ans=((ans%mod)*(tm%mod))%mod;
        }
        sq=sqrt(n);
    }
    if(n>1)
    {
        ll x,y;
        ll g = extended_euclidean(n-1, mod, x, y);
        x = (x % mod + mod) % mod;
        ll tm=(((bigmod(n,k+1)-1+mod)%mod)*(x%mod))%mod;
        ans=((ans%mod)*(tm%mod))%mod;
    }
    return ans;
}
int main()
{
    seive();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=100;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,k;
        cin>>n>>k;
        ll ans=fac(n,k);
        cout<<"Case "<<test<<": "<<ans<<endl;
    }
///*****************************  ALHAMDULILLAH  *****************************/
}



