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
vector<ll>V;
ll query(ll a,ll b)
{
    ll x;
    cout<<"? "<<a<<" "<<b<<"\n";
    cin>>x;
    return x;
}
ll cal(ll a,ll b,ll c,ll d)
{
    ll x=query(a,c);
    if(x==1)
    {
        x=query(a,d);
        if(x==1)
        {
            return a;
        }
        else
        {
            return d;
        }
    }
    else if(x==2)
    {
        x=query(c,b);
        if(x==1)
        {
            return c;
        }
        else
        {
            return b;
        }
    }
    else
    {
        x=query(d,b);
        if(x==1)
        {
            return d;
        }
        else
        {
            return b;
        }
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    fflush(stdout);
    ll tcase=1;
     cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        V.clear();
        n=pow(2,n);
        for(ll i=1; i<=n; i++)
        {
            V.PB(i);
        }
        while(n>=4)
        {
            vector<ll>V2;
            for(ll i=0; i<n; i+=4)
            {
                ll x=cal(V[i],V[i+1],V[i+2],V[i+3]);
                V2.PB(x);
            }
            V.clear();
            V=V2;
            n=V.size();
        }
        ll ans;
        if(n==1)
        {
            ans=V[0];
        }
        else
        {

            ll x=query(V[0],V[1]);
            if(x==1)
            {
                ans=V[0];
            }
            else
            {
                ans=V[1];
            }

        }
        cout<<"! "<<ans<<"\n";

    }
    return 0;
}




