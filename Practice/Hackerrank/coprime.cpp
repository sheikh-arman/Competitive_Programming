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
ll ar[200010];
ll res[200010];
#define MAX 200010
vector<ll>prime_list;
bool prime_ck[MAX+10];
void seive()
{
    prime_ck[0]=prime_ck[1]=true;
    //prime_list.push_back(2);
    ll cnt=0;
    for(ll i=2; i<=MAX; i+=2)
    {
        cnt+=ar[i];
        prime_ck[i]=1;
    }
    for(ll i=2; i<=MAX; i+=2)
    {
        res[i]-=cnt;
    }
    for(ll i=3; i<=MAX; i+=2)
    {
        ll cnt_1st=0;
        ll cnt_2nd=0;
        if(prime_ck[i]==0)
        {
            //prime_list.push_back(i);
            for(ll j=i; j<=MAX; j+=i)
            {
                if(prime_ck[j]==0)
                {
                    cnt_1st+=ar[j];
                }
                else
                {
                    cnt_2nd+=ar[j];
                }
            }
            for(ll j=i; j<=MAX; j+=i)
            {
                if(prime_ck[j]==0)
                {
                    res[j]-=cnt_1st;
                    res[j]-=cnt_2nd;
                }
                else
                {
                    res[j]-=cnt_1st;
                }
                prime_ck[j]=1;
            }
        }
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,sum=0,m;
        cin>>n>>m;
        vector<ll>V;
        for(ll i=1; i<=200000; i++)
        {
            res[i]=n;
        }
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            ar[a]++;
        }
        seive();
        for(ll i=0; i<m; i++)
        {
            ll a;
            cin>>a;
            cout<<res[a]<<"\n";
        }
    }
    return 0;
}




