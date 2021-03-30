
/*
    Sk arman Hossain
    University of Barisal

    Problem name :1379 - Toll Management
    Algorithm :Dijkastra
 */

#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define PR pair<int,int>
#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d %d",&n,&m)
#define sfl(n) scanf("%lld", &n)
#define sfu(n) scanf("%llu", &n)
#define sffl(n, m) scanf("%lld %lld",&n,&m)
#define pfn(n) printf("%d\n",n)
#define pf(n) printf("%d ",n)
#define pfl(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES printf("YES\n")
#define NO printf("NO\n")
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<ll>V,V2,V3;
vector<int>nod[100],v3;
struct pr{
    int cost,max_toll;
}dis[10010];
int color[100];
int parent[100];
map<PR,int>cost;
int node,edge;
void CLEAR()
{
    cost.clear();
    V.clear();
    V2.clear();
    V3.clear();
}

void dijkastra(int startingnode,int max_toll)
{
    for(int i=0; i<10005; i++)
    {
        dis[i].cost=INT_MAX;
    }
    dis[startingnode].cost=0;
    priority_queue< pair<int,int> >q;
    q.push({startingnode,0});
    while(!q.empty())
    {
        PR x;
        x=q.top();
        q.pop();
        int siz=nod[x.first].size();
        for(int i=0; i<siz; i++)
        {
            int tmp=nod[x.first][i];
            if(dis[x.first].first+cost[x.first][tmp]<dis[tmp])
            {
                dis[tmp]=dis[x.first]+cost[x.first][tmp];
                q.push({tmp,dis[tmp]});
            }
        }
    }
}
int main()
{
    ///freopen("1input.txt","r",stdin);
    int tcase=1;
    //sf(tcase);
    for(int test=1; test<=tcase; test++)
    {

        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

