/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
#define PB push_back
typedef long long int ll;
using namespace std;
bitset<10000110>ck;
vector<ll>prime;
void seive(){
    prime.PB(2);
    for(ll i=3;i<=1000010;i+=2){
        if(!ck[i]){
            prime.PB(i);
            for(ll j=i*i;j<=1000010;j+=(i+i)){
                ck[i]=1;
            }
        }
    }
}
ll fac(ll n){
    ll siz=prime.size();
    ll ans=n;
    for(ll i=0;i<siz;i+=1){
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
            }
            ans-=ans/prime[i];
        }
        if((ll)(prime[i]*prime[i])>n)break;
    }
    if(n>1){
        ans-=ans/n;
    }
    return ans;
}
int main()
{
    seive();
    ll m,n;
    scanf("%lld%lld",&m,&n);
    ll ans=1;
    ans=fac(n);
    if(n==1)ans=0;
    if(m%n!=0)ans=0;  
    printf("%lld\n",ans);
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}



