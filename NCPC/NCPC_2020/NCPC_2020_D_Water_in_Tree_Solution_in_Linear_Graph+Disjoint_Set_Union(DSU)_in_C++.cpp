/*
    Author:SK Arman Hossain
    University of Barishal

    Problem:NCPC-2020-D. Water in Tree
    Solution: Disjoint_Set_Union + Linear_Graph

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 200010
bool visited[N];
bool color[N];
ll starting[N];
ll ending[N],cnt;
ll COUNT[N],rep[N],position[N];
vector<ll>end_time,edj[N];
vector<ll>::iterator it;
vector< pair<ll,ll> >V;
void dfs(ll node)
{
    starting[node]=cnt++;
    visited[node]=true;
    ll siz=edj[node].size();
    for(ll i=0; i<siz; i++)
    {
        ll child=edj[node][i];
        if(visited[child]==false)
        {
            visited[child]=true;
            dfs(child);
        }
    }
    ending[node]=cnt++;
}
ll fin(ll node)
{
    return (node==rep[node]?node:rep[node]=fin(rep[node]));
}
void joint(ll u,ll v,ll c)
{
    ll repu=fin(u);
    ll repv=fin(v);
    if(repu!=repv)
    {
        if(COUNT[repu] > COUNT[repv])
        {
            COUNT[repu]+=COUNT[repv];
            rep[repv]=repu;
            position[repu]=max(position[repu],position[repv])+c;
        }
        else
        {
            COUNT[repv]+=COUNT[repu];
            rep[repu]=repv;
            position[repv]=max(position[repu],position[repv])+c;
        }
    }
    else
    {
        position[repu]++;
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tcase=1;
    cin>>tcase;
    for(ll TEST=1; TEST<=tcase; TEST++)
    {
        ll n,query;
        cin>>n;
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            color[i]=false;
            visited[i]=false;
            position[i]=i;
            rep[i]=i;
            COUNT[i]=1;
        }
        V.clear();
        end_time.clear();
        for(ll i=1; i<n; i++)
        {
            ll u,v;
            cin>>u>>v;
            it=lower_bound(edj[u].begin(),edj[u].end(),v);
            edj[u].insert(it,v);

            it=lower_bound(edj[v].begin(),edj[v].end(),u);
            edj[v].insert(it,u);
        }
        cnt=1;
        dfs(1);
        for(ll i=1; i<=n; i++)
        {
            V.push_back({ending[i],i});
        }
        sort(V.begin(),V.end());
        for(ll i=0; i<n; i++)
        {
            end_time.push_back(V[i].first);
        }
        ll cn=0;
        cin>>query;
        cout<<"Case "<<TEST<<":\n";
        for(ll i=1; i<=query; i++)
        {
            ll a;
            cin>>a;
            if(a==1)
            {
                ll u,k;
                cin>>u>>k;
                if(cn<n)
                {
                    ll pos=lower_bound(end_time.begin(),end_time.end(),starting[u])-end_time.begin();
                    ll tm_re=fin(pos);
                    while(k)
                    {
                        ll te=0;
                        ll pos=position[tm_re];
                        while(pos<n)
                        {
                            if(V[pos].first>ending[u])
                            {
                                break;
                            }
                            if(color[V[pos].second]==false)
                            {

                                joint(pos,tm_re,1);
                                cn++;
                                te=1;
                                color[V[pos].second]=true;
                                break;
                            }
                            else
                            {
                                joint(pos,tm_re,0);
                                tm_re=fin(pos);
                                pos=position[tm_re];
                            }
                        }
                        if(te==0)break;
                        k--;
                    }
                }
            }
            else
            {
                ll u;
                cin>>u;
                cout<<color[u]<<"\n";
            }
        }

    }
///*************Alhamdulillah****************/////
}
