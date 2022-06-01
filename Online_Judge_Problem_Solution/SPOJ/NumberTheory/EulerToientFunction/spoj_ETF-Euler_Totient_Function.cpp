/*
Author: Sk Arman Hossain
University of Barishal
Problem :  spoj - ETF - Euler Totient Function
Algorithm: Totient

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll toten[1000010];
ll N=1000000;
void totient(){
    toten[1]=1;
    for(ll i=2;i<=N;i++){
        toten[i]=i;
    }
    for(ll i=2;i<=N;i+=2){
        toten[i]-=toten[i]/2;
    }
    for(ll i=3;i<=N;i+=2){
        if(toten[i]==i){
            for(ll j=i;j<=N;j+=i){
                toten[j]-=toten[j]/i;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    totient();
    ll tcase;
    cin>>tcase;
    while(tcase--){
        ll n;
        cin>>n;
        cout<<toten[n]<<"\n";
    }
    return 0;
}
