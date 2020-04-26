/*
    Sk arman Hossain
    University of Barisal

    Problem name :
    Algorithm : dp
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 2002
ll dp[N+10][N+10];
ll siz[N+10];
ll weight[N+10];
ll s,n;
ll knap(ll i,ll w){
    if(i>=n){
        return 0;
    }
    if(dp[i][w]!=-1){
        return dp[i][w];
    }
    ll ans1=0,ans2=0;
    ans1=knap(i+1,w);
    if(w>=siz[i]){
        ans2=knap(i+1,w-siz[i])+weight[i];
    }
    return dp[i][w]=max(ans1,ans2);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tcase=1;
    //cin>>tcase;
    for(ll TEST=1; TEST<=tcase; TEST++)
    {

        cin>>s>>n;
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=s;j++){
                dp[i][j]=-1;
            }
        }
        for(ll i=0;i<n;i++){
            cin>>siz[i]>>weight[i];
        }
        ll ans=knap(0,s);
        cout<<ans<<endl;
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}


