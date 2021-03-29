#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll mi[1000010];
ll ma[1000010];
ll rep[1000010];
ll Find(ll node)
{
    return (rep[node]==node?node:rep[node]=Find(rep[node]));
}
void joint(ll u,ll v)
{
    u=Find(u);
    v=Find(v);
    if(u!=v)
    {
        mi[u]=min(mi[u],mi[v]);
        ma[u]=max(ma[u],ma[v]);
        rep[v]=u;
        //cout<<mi[u]<<" "<<ma[u]<<"\n";
    }

}
int main()
{
    //freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        vector<ll>V;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        for(ll i=0; i<=n; i++)
        {
            mi[i]=V[i];
            ma[i]=V[i];
            rep[i]=i;
        }
        ll q;
        cin>>q;
        for(ll i=0; i<q; i++)
        {
            ll st,u,v;
            cin>>st;
            if(st==1)
            {
                cin>>u>>v;
                joint(u-1,v-1);
            }
            else
            {
                cin>>u;
                u=Find(u-1);
                cout<<abs(mi[u]-ma[u])<<"\n";
            }

        }
    }
    return 0;
}

