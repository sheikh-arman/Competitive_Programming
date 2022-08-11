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
vector<pair<ll,ll>>V;
bool cmp(pair<ll,ll>a, pair<ll,ll>b)
{
    if(a.first!=b.first)
    {
        return a.first>b.first;
    }
    else
    {
        return a.second<b.second;
    }
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
        ll n,m;
        cin>>n>>m;
        for(ll i=0; i<n; i++)
        {
            ll a,b;
            cin>>a>>b;
            V.PB({b,a});
        }
        sort(V.begin(),V.end(),cmp);
        set<ll>st;
        for(ll i=0; i<=m+1; i++)
        {
            st.insert(i);
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            ll val=(m-V[i].second)+1;
            //cout<<val<<" t\n";
            if(val<=0){
                continue;
            }
            auto it=st.lower_bound(val+1);
            if(it==st.begin()){
                continue;
            }
            it--;
            if(*it<=val&&*it>0){
                ans+=V[i].first;
                st.erase(it);
               // cout<<i<<" x\n";
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}




