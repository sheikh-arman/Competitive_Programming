
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
ll N=100000;
vector<ll>divisor[100010];
void nod()
{
    for(ll i=1; i<=N; i+=1)
    {
        for(ll j=i; j<=N; j+=i)
        {
            divisor[j].PB(i);
        }
    }
}
int main()
{
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    nod();
    ll n;
    while(cin>>n&&n)
    {
        ll l1=divisor[n].size();
        for(ll i=0;i<l1;i++){
            cout<<divisor[n][i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

