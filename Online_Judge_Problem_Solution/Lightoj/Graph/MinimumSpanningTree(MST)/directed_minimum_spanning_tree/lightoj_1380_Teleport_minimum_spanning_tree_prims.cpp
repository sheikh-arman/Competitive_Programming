#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
/*   Black Box    */
struct Edge
{
    int x, y, w;
};
int dmst(int N, vector<Edge> E, int root)
{
    const int oo = 1e9;
    vector<int> cost(N), Back(N), label(N), bio(N);
    int ret = 0;

    for (;;)
    {
        for(int i=0; i<N; i++) cost[i] = oo;
        for (auto e : E)
        {
            if (e.x == e.y) continue;
            if (e.w < cost[e.y]) cost[e.y] = e.w, Back[e.y] = e.x;
        }
        cost[root] = 0;
        for(int i=0; i<N; i++) if (cost[i] == oo) return -1;
        for(int i=0; i<N; i++) ret += cost[i];

        int K = 0;
        for(int i=0; i<N; i++) label[i] = -1;
        for(int i=0; i<N; i++) bio[i] = -1;
        for(int i=0; i<N; i++)
        {
            int x = i;
            for (; x != root && bio[x] == -1; x = Back[x]) bio[x] = i;

            if (x != root && bio[x] == i)
            {
                for (; label[x] == -1; x = Back[x]) label[x] = K;
                ++K;
            }
        }
        if (K == 0) break;

        for(int i=0; i<N; i++) if (label[i] == -1) label[i] = K++;

        for (auto &e : E)
        {
            int xx = label[e.x];
            int yy = label[e.y];
            if (xx != yy) e.w -= cost[e.y];
            e.x = xx;
            e.y = yy;
        }
        root = label[root];
        N = K;
    }
    return ret;
}

int main()
{
     freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        vector<Edge>edj;
        ll n,m,k;
        cin>>n>>m>>k;
        for(ll i=0; i<m; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            Edge temp_edj;
            temp_edj.x=u;
            temp_edj.y=v;
            temp_edj.w=w;
            edj.PB(temp_edj);
        }
        ll ans=dmst(n,edj,k);
        if(ans!=-1)
        {
            cout<<"Case "<<test<<": "<<ans<<"\n";
        }
        else
        {
            cout<<"Case "<<test<<": impossible\n";
        }
    }
    return 0;
}
/*
test case:
2
3 3 0
0 1 5
0 2 100
2 1 3

5 6 0
0 1 5
0 2 100
2 1 3
1 3 5
3 4 5
4 1 1

ans: 103
     113


*/
