/*
    Sk arman Hossain
    University of Barisal

    Problem : spoj MIXTURES - Mixtures
    Algorithm :  DP Matrix Chain Multiplication
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>V;
ll dp[105][105],n;
ll cum[105];
ll Merge(ll i,ll k,ll j){
    i++;k++;j++;///as cum is 1 indexed
    return ((cum[k]-cum[i-1])%100)*((cum[j]-cum[k])%100);
}
ll matrix(ll i,ll j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll ans=LONG_MAX;
    for(ll k=i;k<j;k++){
        ll x=matrix(i,k);
        ll y=matrix(k+1,j);
        ans=min(ans,x+y+Merge(i,k,j));
    }
    return dp[i][j]=ans;
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tcase=1;
    //cin>>tcase;
    while(scanf("%lld",&n)!=EOF)
    {
        V.clear();
        //cin>>n;
        cum[0]=0;
        for(ll i=1;i<=n;i++){
            ll r;
            //cin>>r;
            scanf("%lld",&r);
            cum[i]=r+cum[i-1];
            V.push_back(r);
        }
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
        ll ans=matrix(0,n-1);
       printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
/*
3
40 60 20


*/
