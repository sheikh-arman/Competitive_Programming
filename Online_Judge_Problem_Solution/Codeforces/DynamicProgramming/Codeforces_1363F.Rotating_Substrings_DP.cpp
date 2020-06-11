/*
    Sk arman Hossain
    University of Barisal

    Problem :Codeforces_1363F.Rotating_Substrings
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
string s,t;
vector<ll>V,V2,V3;
ll n;
ll cnts[2010][30],cntt[2010][30];
ll dp[2010][2010];
ll rec(ll i,ll j){
    if(i<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll ans=LONG_MAX;
    if(s[i]==t[j]){
        ans=rec(i-1,j-1);
    }
    else if(cnts[i][t[j]-'a']>=cntt[j][t[j]-'a']){
        ans=rec(i,j-1);
    }
    ans=min(ans,rec(i-1,j)+1);
    dp[i][j]=ans;
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>n;
        cin>>s>>t;
        if(s==t)
        {
            cout<<"0\n";
            continue;
        }
        for(ll i=n-1; i>=0; i--)
        {
            if(s[i]==t[i])
            {
                n--;
                s.pop_back();
                t.pop_back();
            }
            else break;
        }
        string s1,s2;
        ll ck=0;
        for(ll i=0; i<n; i++)
        {
            if(s[i]!=t[i])
            {
                ck=1;
            }
            if(ck)
            {
                s1+=s[i];
                s2+=t[i];
            }
        }
        s=s1;
        t=s2;
        n=s.size();
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=n; j++)
            {
                dp[i][j]=-1;
            }
        }
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<26;j++){
                cnts[i][j]=0;
                cntt[i][j]=0;
            }
        }
        for(ll i=n-1;i>=0;i--){
            cnts[i][s[i]-'a']=1;
            for(ll j=0;j<=25;j++){
                cnts[i][j]+=cnts[i+1][j];
            }
        }
        for(ll i=n-1;i>=0;i--){
            cntt[i][t[i]-'a']=1;
            for(ll j=0;j<=25;j++){
                cntt[i][j]+=cntt[i+1][j];
            }
        }
        ck=0;
        for(ll i=0;i<26;i++){
            if(cnts[0][i]!=cntt[0][i]){
                ck=1;break;
            }
        }
        //cout<<s<<" "<<t<<"\n";
        if(ck){
            cout<<"-1\n";
        }
        else{
           ll ans=rec(n-1,n-1);
        cout<<ans<<"\n";
        }




    }
///*****************************  ALHAMDULILLAH  *****************************/
}


