/*
    Sk arman Hossain
    University of Barisal

    Problem : Codeforces 1354B
    Solution : DP
 */
#include<bits/stdc++.h>
#define nl cout<<"\n";
#define N 200001
#define PR pair<ll,ll>
#define sf1(n) cin>>n
#define sf2(n, m) cin>>n>>m
#define sf3(n, m,k ) cin>>n>>m>>k
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define minus1 printf("-1\n")
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<ll>V,V2,V3;
string s;
ll n;
ll chache[200010][3][3][3];
ll dp(ll i,ll c1,ll c2,ll c3)
{
    if(c1==1&&c2==1&&c3==1)
    {
        return i;
    }
    if(i>=n)
    {
        return LONG_MAX;
    }
    if(chache[i][c1][c2][c3]!=-1)
    {
        return chache[i][c1][c2][c3];
    }
    ll ans=LONG_MAX;
    if(c1||c2||c3)
    {
        ll tm;
        if(s[i]=='1')tm=dp(i+1,1,c2,c3);
        if(s[i]=='2')tm=dp(i+1,c1,1,c3);
        if(s[i]=='3')tm=dp(i+1,c1,c2,1);
        ans=tm;
    }
    else
    {
        ll tm;
        if(s[i]=='1')tm=dp(i+1,1,c2,c3);
        if(s[i]=='2')tm=dp(i+1,c1,1,c3);
        if(s[i]=='3')tm=dp(i+1,c1,c2,1);
        ans=tm-i;
        ans=min(ans,dp(i+1,c1,c2,c3));
    }
    return chache[i][c1][c2][c3]=ans;
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
        cin>>s;
        n=s.size();
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<2; j++)
            {
                for(ll k=0; k<2; k++)
                {
                    for(ll x=0; x<2; x++)
                    {
                        chache[i][j][k][x]=-1;
                    }
                }
            }
        }
        ll ans=dp(0,0,0,0);
        if(ans>2000000)
        {
            cout<<"0\n";
        }
        else cout<<ans<<"\n";

    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}


