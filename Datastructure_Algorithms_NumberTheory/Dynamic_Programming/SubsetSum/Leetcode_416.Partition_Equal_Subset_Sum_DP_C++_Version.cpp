/*
    Sk arman Hossain
    University of Barisal

    Problem: 416. Partition Equal Subset Sum
    Solution : dp
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[20010],sum,n;
vector<ll>V;
bool sub_sum(ll i,ll val)
{
    if(i>=n)
    {
        //cout<<val<<" t\n";
        if(val==sum/2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(dp[val]!=-1)
    {
        return dp[val];
    }
    bool ans=0;
    if(val+V[i]<=sum/2)
    {
        ans=sub_sum(i+1,val+V[i]);
    }
    ans|=sub_sum(i+1,val);
    return dp[val]=ans;
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
        sum=0;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.push_back(a);
            sum+=a;
        }
        for(ll j=0; j<=sum/2; j++)
        {
            dp[j]=-1;
        }
        if(sum%2!=0)
        {
            cout<<"false\n";
            continue;
        }
        bool ans=sub_sum(0,0);
        //cout<<cnt<<" "<<sum/k<<"\n";
        if(ans==1)
        {
            cout<<"true\n";
        }
        else
        {
            cout<<"false\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
/*
5
3 3 3 4 5


*/
