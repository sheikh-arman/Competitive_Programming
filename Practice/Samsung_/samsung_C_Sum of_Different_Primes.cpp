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
#define MAX 1125
#define T(n) printf("test : %d\n",n);
ll mem[1130][16];
bitset<1130>prime;
void seive()
{
    prime.set();
    prime[0]=0;
    prime[1]=0;
    for(ll i=4; i<1125; i+=2)
    {
        prime[i]=0;
    }
    for(ll i=3; i<=1125; i+=2)
    {
        if(prime[i])
        {
            for(ll j=i*i; j<=1125; j+=2*i)
            {
                prime[j]=0;
            }
        }
    }
}
void solve_dp()
{
    for(ll i=0; i<=MAX; i++)
    {
        for(ll j=0; j<15; j++)
        {
            mem[i][j]=0;
        }
    }
    for(ll i=0; i<=MAX; i++)
    {
        mem[i][1]=prime[i];
    }
    for(ll j=2; j<=3; j++)
    {
        for(ll i=1; i<=25; i++)
        {
            cout<<i<<" x:\n";
            for(ll k=1; k<i; k++)
            {
                if(mem[k][j-1]>0&&prime[i-k]==1)
                {
                    if(prime[k]==1&&i-k==k)continue;
                    mem[i][j]+=mem[k][j-1];
                    cout<<k<<" "<<i-k<<" f\n";
                }
            }
             cout<<mem[i][j]<<" x2\n";

        }
    }
}
int main()
{
    seive();
    solve_dp();
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; ; test++)
    {
        ll n,k;
        cin>>n>>k;
        if(n==0&&k==0)
        {
            break;
        }
        cout<<mem[n][k]<<"\n";
    }
    return 0;
}




