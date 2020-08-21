/*
    Sk arman Hossain
    University of Barisal

    Problem name : Codeforces 1401D
    Solution : DFS
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
ll n,cnt[100010];
vector<ll>edge_freq,edj[100010],V;
bitset<100010>color;
ll mod=1e9+7;
void dfs(ll node)
{
    color[node]=true;
    cnt[node]+=1;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            dfs(i);
            cnt[node]+=cnt[i];
            edge_freq.PB(cnt[i]*(n-cnt[i]));
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>n;
        V.clear();
        edge_freq.clear();
        for(ll i=0; i<=n; i++)
        {
            color[i]=false;
            edj[i].clear();
            cnt[i]=0;
        }
        for(ll i=0; i<n-1; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
        }
        dfs(1);
        sort(edge_freq.begin(),edge_freq.end(),greater<ll>());
        ll m,a;
        cin>>m;
        for(ll i=0; i<m; i++)
        {
            cin>>a;
            V.PB(a);
        }
        sort(V.begin(),V.end(),greater<ll>());
        if(m<n-1)
        {
            for(ll i=m+1; i<=n-1; i++)
            {
                V.PB(1);
            }
            m=n-1;
        }
        n--;
        ll ans=0;
        ll cn=(m-n)+1,tm=edge_freq[0];
        for(ll i=0; i<cn; i++)
        {
            tm=((tm%mod)*(V[i]%mod))%mod;
        }
        ans=tm;
        ans%=mod;
        for(ll i=1; i<n; i++)
        {
            ans+=((edge_freq[i]%mod)*(V[i+cn-1]%mod))%mod;
            ans%=mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
