/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
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
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define minus1 printf("-1\n");
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
bitset<100010>ck;
vector<ll>prime;
void seive(){
    prime.PB(2);
    for(ll i=3;i<=100000;i+=2){
        if(!ck[i]){
            prime.PB(i);
            for(ll j=i*i;j<=100000;j+=(i+i)){
                ck[i]=1;
            }
        }
    }
}
void fac(ll n,ll& ans){
    ll sq=sqrt(n+1);
    ll siz=prime.size();
    ans=0;
    for(ll i=0;i<siz&&prime[i]<=sq;i+=1){
        if(n%prime[i]==0){
            ll cnt=0;
            while(n%prime[i]==0){
                n/=prime[i];
                cnt++;
            }
            ans=__gcd(ans,cnt);
        }
    }
    if(n>1){
        ans=1;
    }
}
int main()
{
    seive();
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll tcase=100;
    //sf1(tcase);
    scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        scanf("%lld",&n);
        ll ck=0;
        if(n<0)ck=1;
        ll ans=1;
        n=abs(n);
        fac(n,ans);
        if(ck&&ans%2==0){
            while(ans%2==0)ans/=2;
        }
        printf("Case %lld: %lld\n",test,ans);
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}



