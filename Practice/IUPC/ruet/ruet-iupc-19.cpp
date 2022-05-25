// Problem: F. Mathematical Marathon
// Contest: CodeMarshal - Technocracy 2019 by RUET, IUPC
// URL: https://algo.codemarshal.org/contests/ruet-iupc-19/problems/F
// Memory Limit: 1500 MB
// Time Limit: 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std ;

#define   Pi     2*acos(0.0)
#define   ll     long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    500006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element
// also 0 indexed

struct edge
{
    int vertex, weight;
    edge(int a, int b)
    {
        vertex = a;
        weight = b;
    }
};
struct node
{
    int vertex, cost, gcd,main_gcd;
    node(int a, int b, int c,int d)
    {
        vertex = a;
        cost = b;
        gcd = c;
        main_gcd=d;
    }
    bool operator<(node other)const
    {
        return cost > other.cost;
    }
};

int n, m, x, y, w;
vector<edge> g[MAX];
ll Dijkstra(int dest, int source, int gcd)
{
    priority_queue<node> pq;
    unordered_map<ll, ll> dist;
    pq.push(node(source, 0, 1LL,1LL));
    int ck=1;
    while(!pq.empty())
    {

        node u = pq.top();
        pq.pop();
        ll ucost = dist[((ll)u.vertex << 32) + u.gcd];
        //cout<<u.vertex<<" "<<u.cost<<" "<<u.gcd<<" "<<u.main_gcd<<" x\n";
        if((u.vertex == dest) and (u.gcd%u.main_gcd==0&& gcd%u.main_gcd==0 && gcd>=u.gcd)) return u.cost;
        if(u.cost != ucost) continue;
        //cout<<"test\n";
        for(auto v: g[u.vertex])
        {
            int a = v.weight;
            //cout<<a<<" "<<gcd<<" "<<u.main_gcd<<" "<<u.gcd<<" f\n";
            if( a%u.main_gcd!=0|| gcd%u.main_gcd!=0 || a>gcd||u.main_gcd>a)continue;
            if(u.gcd%u.main_gcd!=0|| a%u.main_gcd!=0||a<u.gcd)continue;
            ll val = 1e14;
            //cout<<" hi\n";
            if(dist.count(((ll)v.vertex << 32) + a))val = dist[((ll)v.vertex << 32) + a];
            if(ucost + v.weight < val)
            {
                val = ucost + v.weight;
                x=u.main_gcd;
                if(ck)x=a;
                pq.push(node(v.vertex, val, a,x));
                dist[((ll)v.vertex << 32) + a] = val;
            }
        }
        ck=0;
    }
    return 1e14;
}

int main()
{
    freopen("1input.txt","r",stdin);
    int t;
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i <= n; i++)
        {
            g[i].clear();
        }
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &x, &y, &w);
            g[x].pb(edge(y, w));
            g[y].pb(edge(x, w));
        }
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);
        printf("Case %d: ", cs);
        if(a == b)
        {
            printf("0\n");
            continue;
        }
        ll ans = Dijkstra(a, b, c);

        if(ans > 1e11)
        {
            printf("impossible\n");
        }
        else printf("%lld\n", ans);

    }
}
