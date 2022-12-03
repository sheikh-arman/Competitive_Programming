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
ll SET(ll n,ll pos)
{
    return (n|=(1<<pos));
}
ll ison(ll n, ll pos)
{
    return (n&=(1<<pos));
}
vector<pair<ll,ll>>V;
double dist(ll fst,ll snd)
{
    ll x=V[fst].first;
    ll y=V[fst].second;

    ll x2=V[snd].first;
    ll y2=V[snd].second;

    double ans=0;

    ans+=abs(x-x2)*abs(x-x2);
    ans+=abs(y-y2)*abs(y-y2);
    ans=sqrt(ans);

    return ans;
}
double mem[12][1<<12];
ll path[12][1<<12];
ll n;
double dp(ll prev,ll mask)
{
    if(mask==(1<<n)-1)
    {
        return 0;
    }
    if(mem[prev][mask]!=-1)
    {
        return mem[prev][mask];
    }
    double ans=LONG_LONG_MAX;
    for(ll j=0; j<n; j++)
    {
        if(!ison(mask,j))
        {
            ll new_mask=SET(mask,j);
            double tm_ans=dp(j,new_mask)+dist(prev,j);
            if(ans>tm_ans)
            {
                ans=tm_ans;
                path[prev][mask]=j;
            }
        }
    }
    return mem[prev][mask]=ans;
}
vector<ll>pth;
void ph(ll mask,ll fst)
{
    pth.PB(fst);
    ll snd=path[fst][mask];
    ll new_mask=SET(mask,snd);
    if(new_mask==(1<<n)-1)
    {
        pth.PB(snd);
        return;
    }
    ph(new_mask,snd);
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
        ll cnt=1;
        while(cin>>n&&n)
        {
            V.clear();
            pth.clear();
            for(ll i=0; i<=n; i++)
            {
                for(ll j=0; j<(1<<n); j++)
                {
                    mem[i][j]=-1;
                    path[i][j]=-1;
                }
            }
            for(ll i=0; i<n; i++)
            {
                ll a,b;
                cin>>a>>b;
                V.PB({a,b});
            }
            // reverse(V.begin(),V.end());
            double ans=LONG_LONG_MAX;
            ll fst;
            for(ll i=0; i<n; i++)
            {
                double tm_ans=dp(i,SET(0,i));
                if(tm_ans<ans)
                {
                    ans=tm_ans;
                    fst=i;
                }
            }
            ph(SET(0,fst),fst);
            cout<<"**********************************************************\n";
            cout<<"Network #"<<cnt++<<"\n";
            ll pre=-1;
            double answer=0;
            for(ll i:pth)
            {
                if(pre==-1)pre=i;
                else
                {
                    double tm=dist(pre,i)+16;
                    cout<<fixed<<setprecision(2)<<"Cable requirement to connect ("<<V[pre].first<<","<<V[pre].second<<") to ("<<V[i].first<<","<<V[i].second<<") is "<<tm<<" feet.\n";
                    pre=i;
                    answer+=tm;
                }
            }
            cout<<fixed<<setprecision(2)<<"Number of feet of cable required is "<<answer<<".\n";
        }
    }
    return 0;
}





