/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
    Date:
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define sf(n) scanf("%lld",&n);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define nl cout<<"\n";
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
#define MAX 2000010
#define T(n) printf("test : %d\n",n);
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
ll mem[33][33];
ll mem2[33][33];
ll n,m;
string s,p;
ll dp(ll i,ll j)
{
    if(i>=n||j>=m)
    {
        return mem[i][j]=0;
    }
    if(mem[i][j]!=-1)
    {
        return mem[i][j];
    }
    ll ans=0;
    if(s[i]==p[j])
    {
        ans=dp(i+1,j+1)+1;
    }
    else
    {
        ans=dp(i+1,j);
        ans=max(ans,dp(i,j+1));
    }
    return mem[i][j]=ans;
}
ll dp2(ll i,ll j)
{
    if(i>=n||j>=m)
    {
        return mem2[i][j]=1;
    }
    if(mem2[i][j]!=-1)
    {
        return mem2[i][j];
    }
    ll ans=0;
    if(s[i]==p[j])
    {
        ans=dp2(i+1,j+1);
    }
    else
    {
        if(mem[i+1][j]==mem[i][j+1])
        {
            ans=dp2(i+1,j);
            ans+=dp2(i,j+1);
        }
        else if(mem[i+1][j]>mem[i][j+1])
        {
            ans=dp2(i+1,j);
        }
        else
        {
            ans=dp2(i,j+1);
        }
    }
    return mem2[i][j]=ans;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>s>>p;
        n=s.size();
        m=p.size();
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=m; j++)
            {
                mem[i][j]=-1;
            }
        }
        ll ans=dp(0,0);
        ll mi=(n+m)-ans;
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=m; j++)
            {
                mem2[i][j]=-1;
            }
        }
        ll way=0;
        way=dp2(0,0);
        cout<<"Case "<<test<<": "<<mi<<" "<<way<<"\n";


    }
    return 0;
}




