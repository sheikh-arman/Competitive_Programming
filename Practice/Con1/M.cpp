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
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    // cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;

        vector<ll>V;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        if(n==1)
        {
            cout<<(V[0]+V[0])<<"\n";
            continue;
        }
        VST(V);
        reverse(V.begin(),V.end());
        ll pos=0,value=0;
        for(ll i=1; i<n; i++)
        {
            ll val=i+1;
            ll x=(val*(val-1))/2;
            x*=2;
            x+=val;
            if(x>m)
            {
                break;
            }
            value=x;
            pos=i;
        }
        ll ans=0;
        for(ll i=0; i<=pos; i++)
        {
            ans+=(pos+1)*V[i];
        }
        m-=value;
        if(m)
        {
            ll left=0,right=pos+1,tm_ans=0;
            while(m--)
            {
                tm_ans+=(V[left]+V[right]);
                if(right+1<n)
                {
                    if(left+1<=pos)
                    {
                        if(V[left]+V[right+1]>= V[left+1]+V[right])
                        {
                            right++;
                        }
                        else
                        {
                            left++;
                        }
                    }
                    else
                    {
                        right++;
                    }
                }
                else
                {
                    right=pos+1;
                    left++;
                }
            }
            ans+=tm_ans;
        }
        cout<<ans<<"\n";
    }
    return 0;
}




