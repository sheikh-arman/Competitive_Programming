#include<bits/stdc++.h>
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long int ll;
ll mem[33][33];
ll dp(ll n,ll k){
    if(k>n){
        return 0;
    }
    if(k==0||k==n){
        return 1;
    }
    if(mem[n][k]>0){
        return mem[n][k];
    }
    mem[n][k]=dp(n-1,k)+dp(n-1,k-1);
    return mem[n][k];
}
int main(){
    fast;
    //freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);

    ll tcase=1;
    cin>>tcase;
    for(ll test=1;test<=tcase;test++){
        ll n,k;
        cin>>n>>k;
        ll ans=0;
        ans=dp(n,k);
        for(ll i=(n-k)+1;i<=n;i++)
              ans*=i;
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
    return 0;
}
