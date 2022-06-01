/*
    Sk arman Hossain
    University of Barisal

    Problem : spoj_SUBMERGE-Submerging_Islands
    Solution : DFS(articulation_point)
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bitset<10010>color,art_ck;
vector<ll>edj[10010];
ll start[10010];
ll en[10010],cnt;
ll parent[10010];
void dfs(ll node)
{
    color[node]=true;
    start[node]=cnt;
    en[node]=cnt++;
    ll child=0;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            parent[i]=node;
            child++;
            color[i]=true;
            dfs(i);
            en[node]=min(en[i],en[node]);
            if(parent[node]==-1&&child>1)
            {
                art_ck[node]=1;
            }
            if(parent[node]!=-1&&start[node]<=en[i])
            {
                art_ck[node]=1;
            }
        }
        else
        {
            if(parent[node]!=i)
                en[node]=min(start[i],en[node]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1,n,m;
    //sf1(tcase);
    while(cin>>n>>m&&(n||m))
    {
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            color[i]=false;
            art_ck[i]=false;
            parent[i]=-1;
        }
        for(ll i=0; i<m; i++)
        {
            ll a,b;
            cin>>a>>b;
            edj[a].push_back(b);
            edj[b].push_back(a);
        }
        cnt=1;
        dfs(1);
        ll ans=0;
        for(ll i=1; i<=n; i++)
        {
            if(art_ck[i]==true)
            {
                ans++;
            }

        }
        cout<<ans<<"\n";

    }
///*****************************  ALHAMDULILLAH  *****************************/
}
/*
3 3
1 2
2 3
1 3
6 8
1 3
6 1
6 3
4 1
6 4
5 2
3 2
3 5
0 0
*/
