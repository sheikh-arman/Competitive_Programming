
/*
Author: Sk Arman Hossain
University of Barishal
Problem :  uva 11327 - Enumerating Rational Numbers
Algorithm: Totient

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
ll toten[200010];
ll N=200000;
void totient()
{
    toten[1]=2;
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
vector<ll>V;
void dp()
{
    V.PB(0);
    V.PB(2);
    ll tm=2;
    for(ll i=2; i<=N; i++)
    {
        tm+=toten[i];
        V.PB(tm);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    totient();
    dp();
    ll n;
    while(cin>>n&&n)
    {
        ll pos=lower_bound(V.begin(),V.end(),n)-V.begin();
        ll ase=V[pos-1],need;
        if(toten[pos]==pos-1)
        {
            need=n-ase;
        }
        else
        {
            for(ll i=0; i<=pos; i++)
            {
                if(__gcd(i,pos)==1)
                {
                    ase++;
                }
                if(ase>=n)
                {
                    need=i;
                    break;
                }
            }
        }
        cout<<need<<"/"<<pos<<"\n";
    }
    return 0;
}

