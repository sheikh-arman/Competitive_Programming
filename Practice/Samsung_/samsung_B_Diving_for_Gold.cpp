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
ll t,w,n;
ll mem[33][1010];
ll previous[33][1010];
vector<pair<ll,ll>>treasure;
ll dp(ll pos, ll prev, ll have)
{
    //T(1);
    if(pos>=n)
    {
        return 0;
    }
    if(mem[pos][have]!=-1)
    {
        return mem[pos][have];
    }
    ll without_current=dp(pos+1,prev,have);
    ll depth=treasure[pos].first;
    ll gold=treasure[pos].second;
    ll with_current=0;
    if((depth*3*w)<=have)
    {
        with_current=dp(pos+1,pos,have-(depth*3*w))+gold;
    }
    if(without_current>with_current)
    {
        previous[pos][have]=pos+1;
    }
    else
    {
        previous[pos][have]=pos;
    }
    return mem[pos][have]=max(without_current,with_current);
}
int main()
{
    // freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll ck=0;
    while(scanf("%lld%lld",&t,&w)!=EOF)
    {
        // cin>>t>>w;
        cin>>n;
        treasure.clear();
        for(ll i=0; i<n; i++)
        {
            ll width,gold;
            cin>>width>>gold;
            treasure.PB({width,gold});
        }
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=t; j++)
            {
                mem[i][j]=-1;
                previous[i][j]=-1;
            }
            // previous[i]=-1;
        }
        ll ans=dp(0,-1,t);
        if(ck)
        {
            cout<<"\n";
        }
        ck=1;
        cout<<ans<<"\n";
        vector<ll>path;
        ll index=0;
        while(ans&&index<n)
        {
            //cout<<index<<" "<<ans<<" "<<mem[index][t]<<" "<<previous[index][t]<<" x\n";
            if(index==previous[index][t]&&mem[index][t]==ans)
            {
                path.PB(index);
                ans-=treasure[index].second;
                t-=(treasure[index].first*3*w);
                index++;
                // T(index-1);
            }
            else
            {
                index++;
            }
        }
        ll siz=path.size();
        cout<<siz<<"\n";
        for(ll i=0; i<siz; i++)
        {
            cout<<treasure[path[i]].first<<" "<<treasure[path[i]].second<<"\n";
        }

    }
    return 0;
}




