/*
  Sk arman Hossain
  University of Barisal

 Problem name : 1412 - Visiting Islands
 Algorithm : BFS
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
vector<int>edge[100010],visit;
vector<PR>V;
bool color[100010];
bool cmp(PR a,PR b)
{
    if(a.first==b.first)
        return a.second>b.second;
    else
        return a.first>b.first;
}
int label[100010],long_node,cnt,best,final_best,total_node;
void CLEAR()
{
    //long_node=cnt=final_best=
    final_best=total_node=0;
    memset(label,-1,sizeof(label));
    memset(color,false,sizeof(color));
    V.clear();
}
void dfs(int u)
{
    int i;color[u]=true;
    visit.PB(u);
    int l=edge[u].size();
    for(i=0; i<l; i++)
    {
        int v=edge[u][i];
        if(label[v]<0)
        {
            label[v]=label[u]+1;
            dfs(v);
        }
    }

}
void solve(int start)
{
    best=0;
    //memset(label,-1,sizeof(label));
    label[start]=0;
    visit.clear();
    dfs(start);
    best=start;
    int l=visit.size();
    for(int i=0; i<l; i++)
        if(label[visit[i]]>label[best]) best=visit[i];
   //memset(label,-1,sizeof(label));

    for(int i=0; i<l; i++) label[visit[i]]=-1;
    visit.clear();
    label[best]=0;
    dfs(best);
    for(int i=0; i<l; i++)
        if(label[visit[i]]>label[best]) best=visit[i];
    V.PB({l,label[best]});
    final_best=max(final_best,label[best]);
    total_node=max(total_node,l);//printf("%d %d b\n",l+1,label[best]);
}
int main()
{
     //freopen("1input.txt","r",stdin);
    int tcase=1;
    sf(tcase);
    for(int test=1; test<=tcase; test++)
    {
        CLEAR();
        int n,m,ma=0;
        sff(n,m);
        for(int i=0; i<m; i++)
        {
            int a,b;
            sff(a,b);
            edge[a].PB(b);
            edge[b].PB(a);

        }
        for(int i=1; i<=n; i++)
        {
            if(color[i]==false)
            {
                solve(i);
            }
        }
        sort(V.begin(),V.end(),cmp);
        int query;
        sf(query);
        printf("Case %d:\n",test);
        for(int i=0; i<query; i++)
        {
            int a;
            sf(a);
            if(a-1<=final_best)
            {
                printf("%d\n",a-1);
            }
            else if(a>total_node)
            {
                printf("impossible\n");
            }
            else
            {
                int l=V.size();
                int ans=INT_MAX;
                for(int j=0; j<l; j++)
                {
                    if(V[j].first<a)break;
                    ans=min(ans,((a-V[j].second-1)*2)+V[j].second);
                    //printf("%d %d\n",V[j].first,V[j].second);
                }
                printf("%d\n",ans);
            }
        }
        for(int i=1; i<=n; i++)
        {
            edge[i].clear();
        }
        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
