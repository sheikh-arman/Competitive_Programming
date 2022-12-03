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
int mem[2001][2001][27];
string s;
ll dp(ll left,ll right,ll pre)
{
    if(left>=right)
    {
        ll an;
        ll val=s[left]-'a';
        if(pre>val)an=0;
        else if(pre<val) an=2;
        else an=1;
        return an;
    }
    if(mem[left][right][pre]!=-1)
    {
        return mem[left][right][pre];
    }
    if((right-left)%2!=0)
    {
        ll ans=max(dp(left+1,right,s[left]-'a'),dp(left,right-1,s[right]-'a'));
        return mem[left][right][pre]=ans;
    }
    else
    {
        ll ans1=dp(left+1,right,pre);
        ll ans2=dp(left,right-1,pre);
        ll ans=min(ans1,ans2);
        if(ans==1)
        {
            ans=3;
            if(ans1==1)
            {
                ll val=s[left]-'a';
                if(pre>val)ans=0;
                else if(pre<val) ans=2;
                else ans=1;
            }
            if(ans2==1)
            {
                ll ans2;
                ll val=s[right]-'a';
                if(pre>val)ans2=0;
                else if(pre<val) ans2=2;
                else ans2=1;
                ans=min(ans,ans2);
            }
        }
        return mem[left][right][pre]=ans;
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {

        cin>>s;
        ll n=s.size();
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<n; j++)
            {
                for(ll k=0; k<26; k++)
                {
                    mem[i][j][k]=-1;
                }
            }
        }
        ll ans=dp(0,n-1,0);
         if(ans==1)
        {
            cout<<"Draw\n";
        }
        else
        {
            cout<<"Alice\n";
        }
    }
    return 0;
}

/*

afaada

*/





