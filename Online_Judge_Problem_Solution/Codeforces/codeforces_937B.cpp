/*
    Sk arman Hossain
    University of Barisal

    Problem name :
    Algorithm :
 */
#include<bits/stdc++.h>
#define nl printf("\n");
#define PR pair<ll,ll>
#define sf1(n) scanf("%lld", &n)
#define sf2(n, m) scanf("%lld %lld",&n,&m)
#define sf3(n, m,k ) scanf("%lld %lld %lld",&n,&m,&k)
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES printf("YES\n")
#define NO printf("NO\n")
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
ll N=40000;
vector<ll>prime_list;
bool prime_ck[40010];
void seive()
{
    prime_ck[0]=prime_ck[1]=1;
    prime_list.push_back(2);
    for(int i=4; i<=N; i+=2)
    {
        prime_ck[i]=1;
    }
    for(int i=3; i<=N; i+=2)
    {
        if(prime_ck[i]==0)
        {
            prime_list.push_back(i);
            for(int j=i+i+i; j<=N; j+=i+i)
            {
                prime_ck[j]=1;
            }
        }
    }
}
int main()
{
    seive();
    ///freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        sf2(n,m);
        ll pos=lower_bound(prime_list.begin(),prime_list.end(),n)-prime_list.begin();
        if(pos>=prime_list.size()){
            pos--;
        }
        else if(prime_list[pos]>n)pos--;
        while(m>n){
            ll ck=0;
            for(ll i=0;i<=pos;i++){
                if(m%prime_list[i]==0){
                    ck=1;
                    break;
                }
            }
            if(ck==0){
                printf("%lld\n",m);return 0;
            }
            m--;
        }
        minus1;
        return 0;
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

