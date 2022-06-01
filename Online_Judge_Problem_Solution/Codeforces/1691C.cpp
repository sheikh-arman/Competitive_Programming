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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> policy_set;

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
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll start=-1,en=0,ck=1,res=0;
        for(ll i=0; i<n; i++)
        {
            if(i<n-1)
            {
                if(s[i]=='0'&&s[i+1]=='1')res+=1;
                if(s[i]=='1'&&s[i+1]=='0')res+=10;
                if(s[i]=='1'&&s[i+1]=='1')res+=11;
            }
            if(s[i]=='1')
            {
                if(ck)
                {
                    start=i;
                }
                else
                {
                    en=i;
                }
                ck=0;
            }
        }
        if((s[0]=='1'&&s[n-1]=='1')||start==-1||k==0)
        {
            cout<<res<<"\n";
            continue;
        }
       // cout<<res<<" x\n";
        ll lagbe=0,check=1;
        if(s[n-1]=='0')
        {
            if(en==0)en=start;
            lagbe=(n-1)-en;
            if(lagbe<=k)
            {
                res-=10;
                if(en==0)res+=1;
                if(en==start)
                {
                    check=0;
                }
                k-=lagbe;
            }
        }
        if(s[0]=='0'&&check)
        {
            if(start<=k&&start<n-1)
            {
                res-=1;

            }
        }
        cout<<res<<"\n";
    }
    return 0;
}




