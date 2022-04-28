#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define sf(n) scanf("%lld",&n);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define nl cout<<"\n";
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
#define MAX 2000010
#define T(n) printf("test : %d\n",n);
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
ll mem[100010][3];
ll mem_conjecutive[100010][3];
ll mod=1e9+7;
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
int main()
{
    mem[1][0]=1;
    // mem_conjecutive[1][0]=1;
    // mem_conjecutive[1][1]=1;
    for(ll i=2; i<=100000; i++)
    {
        mem[i][0]+=mem[i-1][0]+mem[i-1][1];
        mem[i][0]%=mod;
        mem[i][1]+=mem[i-1][0]+mem[i-1][1];
        mem[i][1]%=mod;
    }
    ///generate Set of P where No consecutive A
    mem_conjecutive[1][0]=1;
    for(ll i=2; i<=100000; i++)
    {
        mem_conjecutive[i][0]=mem_conjecutive[i-1][1];
        mem_conjecutive[i][1]=mem_conjecutive[i-1][1]+mem_conjecutive[i-1][0];
        mem_conjecutive[i][0]%=mod;
        mem_conjecutive[i][1]%=mod;
    }
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,sum=0;
        cin>>n;
        ll x, y;
        ll m=mod;
        ll total_count=mem[n][0]+mem[n][1];
        total_count%=m;
        ll without_Conjecutive=mem_conjecutive[n][0]+mem_conjecutive[n][1];
        without_Conjecutive%=m;
        ll with_Conjecutive=total_count-without_Conjecutive;
        with_Conjecutive+=m;
        with_Conjecutive%=m;
        ll gcd=__gcd(total_count,with_Conjecutive);
        total_count/=gcd;
        with_Conjecutive/=gcd;
        ll g = extended_euclidean(total_count, m, x, y);
        x = (x + m) % m;
        x*= with_Conjecutive;
        x%=m;
        cout<<x<<"\n";
    }
    return 0;
}




