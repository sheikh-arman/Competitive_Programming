/*
    Sk arman Hossain
    University of Barisal

    Problem : Longest Common Subsequence
    Solution : Dynamic Programming(Recursive)
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define N 500
string s1,s2;
ll dp[N+10][N+10];
ll lcs(ll l,ll r){
    ll sizl=s1.size();
    ll sizr=s2.size();
    ll ans=0;
    if(l>=sizl||r>=sizr){
        return 0;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    if(s1[l]==s2[r]){
        ans=1+lcs(l+1,r+1);
    }
    else{
        ans=max(lcs(l+1,r),lcs(l,r+1));
    }
    dp[l][r]=ans;
    return dp[l][r];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tcase=1;
    //cin>>tcase;
    for(int TEST=1; TEST<=tcase; TEST++)
    {
        cin>>s1>>s2;
        ll siz1=s1.size();
        ll siz2=s2.size();
        for(ll i=0;i<siz1;i++){
            for(ll j=0;j<siz2;j++){
                dp[i][j]=-1;
            }
        }
        ll ans=lcs(0,0);
        cout<<ans<<"\n";
    }
    ///************************Alhamdulillah*************//
    return 0;
}
/*
ref: shafaetsplanet
hellom hmrll
3
*/


