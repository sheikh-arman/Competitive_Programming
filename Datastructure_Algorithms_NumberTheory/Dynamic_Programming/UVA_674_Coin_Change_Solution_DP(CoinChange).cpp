/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution : DP(CoinChange)
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ar[7]= {50,25,10,5,1};
ll chache[7500][7],n;
ll dp(ll i,ll val)
{
    if(i>=5)
    {
        if(val==0)
        {
            return 1;
        }
        else return 0;
    }
    if(chache[val][i]!=-1)
    {
        return chache[val][i];
    }
    ll ans=0;
    if(val-ar[i]>=0)
    {
        ans+=dp(i,val-ar[i]);
    }
    ans+=dp(i+1,val);
    return chache[val][i]=ans;
}
int main()
{
    for(ll i=0; i<=7490; i++)
    {
        for(ll j=0; j<5; j++)
        {
            chache[i][j]=-1;
        }
    }
    for(ll i=1; i<=7489; i++)
        ll ans=dp(0,i);
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%lld\n",chache[n][0]);
    }
    //*****Alhamdulillah***********/
    return 0;
}
