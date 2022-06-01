/*
    Sk arman Hossain
    University of Barisal

    Problem name : spoj_LOCKER-Magic_of_the_locker
    Algorithm : Big Mod
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1e9+7;
ll big_mod(ll n,ll p)
{
    if(p==0)
    {
        return 1;
    }
    if(p==1)
    {
        return n;
    }
    if(p%2==0)
    {
        ll tm=big_mod(n,p/2);
        return ((tm%mod)*(tm%mod))%mod;
    }
    else
    {
        return ((big_mod(n,p-1)%mod)*(n%mod))%mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tcase=1;
    cin>>tcase;
    for(ll TEST=1; TEST<=tcase; TEST++)
    {
        ll n;
        cin>>n;
        ll tm=n/3;
        ll cn=n%3;
        ll ans=1;
        if(n%3==1)
        {
            if(tm)
            {
                tm-=1;
                ans=4;
                ans=((ans%mod)*(big_mod(3,tm))%mod)%mod;
            }
        }
        else if(n%3==2)
        {
            ans=2;
            ans=((ans%mod)*(big_mod(3,tm))%mod)%mod;
        }
        else
        {
            ans=big_mod(3,tm);
        }
        cout<<ans<<"\n";

    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
