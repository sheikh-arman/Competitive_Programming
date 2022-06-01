/*
    Sk arman Hossain
    University of Barisal

    Problem : spoj_BYTESM2-Philosophers Stone
    Algorithm : DP
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ar[110][110],n,m;
ll dp[110][110];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tcase=1;
    cin>>tcase;
    for(ll TEST=1;TEST<=tcase;TEST++){
        cin>>n>>m;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cin>>ar[i][j];
                dp[i][j]=0;
            }
        }
        for(ll j=0;j<m;j++)dp[n-1][j]=ar[n-1][j];
        for(ll i=n-1;i>0;i--){
            for(ll j=0;j<m;j++){
                if(j-1>=0){
                    dp[i-1][j-1]=max(dp[i-1][j-1],dp[i][j]+ar[i-1][j-1]);
                }
                if(j+1<m){
                    dp[i-1][j+1]=max(dp[i-1][j+1],dp[i][j]+ar[i-1][j+1]);
                }
                dp[i-1][j]=max(dp[i-1][j],dp[i][j]+ar[i-1][j]);
            }
        }
        ll ans=0;
        for(ll i=0;i<m;i++){
            ans=max(ans,dp[0][i]);
        }
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
/*
1 1
2 4 7
*/

