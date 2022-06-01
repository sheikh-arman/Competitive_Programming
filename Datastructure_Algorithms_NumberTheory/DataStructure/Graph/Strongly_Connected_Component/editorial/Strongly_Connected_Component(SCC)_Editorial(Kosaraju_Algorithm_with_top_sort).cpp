/*
    Author : SK Arman Hossain
    University of Barishal
    Problem:
    Solution:Strongly Connected Conponent(Kosaraju_Algorithm)
*/
#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
vector< pair<ll,ll> >V;
vector<ll>edj[30000],trans_edj[30000],ans;
ll ending[30000],cnt;
bitset<30000>color;
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
void dfs(ll node)
{
    ans.PB(node);
    color[node]=true;
    for(ll i:trans_edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            dfs(i);
        }
    }
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll n,e,TEST=1,ck=0;
    while(cin>>n>>e&&(n||e))
    {
        V.clear();
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            trans_edj[i].clear();
            color[i]=false;
        }
        for(ll i=0; i<e; i++)
        {
            ll a,b;
            cin>>a>>b;
            edj[a].PB(b);
            trans_edj[b].PB(a);
        }
        cnt=1;
        for(ll i=1; i<=n; i++)
        {
            if(color[i]==false)
            {
                topo_sort(i);
            }
        }
        for(ll i=1; i<=n; i++)
        {
            V.PB({ending[i],i});
        }
        sort(V.begin(),V.end());
        //reverse(V.begin(),V.end());
        for(ll i=0; i<=n; i++)color[i]=false;
        cout<<"Strongly Connected Components are: \n";
        for(ll i=n-1; i>=0; i--)
        {
            if(color[V[i].second]==false)
            {
                ans.clear();
                dfs(V[i].second);
                ll siz=ans.size();
                for(ll j=0; j<siz; j++)
                {
                    cout<<ans[j]<<" ";
                }
                cout<<"\n";
            }
        }
        cout<<"\n";
    }
    ///***************Alhamdulillah*************///
    return 0;
}
/*
5 6
1 2
2 3
3 4
4 3
3 1
2 5
*/



