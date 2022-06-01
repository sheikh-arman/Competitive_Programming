#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
vector<ll>edj[20000];
vector<pair<ll,ll> >V;
bool color[20000];
ll ending[20000],cnt;
void dfs(ll node)
{
    cnt++;
    color[node]=true;
    ll siz=edj[node].size();
    for(ll i=0; i<siz; i++)
    {
        ll tm=edj[node][i];
        if(color[tm]==false)
        {
            color[tm]=true;
            dfs(tm);
        }
    }
    ending[node]=cnt++;
}
int main()
{
    ll TCASE=1;
    scanf("%lld",&TCASE);
    for(ll TEST=1; TEST<=TCASE; TEST++)
    {
        ll n,m;
        cnt=1;
        scanf("%lld%lld",&n,&m);
        for(ll i=0; i<=n; i++)
        {
            color[i]=false;
            edj[i].clear();
        }
        V.clear();
        for(ll i=0; i<m; i++)
        {
            ll a,b;
            scanf("%lld%lld",&a,&b);
            edj[a].PB(b);

        }
        for(ll i=1; i<=n; i++)
        {
            if(color[i]==false)
            {
                dfs(i);
            }
            V.PB({ending[i],i});
        }
        sort(V.begin(),V.end());
        ll ans=0;
        for(ll i=1; i<=n; i++)
        {
            color[i]=false;
        }
        for(ll i=n-1; i>=0; i--)
        {
            if(color[V[i].second]==false)
            {
               // printf("%lld tt\n",V[i].second);
                ans++;
                dfs(V[i].second);
            }
        }
        printf("Case %lld: %lld\n",TEST,ans);
        //return 0;

    }
}
