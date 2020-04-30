/*
    Sk arman Hossain
    University of Barisal

    Problem : spoj_BYTESM2-Philosophers Stone
    Algorithm : DP
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[110][110];
ll ar[110][110],n,m;
ll grid(ll i=0,ll j=0){
    if(j>=m||j<0){
        return LONG_MIN;
    }
    if(i>=n-1){
        return dp[i][j]=ar[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll ans=max(max(grid(i+1,j),grid(i+1,j+1)),grid(i+1,j-1))+ar[i][j];
    return dp[i][j]=ans;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tcase=1;
    cin>>tcase;
    for(ll TEST=1;TEST<=tcase;TEST++){
        cin>>n>>m;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                dp[i][j]=-1;
                cin>>ar[i][j];
            }
        }
        ll ans=0;
        for(ll i=0;i<m;i++){
            ans=max(ans,grid(0,i));
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

