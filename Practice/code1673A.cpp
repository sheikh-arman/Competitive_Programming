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
ll mod=1e9+7;
ll ck_palin(ll n)
{
    ll num=n,sum=0;
    while(num)
    {
        sum=(sum*10)+num%10;
        num/=10;
    }
    return (sum==n);
}
vector<ll>V;
ll siz;
ll mem[40010][600];
ll dp(ll val,ll pos){
    if(val==0){
        return 1;
    }
    if(pos>=siz){
        return 0;
    }
    if(mem[val][pos]!=-1){
        return mem[val][pos];
    }
    ll sol1=0;
    ll sol2=0;
    if(val>=V[pos]){
        sol1=dp(val-V[pos],pos+1);
    }
    sol2=dp(val,pos+1);
    sol1%=mod;
    sol2%=mod;
    return mem[val][pos]=(sol1+sol2)%mod;
}
int main()
{
    for(ll i=1; i<=40000; i++)
    {
        if(ck_palin(i))V.PB(i);
    }
    siz=V.size();
    for(ll i=0;i<=40000;i++){
        for(ll j=0;j<=siz+10;j++){
            mem[i][j]=-1;
        }
    }
    ll ck=dp(40000,0);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        cout<<dp(n,0)<<"\n";



    }
    return 0;
}




