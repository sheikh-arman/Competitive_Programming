/*
Author: Sk Arman Hossain
University of Barishal
Problem :
Algorithm: Totient

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
ll N=1000000;
vector<ll>prime;
bitset<1000010>ckprime;
void seive(){
    prime.PB(2);
    for(ll i=3;i<=N;i+=2){
        if(ckprime[i]==false){
                prime.PB(i);
            for(ll j=i*i;j<=N;j+=i+i){
                ckprime[j]=true;
            }
        }
    }
}
ll totient(ll n){
    ll ans=n;
    ll sq=sqrt(n+1);
    for(ll i=0;prime[i]<=sq;i++){
        if(n%prime[i]==0){
            while(n%prime[i]==0)
                n/=prime[i];
            ans-=ans/prime[i];
        }
    }
    if(n>1){
        ans-=ans/n;
    }
    return ans;
}
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    seive();
    ll tcase;
    cin>>tcase;
    while(tcase--){
        ll n;
        cin>>n;
        cout<<totient(n)<<"\n";
    }
    return 0;
}


