#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll rep[500010];
ll cnt[500010];
ll Find(ll node)
{
    return (node==rep[node]?node:rep[node]=Find(rep[node]));
}
void joint (ll a,ll b)
{
    ll u=Find(a);
    ll v=Find(b);
    if(u!=v)
    {
        if(cnt[u]<cnt[v])
        {
            swap(u,v);
        }
        cnt[u]+=cnt[v];
        rep[v]=u;
    }
}
ll mod=1e9+7;
ll big_mod(ll n,ll p)
{
    if(p==0)
    {
        return 1LL;
    }
    if(p==1)
    {
        return n;
    }
    if(p%2==0)
    {
        ll tm=big_mod(n,p/2);
        ll val=((tm%mod)*(tm%mod))%mod;
        return val;
    }
    else
    {
        ll val=((big_mod(n,p-1)%mod)*(n%mod))%mod;
        return val;
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=0; i<=n; i++)
        {
            cnt[i]=1;
            rep[i]=i;
        }
        for(ll i=0; i<m; i++)
        {
            ll u,v;
            cin>>u>>v;
            joint(u,v);
        }
        set<ll>st;
        for(ll i=1; i<=n; i++)
        {
            ll u=Find(i);
            st.insert(u);
        }
        vector<ll>V;
        for(ll i:st)
        {
            V.PB(cnt[i]);
        }
        ll k;
        cin>>k;
        for(ll i=0; i<k; i++)
        {
            ll a;
            cin>>a;
            ll ans=1;
            for(ll j:V)
            {
                //cout<<k<<" "<<j<<" \n";
                ll tm=j;
                ll tm_ans=a;
                tm-=1;
                tm=big_mod(a-1,tm);
                //cout<<tm_ans<<" "<<tm<<" hm\n";
                tm_ans=((tm_ans%mod)*(tm%mod))%mod;
                ans*=tm_ans;
                ans%=mod;
                //ans%=mod;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}


