/*
    Sk arman Hossain
    University of Barisal

    Problem : Codeforces 1203F2
    Solution : DP(knapsack)
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<pair<ll,ll> >V,V2;
ll chache[110][30010],n;
ll dp(ll i,ll r)
{
    if(i>=n||r<=0)
    {
        return 0;
    }
    if(chache[i][r]!=-1)
    {
        return chache[i][r];
    }
    ll ans=0;
    if(r>=V[i].first&&r+V[i].second>=0)
    {
        ans=1+dp(i+1,r+V[i].second);
    }
    ans=max(ans,dp(i+1,r));
    return chache[i][r]=ans;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll r;
    cin>>n>>r;
    for(ll i=0; i<n; i++)
    {
        ll a,b;
        cin>>a>>b;
        if(b<0)
        {
            V.push_back({a,b});
        }
        else
            V2.push_back({a,b});
    }
    sort(V2.begin(),V2.end());
    sort(V.begin(),V.end(),[&](pair<ll,ll>a,pair<ll,ll>b)
    {
        return (a.first+a.second)>(b.first+b.second);
    });
    ll siz=V2.size(),ans=0;
    for(ll i=0; i<siz; i++)
    {
        if(V2[i].first<=r)
        {
            r+=V2[i].second;
            ans++;
        }
    }
    for(ll i=0; i<=n; i++)
    {
        for(ll j=0; j<=30000; j++)
        {
            chache[i][j]=-1;
        }
    }
    n=V.size();
    ans+=dp(0,r);
    cout<<ans<<"\n";

    return 0;
}
