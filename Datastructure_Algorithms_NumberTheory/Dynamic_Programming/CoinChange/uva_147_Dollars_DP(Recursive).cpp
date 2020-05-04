/*
    Sk arman Hossain
    University of Barisal

    Problem : uva_147_Dollars
    Solution : DP(recursive)
 */
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
ll dp[30010][13];
double ar[]= {10000,5000,2000,1000,500,200,100,50,20,10,5};
ll coin(ll i,ll val)
{
    if(val<=0)
    {
        if(val==0)
            return 1;
        else return 0;
    }

    if(dp[val][i]!=-1)
    {
        return dp[val][i];
    }
    ll ans=0;
    for(ll k=i; k<11; k++)
    {
        ans+=coin(k,val-ar[k]);
    }
    return dp[val][i]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//   freopen("1input.txt","r",stdin);
//   freopen("1output.txt","w",stdout);
    for(ll i=0; i<=30000; i++)
    {
        for(ll j=0; j<=11; j++)
            dp[i][j]=-1;
    }
    for(ll i=30000; i>=5; i-=5)
    {
        if(dp[i][0]==-1)
        {
            dp[i][0]=coin(0,i);
        }
    }

    double n;
    while(cin>>n&&n>.00001)
    {
        ll tm=(n*100)+.5;// add .5 for avoid precission error
        cout<<fixed<<setprecision(2)<<setw(6)<<n<<setw(17)<<dp[tm][0]<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

