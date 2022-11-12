/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
    Date:
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define sf(n) scanf("%lld",&n);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define nl cout<<"\n";
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
#define MAX 2000010
#define T(n) printf("test : %d\n",n);
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
#define MAX 40000
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
}
vector<ll> fact(ll n)
{
    vector<ll>V;
    for(ll i:prime_list)
    {
        if(i*i>n)break;
        if(n%i==0)
        {
            V.PB(i);
        }
        while(n%i==0)
        {
            n/=i;
        }
    }
    if(n>1)
    {
        V.PB(n);
    }
    return V;
}
int main()
{
    seive();
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        ll gcd=__gcd(n,m);
//        if(gcd==1)
//        {
//            if(n==m)
//            {
//                YES;
//            }
//            else
//            {
//                NO;
//            }
//            continue;
//        }
        ll num1=gcd;
        ll num2=m/gcd;
        ll ck=0;
        if(num1<=num2)
        {
            vector<ll>V;
            V=fact(num1);
            for(ll i:V)
            {
                while(num2%i==0)num2/=i;
            }
            if(num2==1)ck=1;
        }
        else
        {
            vector<ll>V;
            V=fact(num2);
            ll cc=1;
            for(ll i:V)
            {
                if(num1%i!=0)cc=0;
            }
            if(cc==1)ck=1;
        }
        if(ck)
        {
            YES;
        }
        else
        {
            NO;
        }
    }
    return 0;
}






