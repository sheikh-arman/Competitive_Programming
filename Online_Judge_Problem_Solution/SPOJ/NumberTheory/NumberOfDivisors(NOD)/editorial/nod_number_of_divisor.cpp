
/*
Author: Sk Arman Hossain
University of Barishal
Problem :
Algorithm: number of divisor(nod)

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
ll N=2000000;
vector<ll>prime;
bitset<2000010>ckprime;
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
ll nod(ll n)
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
            ans*=(cnt+1);
        }
    }
    if(n>1)
    {
        ans*=2;
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
        cout<<nod(n)<<"\n";
    }
    return 0;
}

