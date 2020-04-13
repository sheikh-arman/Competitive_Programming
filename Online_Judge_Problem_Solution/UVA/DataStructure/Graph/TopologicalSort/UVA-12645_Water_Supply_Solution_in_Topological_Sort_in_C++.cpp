/*
    Author : SK Arman Hossain
    University of Barishal
    Problem: UVA-12645 Water Supply
    Solution:Topological Sort + DFS
*/
#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
vector< pair<ll,ll> >V;
vector<ll>edj[100010];
ll ending[100010],cnt;
bitset<100010>color;
void topo_sort(ll node)
{
    cnt++;
    color[node]=true;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            topo_sort(i);
        }
    }
    ending[node]=cnt++;
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,e;
    while(scanf("%lld%lld",&n,&e)!=EOF)
    {
        V.clear();
        cnt=1;
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            color[i]=false;
        }
        for(ll i=0; i<e; i++)
        {
            ll a,b;
            cin>>a>>b;
            edj[a].PB(b);
        }
        for(ll i=0; i<n; i++)
        {
            if(color[i]==false)
            {
                topo_sort(i);
            }
        }
        for(ll i=0; i<=n; i++)
        {
            V.PB({ending[i],i});
        }
        sort(V.begin(),V.end());
        //reverse(V.begin(),V.end());
        ll ans=0;
        for(ll i=0; i<=n; i++)color[i]=false;
        topo_sort(0);
        for(ll i=n; i>=0; i--)
        {
            if(color[V[i].second]==false)
            {
                ans++;
                topo_sort(V[i].second);
            }
        }
        printf("%lld\n",ans);
    }
    ///***************Alhamdulillah*************///
    return 0;
}


