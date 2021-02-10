
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
#define pfn(n) printf("%d\n",n)
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
bitset<1000010>ck;
vector<ll>prime;
void seive()
{
    prime.PB(2);
    for(ll i=3; i<=1000002; i+=2)
    {
        if(ck[i]==0)
        {
            prime.PB(i);
            for(ll j=i*i; j<=1000002; j+=(i+i))
            {
                ck[j]=1;
            }
        }
    }
}
ll fac(ll num, ll a,ll b)
{
    ll sq=sqrt(num);
    ll siz=prime.size();
    ll ans=1;
    ll n=num;
    for(ll i=0; prime[i]<=sq&&i<siz; i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                n/=prime[i];
            }
            ll cnt=0;
            while(a%prime[i]==0)
            {
                a/=prime[i];
                cnt++;
            }
            ll cnt2=0;
            while(b%prime[i]==0)
            {
                b/=prime[i];
                cnt2++;
            }
            ans*=powl(prime[i],(ll)max(cnt,cnt2));
        }
        //sq=sqrt(n);
    }
    if(n>1)
    {
        ll cnt=0;
        while(a%n==0)
        {
            a/=n;
            cnt++;
        }
        ll cnt2=0;
        while(b%n==0)
        {
            b/=n;
            cnt2++;
        }
        ans*=powl(n,(ll)max(cnt,cnt2));
    }
    num*=ans;
    return num;
}
int main()
{
    seive();
    //ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    //cin>>tcase;
    scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll a,b,l;
        scanf("%lld%lld%lld",&a,&b,&l);
        ll gcd=__gcd(min(a,b),max(a,b));
        //a/=gcd;
        //b/=gcd;
        ll ck=0;
        if(l%a||l%b)
        {
            ck=1;
        }
        else
        {
            a/=gcd;
            b/=gcd;
            l/=gcd;
            l/=a;
            l/=b;
            a*=gcd;
            b*=gcd;
            if(__gcd(min(l,a),max(l,a))!=1||__gcd(min(l,b),max(l,b))!=1)
            {
                l=fac(l,a,b);
            }
        }
        if(ck)
        {
            printf("Case %lld: impossible\n",test);
        }
        else
        {
            printf("Case %lld: %lld\n",test,l);
        }
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}
/*critical case
3 4 24
ans 8
4 8 12
ans impossible
3 4 48
ans 16
18 24 432
ans 432
6
3 4 24
3 4 48
4 8 24
4 8 12
2 2 24
18 24 432
Case 1: 8
Case 2: 16
Case 3: 3
Case 4: impossible
Case 5: 24
Case 6: 432
*/


