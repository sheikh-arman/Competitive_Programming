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
vector<ll>V,prime_list;
bitset<10000010>color;
void seive()
{
    color[0]=color[1]=0;
    for(int i=4; i<=3200; i+=2)
    {
        color[i]=0;
    }
    prime_list.PB(2);
    for(ll i=3; i<=3200; i+=2)
    {
        if(color[i]==1)
        {
            prime_list.PB(i);
            for(ll j=i*i; j<=3200; j+=(2*i))
            {
                color[j]=0;
            }
        }
    }
}
int main()
{
    color.set();
    seive();
    color.reset();
    //cout<<prime_list.size();
    //freopen("1input.txt","r",stdin);
    //freopen("1output1.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            color[a]=1;
        }
        ll q;
        cin>>q;
        for(ll i=0; i<q; i++)
        {
            ll a,sum=1;
            cin>>a;
            vector<ll>cnt;
            for(ll i:prime_list)
            {
                if(a%i==0)
                {
                    ll cn=0;
                    while(a%i==0)
                    {
                        a/=i;
                        cn++;
                    }
                    if(color[i]==1)
                        cnt.PB(cn);
                    sum*=(cn+1);
                }
                if((i*i)>=a)
                {
                    break;
                }
            }
            if(a>1)
            {
                if(color[a]==1)
                {
                    cnt.PB(1);
                }
                sum*=2;
            }
            ll ans=0;
            for(ll i:cnt)
            {
                ans+=i;
                ans+=(i*((sum/(i+1))-1));
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}



