/*
    Sk arman Hossain
    University of Barisal

    Problem name : Codeforces F. Kate and imperfection
    Solution : modified seive(prime_factorization)
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
ll ans[500010];
ll prime_factor[500010];
void modified_seive(ll n){
    for(ll i=1;i<=n;i++){
        for(ll j=i+i;j<=n;j+=i){
            prime_factor[j]++;
        }
    }
    set<ll>s;
    s.insert(1);
    for(ll i=1;i<=n;i++){
        for(ll j=i+i;j<=n;j+=i){
            prime_factor[j]--;
            if(prime_factor[j]==0){
                s.insert(j);
            }
        }
        ll siz=s.size();
        if(ans[siz]==0){
            ans[siz]=i;
        }
    }
    for(ll i=n-1;i>1;i--){
        if(ans[i]==0){
            ans[i]=ans[i+1];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        modified_seive(n);
        for(ll i=2;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
//logic->me
//implement->anachor
