/*
    Sk arman Hossain
    University of Barisal

    Problem : spoj_BVAAN-Balika_Vadhu_and_Alok_Nath
    Solution : LCS+Knapsack
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<char>V;
string s1,s2;
ll dp[110][110][110],len1,len2,k;
ll lcs(ll i,ll j,ll w)
{
    if(i>=len1||j>=len2)
    {
        if(w<k)
        {
            return -99999999;
        }
        return 0;
    }
    if(dp[i][j][w]!=-1)
    {
        return dp[i][j][w];
    }
    ll ans=-999999999,ans2;
    if(s1[i]==s2[j])
    {
        if(w+1<=k)
        {
            ans=lcs(i+1,j+1,w+1)+s1[i];

        }
        ans2=lcs(i+1,j+1,w);
        return dp[i][j][w]=max(ans,ans2);
    }
    else
    {
        ans=max(lcs(i+1,j,w),lcs(i,j+1,w));
        return dp[i][j][w]=ans;
    }

}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        V.clear();
        cin>>s1>>s2;
        cin>>k;
        len1=s1.size();
        len2=s2.size();
        for(ll i=0; i<=len1; i++)
        {
            for(ll j=0; j<=len2; j++)
            {
                for(ll x=0; x<=k; x++)
                {
                    dp[i][j][x]=-1;
                }
            }
        }
        ll ans=lcs(0,0,0);
        ans=max(0ll,ans);
        cout<<ans<<"\n";



    }
///*****************************  ALHAMDULILLAH  *****************************/
}
