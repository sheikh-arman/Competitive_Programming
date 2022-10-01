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
ll mem[210][210];
l mod=998244353;
ll dp(ll n,ll k)
{
    if(k>n)
    {
        return 0;
    }
    if(k==n||k==0)
    {
        return 1;
    }
    if(mem[n][k]>0)
    {
        return mem[n][k]%mod;
    }
    return mem[n][k]=(dp(n-1,k)+dp(n-1,k-1))%mod;
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
        ll n,sum=0;
        vector<ll>V;
        for(ll i=1; i<=6; i++)
        {
            V.PB(i);
        }
        set<vector<ll>>st;
        do
        {
            vector<ll>V1;
            for(ll i=0; i<3; i++)
            {
                V1.PB(V[i]);
            }
            VST(V1);
            st.insert(V1);
            //cout<<"\n";
        }
        while(next_permutation(V.begin(),V.end()));
        cout<<st.size()<<"\n";
        for(auto j:st)
        {
            vector<ll>V1=j;
            for(ll i=0; i<3; i++)
            {
                cout<<" "<<V1[i];
            }
            cout<<"\n";
        }
    }
    return 0;
}







