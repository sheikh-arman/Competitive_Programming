/*
    Sk arman Hossain
    University of Barisal

    Problem name :
    Algorithm :
 */

#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define PR pair<int,int>
#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d %d",&n,&m)
#define sfl(n) scanf("%lld", &n)
#define sfu(n) scanf("%llu", &n)
#define sffl(n, m) scanf("%lld %lld",&n,&m)
#define pfn(n) printf("%d\n",n)
#define pf(n) printf("%d ",n)
#define pfl(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES printf("YES\n")
#define NO printf("NO\n")
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define ff first
#define ss second
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
#define MAX 100000
vector<ll>prime_list;
bool prime_ck[1000001];
void seive()
{
    prime_ck[0]=prime_ck[1]=true;
    prime_list.push_back(2);
    for(ll i=4; i<=MAX; i+=2)
    {
        prime_ck[i]=true;
    }
    for(ll i=3; i<=MAX; i+=2)
    {
        if(prime_ck[i]==0)
        {
            prime_list.push_back(i);
            for(ll j=i*i; j<=MAX; j+=(i+i))
            {
                prime_ck[j]=1;
            }
        }
    }
    //Here prime_list vector indicate list of all prime number
    //prime_ck array indicate a number is prime ? or not ?
    //if prime_ck[n]=0 then number is prime else not a prime
}
int main ()
{
    seive();
    ll n;
    while(cin>>n)
    {

        if(prime_ck[n]==1)
        {
            printf("Not a Prime");
        }
        else
        {
            printf("Prime");

        }
        cout<<endl;
    }


    return 0;
}

