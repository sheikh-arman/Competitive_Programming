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
ll ar[500010][32];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    cin>>tcase;
    for(ll i=0; i<tcase; i++)
    {
        for(ll j=0; j<30; j++)
        {
            ar[i][j]=0;
        }
    }
    for(ll test=1; test<=tcase; test++)
    {
        ll a;
        cin>>a;
        ll cnt=0;
        while(a)
        {
            if(a%2)
            {
                ar[test-1][cnt]++;
            }
            cnt++;
            a/=2;
        }
        if(test>1)
        {
            for(ll i=0; i<30; i++)
            {
                ar[test-1][i]+=ar[test-2][i];
            }
        }
    }
    ll orr=0,andd=0;
    ll pow=1;
    ll n=tcase;
    for(ll i=0; i<30; i++)
    {
        ll one=ar[n-1][i];
        ll tm=one*(n-one);
        tm+=(one*(one-1))/2;
        orr+=tm*pow;
        tm=(one*(one-1))/2;
        andd+=tm*pow;
        pow*=2;
    }
    cout<<abs(orr-andd)<<"\n";
    return 0;
}




