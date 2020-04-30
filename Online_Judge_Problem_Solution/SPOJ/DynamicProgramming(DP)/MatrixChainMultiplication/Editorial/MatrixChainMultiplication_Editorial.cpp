/*
    Sk arman Hossain
    University of Barisal

    Problem : Minimum multiplication operation of N Matrix
    Algorithm : DP_Divide_And_Conqure(Matrix Chain Multiplication)
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<pair<ll,ll>>V;
ll dp[1000][1000],n;
ll cal(ll i,ll k,ll j){
    return V[i].first*V[k].second*V[j].second;
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
        ans=min(ans,x+y+cal(i,k,j));
    }
    return dp[i][j]=ans;
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tcase=1;
    //cin>>tcase;
    for(ll TEST=1; TEST<=tcase; TEST++)
    {
        V.clear();
        cin>>n;
        for(ll i=0;i<n;i++){
            ll r,c;
            cin>>r>>c;
            V.push_back({r,c});
        }
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
        ll ans=matrix(0,n-1);
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
