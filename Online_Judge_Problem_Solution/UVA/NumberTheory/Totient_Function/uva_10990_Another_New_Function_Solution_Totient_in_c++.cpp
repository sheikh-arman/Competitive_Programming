
/*
Author: Sk Arman Hossain
University of Barishal
Problem :  uva 10990 another new function
Algorithm: Totient

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll toten[2000010];
ll toten_sum[2000010];
ll cum_sum[2000010];
ll N=2000000;
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
void dp(){
    for(ll i=2;i<=N;i++){
        toten_sum[i]+=toten_sum[toten[i]]+1;
    }
    for(ll i=2;i<=N;i++){
        cum_sum[i]=cum_sum[i-1]+toten_sum[i];
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    totient();
    dp();
    ll tcase;
    cin>>tcase;
    while(tcase--){
        ll n,m;
        cin>>n>>m;
        if(n>m)swap(n,m);
        cout<<cum_sum[m]-cum_sum[n-1]<<"\n";
    }
    return 0;
}

