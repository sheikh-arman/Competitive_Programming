#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define mp pair<ll,ll>
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
#define pb push_back
#define pi 3.1415926536
#define vst(v) sort(v.begin(),v.end())
#define fori(n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MAX 110
int dx[]= {0,0,1,1};
int dy[]= {1,1,0,0};
#define WHITE 2
#define GRAY 3
#define BLACK 4
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;

vector<int>nod[100],v3;
vector<pair<int,int> >v2;
//vector<pair<int,int> > :: iterator it1,it2;
vector<int> :: iterator it1,it2;

int dis[MAX];
int cost[MAX][MAX];
int node,edge;


void bfs(int startingnode)
{
    dis[startingnode]=0;
    priority_queue< pair<int,int> >q;
    q.push({startingnode,0});
    while(!q.empty())
    {
        pair <int,int> x;
        x=q.top();
        q.pop();
        int siz=nod[x.first].size();
        for(int i=0;i<siz;i++){
                int tmp=nod[x.first][i];
                if(dis[x.first]+cost[x.first][tmp]<dis[tmp]){
                    dis[tmp]=dis[x.first]+cost[x.first][tmp];
                    q.push({tmp,dis[tmp]});
            }
        }
    }
}
int main ()
{
    fast;
    int tcase,cnt=1;
    sf(tcase);
    while(tcase--)
    {
        for(int i=0;i<MAX;i++){
            nod[i].clear();
            dis[i]=INT_MAX;
            for(int j=0;j<MAX;j++){
                cost[i][j]=cost[j][i]=INT_MAX;
            }
        }
        int node,edge,n3;
        sff(node,edge);
        int n1,n2;
        for(int i=0; i<edge; i++)
        {
            sff(n1,n2);sf(n3);
            if(n3<cost[n1][n2]){
                nod[n1].pb(n2);
                nod[n2].pb(n1);
                cost[n1][n2]=n3;
                cost[n2][n1]=n3;
            }
        }

        bfs(1);
        printf("Case %d: ",cnt++);
            if(dis[node]!=INT_MAX)
                printf("%d\n",dis[node]);
            else {
                printf("Impossible\n");
            }
    }
    return 0;
}
