/*
    Sk arman Hossain
    University of Barisal

    Problem : lightoj 1017
    Solution : DP(Knapsack) + binary search
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
ll chache[110][110];
 vector<ll>V;
ll n,ans=1,w,k;
ll dp(ll i,ll step){
    if(i>=n){
        return 0;
    }
    if(chache[i][step]!=-1){
        return chache[i][step];
    }
    ll ans=0;
    if(step>0){
        ll pos=upper_bound(V.begin(),V.end(),V[i]+w)-V.begin();
        ans+=(pos-i)+dp(pos,step-1);
    }
    ans=max(ans,dp(i+1,step));
    return chache[i][step]=ans;
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
        V.clear();
        cin>>n>>w>>k;
        for(ll i=0;i<n;i++){
            ll a,b;
            cin>>a>>b;
           V.PB(b);
        }
        VST(V);
        ll prev=V[0]+w;
        for(ll i=0;i<n;i++){
            if(V[i]>prev){
                ans++;
                prev=V[i]+w;
            }
        }
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=k;j++){
                chache[i][j]=-1;
            }
        }
        ans=dp(0,k);
        cout<<"Case "<<test<<": "<<ans<<endl;


    }
///*****************************  ALHAMDULILLAH  *****************************/
}




