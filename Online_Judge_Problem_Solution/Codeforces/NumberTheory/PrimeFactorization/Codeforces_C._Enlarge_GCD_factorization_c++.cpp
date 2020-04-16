/*
Author:SK Arman HOSSAIN

Problem:Codeforces_C._Enlarge_GCD
Solution: Prime Factorization
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 4000
ll fact[16000010];
ll ck_ar[16000010];
bitset<N+10>pri;
vector<ll>prime,V;
void seive(){
    prime.push_back(2);
    for(ll i=3;i<N;i+=2){
        if(pri[i]==0){
                prime.push_back(i);
            for(ll j=i*i;j<N;j+=2*i){
                pri[j]=1;
            }
        }
    }
}
ll ma=0,cn=0;
//unordered_map<ll,ll>mp;
void factorization(ll n,ll val,ll num){
    if(n==1){
       cn+=val;return;
    }
    ll sq=sqrt(n+1);ll xx=0;
    for(ll i:prime){xx++;
        if(n%i==0){
            fact[i]+=val;
            ma=max(ma,fact[i]);
            while(n%i==0)
                n/=i;
        }
        if(i>n||i>sq||num * i >= 1.5e7)break;
    }
    if(n>1){
        fact[n]+=val;
        ma=max(fact[n],ma);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    seive();
    //<<prime[536]<<endl;;
    //cout<<sqrt(14922769);
    ll n,gcd,a;
    cin>>n;
    cin>>gcd;
    V.push_back(gcd);
    for(ll i=1;i<n;i++){
        cin>>a;
        gcd=__gcd(gcd,a);
        V.push_back(a);
    }
    for(ll i=0;i<n;i++){
        V[i]=V[i]/gcd;
        ck_ar[V[i]]++;
    }
    for(ll i:V){
            ll val=ck_ar[i];
            if(val){
                factorization(i,val,n);ck_ar[i]=0;
            }
    }
    n-=cn;
    if(n){
        cout<<n-ma+cn<<"\n";
    }
    else{
        cout<<"-1\n";
    }
}
