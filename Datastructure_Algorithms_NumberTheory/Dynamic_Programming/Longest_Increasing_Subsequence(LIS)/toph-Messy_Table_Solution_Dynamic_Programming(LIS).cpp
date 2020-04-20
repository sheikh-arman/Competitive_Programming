/*
    Sk arman Hossain
    University of Barisal

    Problem : toph-> Messy Table
    Solution : Dynamic Programming
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define N 5000
int dp[N+10];
int lis(int pos,vector<pair<int,int>>& pairs)
{
    if(dp[pos]!=-1)
    {
        return dp[pos];
    }
    int siz=pairs.size();
    int ans=0;
    for(int j=pos+1; j<siz; j++)
    {
        if(pairs[j].first>pairs[pos].first&&pairs[j].second>pairs[pos].second)
        {
            ans=max(ans,lis(j,pairs));
        }
    }
    dp[pos]=ans+1;
    return dp[pos];
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tcase=1;
    //cin>>tcase;
    for(int TEST=1; TEST<=tcase; TEST++)
    {
        vector<pair<int,int>>V;
        int array_size;
        cin>>array_size;
        for(ll i=0; i<array_size; i++)
        {
            ll a,b;
            cin>>a>>b;
            if(a>b)swap(a,b);
            V.push_back({a,b});
            dp[i]=-1;
        }
        sort(V.begin(),V.end());
        int ans=0;
        for(ll i=0; i<array_size; i++)
        {
            ans=max(ans,lis(i,V));
        }
        cout<<ans<<"\n";
    }
    ///************************Alhamdulillah*************//
    return 0;
}
