
/*
    Sk arman Hossain
    University of Barisal

    Problem : Codeforces 1360E. Polygon
    Solution : DFS
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
bitset<55>color[55];
string s[55];
void dfs(ll i,ll j)
{
    if(s[i][j]=='1')
    {
        color[i][j]=1;
    }
    if(j-1>=0&& s[i][j-1]=='1' &&color[i][j-1]==0)
    {
        dfs(i,j-1);
    }
    if(i-1>=0&&s[i-1][j]=='1' && color[i-1][j]==0)
    {
        dfs(i-1,j);
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            cin>>s[i];
            for(ll j=0; j<n; j++)
            {
                color[i][j]=0;
            }
        }
        for(ll i=0; i<n; i++)
        {
            if(s[n-1][i]=='1')
                dfs(n-1,i);
        }
        for(ll i=0; i<n; i++)
        {
            if(s[i][n-1]=='1')
                dfs(i,n-1);
        }
        ll ck=0;
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<n; j++)
            {
                if(s[i][j]=='1'&&color[i][j]==0)
                {
                    ck=1;
                    break;
                }
            }
        }
        if(ck)
        {
            NO;
        }
        else
        {
            YES;
        }

    }
///*****************************  ALHAMDULILLAH  *****************************/
}

