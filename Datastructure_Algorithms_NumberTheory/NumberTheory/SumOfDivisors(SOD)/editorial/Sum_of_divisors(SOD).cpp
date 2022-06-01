
/*
Author: Sk Arman Hossain
University of Barishal
Problem :
Algorithm: Sum of divisor(sod)

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
ll N=100000;
vector<ll>prime;
bitset<100010>ckprime;
void seive()
{
    prime.PB(2);
    for(ll i=3; i<=N; i+=2)
    {
        if(ckprime[i]==false)
        {
            prime.PB(i);
            for(ll j=i*i; j<=N; j+=i+i)
            {
                ckprime[j]=true;
            }
        }
    }
}
ll sod(ll n)
{
    ll ans=1;
    ll sq=sqrt(n+1);
    for(ll i=0; prime[i]<=sq; i++)
    {
        ll cnt=0;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0){
                cnt++;
                n/=prime[i];
            }
            ans*=(powl(prime[i],cnt+1)-1)/(prime[i]-1);
        }
    }
    if(n>1)
    {
        ans*=(powl(n,2)-1)/(n-1);
    }
    return ans;

}
int main()
{
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    seive();
    ll tcase;
    cin>>tcase;
    while(tcase--)
    {
        ll n,m;
        cin>>n;
        cout<<sod(n)<<"\n";
    }
    return 0;
}


