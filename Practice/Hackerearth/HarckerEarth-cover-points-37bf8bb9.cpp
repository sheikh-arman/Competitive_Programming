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
ll rep[200110];
ll Find(ll node)
{
    return (node==rep[node]?node:rep[node]=Find(rep[node]));
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
        ll n,ck=0;
        cin>>n;
        map<ll,ll>mp;
        vector< pair<pair<ll,ll>,ll>>V;
        vector< pair<pair<ll,ll>,ll>>sort_weight;
        ll m;
        cin>>m;
        set<ll>st;
        for(ll i=0; i<m; i++)
        {
            ll a,b,w;
            cin>>a>>b>>w;
            V.PB({{a,b},w});
            st.insert(a);
            st.insert(b);
            if(a==n||b==n)ck=1;
        }
        ll cnt=1;
        for(ll i:st)
        {
            mp[i]=cnt++;
        }
        for(ll i=0; i<m; i++)
        {
            ll a,b,w;
            a=V[i].first.first;
            b=V[i].first.second;
            w=V[i].second;
            a=mp[a];
            b=mp[b];
            V[i].first.first=w;
            V[i].first.second=a;
            V[i].second=b;
        }
        VST(V);
        for(ll i=0; i<=cnt+1; i++)
        {
            rep[i]=i;
        }
        ll ans=0;
        for(ll i=0; i<m; i++)
        {
            ll a,b,w;
            w=V[i].first.first;
            a=V[i].first.second;
            b=V[i].second;
            a=Find(a);
            if(a<=b)
            {
                ans=w;
                ll cn=0;
                while(a<=b)
                {
                    rep[a]=Find(a+1);
                    a=rep[a];
                }
            }
        }
        ll a=Find(1);
        if(a<cnt||ck==0)ans=-1;
        cout<<ans<<"\n";
    }
    return 0;
}





