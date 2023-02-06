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
ll color[200010];
ll ar1[200100];
ll ar2[200100];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        vector< pair<ll,ll> > V,V_rev;
        cin>>n>>m;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB({a+i+1,i+1});
            V_rev.PB({a+(n-i),i+1});
            color[i+1]=0;
            ar1[i+1]=a+i+1;
            ar2[i+1]=a+(n-i);
        }
        VST(V);
        reverse(V.begin(),V.end());
        VST(V_rev);
        reverse(V_rev.begin(),V_rev.end());
        ll ans=0;
        ll ck=0;
        while(m>0)
        {
            while((ll)V.size())
            {
                ll siz=V.size();
                if(color[V[siz-1].second]==1)
                {
                    V.pop_back();
                }
                else
                {
                    break;
                }
            }
            while((ll)V_rev.size())
            {
                ll siz=V_rev.size();
                if(color[V_rev[siz-1].second]==1)
                {
                    V_rev.pop_back();
                }
                else
                {
                    break;
                }
            }
            if((ll)V.size()&&V_rev.size())
            {
                ll siz1=V.size();
                ll siz2=V_rev.size();
                ll val1=V[siz1-1].first;
                ll val2=V_rev[siz2-1].first;
                if(val1<=val2)
                {
                    if(m>=val1)
                    {
                        ck=1;
                        m-=val1;
                        color[V[siz1-1].second]=1;
                        V.pop_back();
                        ans++;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if(m>=val2)
                    {

                        m-=val2;
                        color[V_rev[siz2-1].second]=1;
                        V_rev.pop_back();
                        ans++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }

        if(!ck&&ans)
        {
            ans--;
            ll mi=1000000000000;
            for(ll i=1; i<=n; i++)
            {
                if(color[i]==0)
                {
                   mi=min(mi,ar1[i]);
                }
            }
            ll ma=0;
            for(ll i=1; i<=n; i++)
            {
                if(color[i]==1){
                    ll tm_mi=min(mi,ar1[i]);
                    m+=ar2[i];
                    if(m>=tm_mi){
                        ans++;break;
                    }
                }
            }
            
        }
        cout<<ans<<"\n";
    }
    return 0;
}





