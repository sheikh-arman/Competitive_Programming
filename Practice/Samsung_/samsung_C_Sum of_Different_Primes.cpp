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
ll mem[195][1132][16];
bitset<1130>prime;
vector<ll>prime_list;
ll n,k;
void seive()
{
    prime.set();
    prime[0]=0;
    prime[1]=0;
    for(ll i=4; i<1125; i+=2)
    {
        prime[i]=0;
    }
    prime_list.PB(2);
    for(ll i=3; i<=1125; i+=2)
    {
        if(prime[i])
        {
            prime_list.PB(i);
            for(ll j=i*i; j<=1125; j+=2*i)
            {
                prime[j]=0;
            }
        }
    }
}
ll dp(ll pos,ll current,ll siz)
{
    if(pos>=(ll)prime_list.size())
    {
        return 0;
    }
    if(prime_list[pos]>n)
    {
        if(current==0&&siz==k)
        {
            return 1;
        }
        return 0;
    }
    if(current<=0)
    {
        if(current==0&&siz==k)
        {
            return 1;
        }
        return 0;
    }
    if(mem[pos][current][siz]!=-1)
    {
        return mem[pos][current][siz];
    }
    ll ans=0;
    ans+=dp(pos+1,current,siz);
    if(siz<k)
    ans+=dp(pos+1,current-prime_list[pos],siz+1);
    return mem[pos][current][siz]=ans;
}
int main()
{
    seive();
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; ; test++)
    {
        cin>>n>>k;
        if(n==0&&k==0)
        {
            break;
        }
        for(ll i=0; i<=190; i++)
        {
            for(ll j=0; j<=n; j++)
            {
                for(ll z=0;z<=k;z++){
                    mem[i][j][z]=-1;
                }
            }
        }
        ll ans=dp(0,n,0);
        cout<<ans<<"\n";
    }
    return 0;
}




