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
ll n;
ll cnt_freq(ll num)
{
    ll cnt=0;
    while(num)
    {
        cnt++;
        num/=10;
    }
    return cnt;
}
map< pair<ll,ll>, ll>mp;
ll bfs(ll x)
{
    queue<pair<ll,ll> >q;
    q.push({x,0});
    ll ans=LONG_LONG_MAX;
    while(!q.empty())
    {
        pair<ll,ll> pa=q.front();
        q.pop();
        ll num=pa.first;
        ll cost=pa.second;
        ll save_num=num;
        ll cnt=cnt_freq(num);
        if(cnt==n)
        {
            return  cost;
        }
        if(cnt>n)
        {
            continue;
        }
        ll ar[11];
        for(ll i=1; i<=9; i++)
        {
            ar[i]=0;
        }
        while(num)
        {
            ar[num%10]=1;
            num/=10;
        }
        for(ll i=9; i>=2; i--)
        {
            if(ar[i]>0)
            {
                ll new_x=save_num*i;
                if(mp.count({new_x,cost+1})==0)
                {
                    q.push({new_x,cost+1});
                    mp[ {new_x,cost+1}]=1;
                }
            }
        }
    }
    if(ans==LONG_LONG_MAX)
    {
        ans=-1;
    }
    return ans;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    // cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll x;
        cin>>n>>x;
        ll ans=bfs(x);
        cout<<ans<<"\n";
    }
    return 0;
}





