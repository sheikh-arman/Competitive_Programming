
/*
  Sk arman Hossain
  University of Barisal

 Problem name : lightoj-1174 - Commandos
 Algorithm : BFS
*/


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
vector<int>nod[MAX],v3;
vector<pair<int,int> >v2;
//vector<pair<int,int> > :: iterator it1,it2;
vector<int> :: iterator it1,it2;
int source_dis[MAX],dis_dis[MAX],clr[MAX];
int cost[MAX][MAX];
int node,edge,s=1;
void bfs(int startingnode)
{
    if(s)
    {
        source_dis[startingnode]=0;
    }
    else
    {
        dis_dis[startingnode]=0;
    }
    queue< int >q;
    q.push(startingnode);
    clr[startingnode]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        int siz=nod[x].size();
        for(int i=0; i<siz; i++)
        {
            int tmp=nod[x][i];
            if(clr[tmp]==0)
            {
                q.push(tmp);
                clr[tmp]=1;
                if(s)
                {
                    source_dis[tmp]=source_dis[x]+1;
                }
                else
                {
                    dis_dis[tmp]=dis_dis[x]+1;
                }
            }

        }
    }
}
int main ()
{
    //fast;
    int tcase,cnt=1;
    sf(tcase);
    while(tcase--)
    {
        for(int i=0; i<MAX; i++)
        {
            nod[i].clear();
        }
        int node,edge,n3,ma=-1;
        sff(node,edge);
        int n1,n2;
        for(int i=0; i<edge; i++)
        {
            sff(n1,n2);
            nod[n1].pb(n2);
            nod[n2].pb(n1);
        }
        int st,di;
        sff(st,di);
        s=1;
        memset(clr,0,sizeof(clr));
        bfs(st);
        memset(clr,0,sizeof(clr));
        s=0;
        bfs(di);
        for(int i=0; i<node; i++)
        {
            ma=max(source_dis[i]+dis_dis[i],ma);
        }
        printf("Case %d: %d\n",cnt++,ma);
    }
    return 0;
}

