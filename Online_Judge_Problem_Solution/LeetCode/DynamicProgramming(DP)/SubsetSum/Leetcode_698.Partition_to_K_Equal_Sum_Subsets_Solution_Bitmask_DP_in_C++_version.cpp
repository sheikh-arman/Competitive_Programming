/*
    Sk arman Hossain
    University of Barisal

    Problem name : subset sum k partition
    Solution : dp
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 17
ll dp[N+2][(1<<N)+10];
ll n,kk,sum=0,found;
vector<ll>V;
ll Set(ll m,ll pos)
{
    return m|1<<pos;
}
bool view(ll m,ll pos)
{
    return m&(1<<pos);
}
bool sub_sum(ll i,ll val,ll bitmask)
{
    if(i>=n)
    {
        if(bitmask==pow(2,n)-1)
        {
            return dp[i][bitmask]=1;
        }
        else if(val==sum/kk)
        {
            dp[i][bitmask]=sub_sum(0,0,bitmask);
            return dp[i][bitmask];
        }
        else
            return dp[i][bitmask]=0;
    }
    if(dp[i][bitmask]!=-1)
    {
        return dp[i][bitmask];
    }
    ll ans1=0,ans2=0;
    ans1=sub_sum(i+1,val,bitmask);
    if(V[i]+val<=sum/kk)
    {
        if(view(bitmask,i)==0)
        {
            ans2=sub_sum(i+1,val+V[i],Set(bitmask,i));
        }
    }
    dp[i][bitmask]=ans1|ans2;
    return dp[i][bitmask];
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
        sum=found=0;
        cin>>n>>kk;
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=(1<<N); j++)
            {
                dp[i][j]=-1;
            }
        }
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.push_back(a);
            sum+=a;
        }
        if(sum%kk!=0)
        {
            cout<<"False\n";
            continue;
        }
        ll ans=sub_sum(0,0,0);
        //cout<<cnt<<" "<<sum/k<<"\n";
        if(ans==1)
        {
            cout<<"True\n";
        }
        else
        {
            cout<<"False\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
/*
9 3
10 10 10 7 7 7 6 6 6

5 3
1 2 2 2 2


*/

