/*
    Sk arman Hossain
    University of Barisal

    Problem : lightoj 1047 neibour house
    Solution : dp
 */
#include<bits/stdc++.h>
#define nl cout<<"\n";
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
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define minus1 printf("-1\n");
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTr(v) sort(v.begin(),v.end(),greater<long long int>())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 200001
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
ll SET(ll NUM,ll POS) {
    return NUM | (1<<POS);
}
bool isOn(ll NUM,ll POS) {
    return (bool)(NUM & (1<<POS));
}
ll mem[22][5];
ll ar[22][4],n;
ll dp(ll pos,ll color){
    if(pos>=n){
        return 0;
    }
    if(mem[pos][color]!=-1){
        return mem[pos][color];
    }
    ll ans=LONG_MAX;
    if(color!=0){
        ans=min(ans,dp(pos+1,0)+ar[pos][0]);
    }
    if(color!=1){
        ans=min(ans,dp(pos+1,1)+ar[pos][1]);
    }
    if(color!=2){
        ans=min(ans,dp(pos+1,2)+ar[pos][2]);
    }
    return mem[pos][color]=ans;
}
int main()
{
    fast;
   // freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>n;
        for(ll i=0;i<n;i++){
            ll r,g,b;
            cin>>r>>g>>b;
            ar[i][0]=r;
            ar[i][1]=g;
            ar[i][2]=b;
        }
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<4;j++){
                mem[i][j]=-1;
            }
        }
        ll ans=dp(0,3);
        cout<<"Case "<<test<<": "<<ans<<"\n";

    }
///*****************************  ALHAMDULILLAH  *****************************/
}




