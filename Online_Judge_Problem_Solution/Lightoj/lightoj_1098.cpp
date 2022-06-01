/*
    Sk arman Hossain
    University of Barisal

    Problem : lightoj 1098
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
ll sum(ll a,ll b)
{
    ll sum1=0,sum2=0;
    a--;
    if(b%2==0)
    {
        sum1=b/2;
        sum1*=(b+1);
    }
    else
    {
        sum1=(b+1)/2;
        sum1*=b;
    }
    if(a%2==0)
    {
        sum2=a/2;
        sum2*=(a+1);
    }
    else
    {
        sum2=(a+1)/2;
        sum2*=a;
    }
    return sum1-sum2;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=100;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n;
        ll ans=0;
        ll sq=sqrt(n);
        ll prev=0;
        for(ll i=2; i<=sq; i++)
        {
            ans+=((n/i)-1)*i;
            ll tm=n/i;
            if(prev!=0)
            {
                ans+=(sum(tm+1,prev-1)*(i-2));
            }
            prev=tm;
            if(tm!=i)
            {
                ans+=((n/tm)-1)*tm;
                if(i==sq)
                {
                    ans+=(sum(i+1,tm-1)*(i-1));
                }
            }
        }
        cout<<"Case "<<test<<": "<<ans<<endl;
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


