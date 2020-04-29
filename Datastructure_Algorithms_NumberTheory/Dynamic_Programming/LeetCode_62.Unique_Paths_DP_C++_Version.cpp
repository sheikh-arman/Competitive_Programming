/*
    Sk arman Hossain
    University of Barisal

    Problem: 62. Unique Paths
    Solution : dp
 */
 #include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int dp[300][300],n,m;
int grid(int i,int j){
    if(i>=n||j>=m){
        return 0;
    }
    if(i==n-1&&j==m-1){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j]=grid(i+1,j)+grid(i,j+1);
}
int main()
{
    //cout<<(4|3);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>n>>m;
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=m;j++){
                dp[i][j]=-1;
            }
        }
        int ans=grid(0,0);
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
