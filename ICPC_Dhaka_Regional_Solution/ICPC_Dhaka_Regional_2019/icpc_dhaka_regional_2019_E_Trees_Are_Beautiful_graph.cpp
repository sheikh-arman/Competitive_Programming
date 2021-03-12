#include <bits/stdc++.h>
using namespace std;
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long int ll;
ll label[20010];
ll cnt_node[20010];
vector<ll>edj[20010];
bitset<20010>color;
ll n;
ll dfs(ll node)
{
    color[node]=true;
    ll cnt=1;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            label[i]=label[node]+1;
            cnt+=dfs(i);
        }
    }
    return cnt_node[node]=cnt;
}
int main()
{
    fast;
    //freopen("1input.txt","r",stdin);
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>n;
        for(ll i=0; i<=n; i++)
        {
            cnt_node[i]=0;
            label[i]=0;
            edj[i].clear();
            color[i]=false;
        }
        vector<pair<pair<ll,ll>,ll> >V;
        for(ll i=0; i<n-1; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            edj[u].push_back(v);
            edj[v].push_back(u);
            V.push_back({{u,v},w});
        }
        ll hi=dfs(1);
        vector<pair<ll,ll> >ans;
        ll sum=0;
        for(ll i=0; i<n-1; i++)
        {
            ll total;
            ll u=V[i].first.first;
            ll v=V[i].first.second;
            ll w=V[i].second;
            if(label[u]>label[v])swap(u,v);
            ll fir=n-cnt_node[v];
            ll sec=cnt_node[v];
            total=fir*sec;
            if(w<0)
                ans.push_back({total,abs(w)});
            sum+=(total*w);
        }
        if(sum>=0)
        {
            cout<<"Case "<<test<<": 0\n";
            continue;
        }
        sort(ans.begin(),ans.end(),greater<pair<ll,ll> >());

        ll siz=ans.size();
        sum*=-1;
        ll result=0;
        for(ll i=0; i<siz; i++)
        {
            ll total=ans[i].first;
            ll w=ans[i].second;
            ll lagbe=sum/total+(sum%total!=0);
            ll mi=min(lagbe,w);
            result+=mi;
            sum-=(total*mi);
            if(sum<=0)
            {
                break;
            }
        }
        cout<<"Case "<<test<<": "<<result<<"\n";
        continue;
    }


}
