/*
    Sk arman Hossain
    University of Barisal

    Problem : spoj_AIBOHP-Aibohphobia
    Algorithm : DP
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[6110][6110];
string s;
ll cal(ll i,ll j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll ans;
    if(s[i]==s[j]){
        ans=cal(i+1,j-1);
    }
    else{
        ans=min(cal(i+1,j),cal(i,j-1))+1;
    }
    return dp[i][j]=ans;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tcase=1;
    cin>>tcase;
    for(ll TEST=1; TEST<=tcase; TEST++)
    {
        cin>>s;
        ll len=s.size();
        for(ll i=0;i<=len;i++){
            for(ll j=0;j<=len;j++){
                dp[i][j]=-1;
            }
        }
        ll ans=cal(0,(ll)len-1);
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
