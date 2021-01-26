/**      BU_Excalibur      **/
/** University of Barishal **/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binpow(ll base, ll power, ll mod)
{
    base%=mod;
    // If mod is prime, power=power%(mod-1);
    ll result=1;
    while(power>0)
    {
        if(power&1)result=(result*base)%mod;
        base=(base*base)%mod;
        power>>=1;
    }
    return result;
}

ll bigMul(ll a, ll b, ll mod)
{
    if(a==0)return 0;
    ll ans=(2*bigMul(a/2,b,mod))%mod;
    if(a&1)
    {
        ans=(ans+(b%mod))%mod;
    }
    return ans;
}

int main()
{
    /***************************************/
    // Site Name        : UVA
    // Problem No/ID    : p11029 Leading and Trailing
    /***************************************/
    ll x,y,n,test;

    scanf("%lld",&test);

        while(test--)
        {
            scanf("%lld%lld",&x,&y);
            ll ans=binpow(x,y,1000);
            double tm=y*log10(x);
            //cout<<tm<<"\n";
            tm-=(ll)tm;
            tm=pow(10,2.0+tm);
            printf("%lld...%.3lld\n",(ll)tm,ans);
        }

    return 0;
}

