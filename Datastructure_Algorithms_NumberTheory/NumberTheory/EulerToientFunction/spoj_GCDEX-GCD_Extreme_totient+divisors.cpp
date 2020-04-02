/*
Author: Sk Arman Hossain
University of Barisal

Problem : GCDEX - GCD Extreme
Algorithm: Euler Totient Function + Divisors
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1000011
ll toten[N+10];
ll ans[N+10];
void totient()
{
    toten[1]=1;
    for(ll i=2; i<=N; i++)
    {
        toten[i]=i;
    }
    for(ll i=2; i<=N; i+=2)
    {
        toten[i]-=toten[i]/2;
    }
    for(ll i=3; i<=N; i+=2)
    {
        if(toten[i]==i)
        {
            for(ll j=i; j<=N; j+=i)
            {
                toten[j]-=toten[j]/i;
            }
        }
    }
}
void pre_process()
{
    for(ll i=1; i<=N; i++)
    {
        for(ll j=i+i; j<=N; j+=i)
        {
            ans[j]+=i*(toten[j/i]);
        }
    }
    for(ll i=2; i<=N; i++)
    {
        ans[i]+=ans[i-1];
    }
}
int main()
{

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    totient();
    pre_process();
    ll n;
    while(cin>>n&&n)
    {
        cout<<ans[n]<<"\n";
    }
    ///*************Alhamdulillah*************///
    return 0;
}
