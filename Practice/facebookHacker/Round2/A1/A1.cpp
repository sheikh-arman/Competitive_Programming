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
int main()
{
    //freopen("inputA1.txt","r",stdin);
    //freopen("outputA1.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll>A,B;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            A.PB(a);
        }
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            B.PB(a);
        }
        if(n==2)
        {
            ll ck=1;
            if(A[0]!=B[0])ck=0;
            if(k%2==0)
            {
                if(ck)
                {
                    cout<<"Case #"<<test<<": YES\n";
                }
                else
                {
                    cout<<"Case #"<<test<<": NO\n";
                }
            }
            else
            {
                if(!ck)
                {
                    cout<<"Case #"<<test<<": YES\n";
                }
                else
                {
                    cout<<"Case #"<<test<<": NO\n";
                }
            }
        }
        else
        {

            ll ck2=1;
            ll j=0;
            for(ll i=0; i<n; i++)
            {
                if(A[0]==B[i])
                {
                    j=i;
                    break;
                }
            }
            for(ll i=0; i<n; i++)
            {
                if(A[i]!=B[j])
                {
                    ck2=0;
                    break;
                }
                j++;
                j%=n;
            }
            if(!ck2)
            {
                cout<<"Case #"<<test<<": NO\n";
            }
            else
            {
                ll ck=1;
                for(ll i=0; i<n; i++)
                {
                    if(A[i]!=B[i])
                    {
                        ck=0;
                        break;
                    }
                }
                if(k==0)
                {
                    if(ck)
                    {
                        cout<<"Case #"<<test<<": YES\n";
                    }
                    else
                    {
                        cout<<"Case #"<<test<<": NO\n";
                    }
                }
                else if(k==1)
                {
                    if(!ck)
                    {
                        cout<<"Case #"<<test<<": YES\n";
                    }
                    else
                    {
                        cout<<"Case #"<<test<<": NO\n";
                    }
                }
                else
                {
                    cout<<"Case #"<<test<<": YES\n";
                }
            }
        }
    }
    return 0;
}
