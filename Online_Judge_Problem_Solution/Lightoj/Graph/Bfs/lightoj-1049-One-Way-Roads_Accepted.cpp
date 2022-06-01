/*
  Sk arman Hossain
  University of Barisal

 Problem name : 1039 - A toy company
 Algorithm : DFS
*/

#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define MP pair<ll,ll>
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
#define fori(n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<int>V[110],V2[110],V3;
map< pair<int,int>,int >M;
bool color[110];

int ans=0;
void dfs(int node)
{
    color[node]=false;
    if(V[node].size()>0)
    {

        if(color[V[node][0]]==true)
        {
            color[V[node][0]]=false;
            dfs(V[node][0]);
        }
        else if(V[node].size()>1)
        {
            if(color[V[node][1]]==true)
                color[V[node][1]]=false;
            dfs(V[node][1]);
        }
        else
        {
            int x=V2[node][0],temp;
            if(color[x]==true)
            {
                temp=x;
                color[temp]=false;
                ans+=M[make_pair(temp,node)];
                dfs(temp);
            }

            else
            {
                ans+=M[make_pair(1,node)];
            }
        }

    }
    else
    {
        int x=V2[node][0],temp;
        if(color[x]==true)
        {
            temp=x;
            color[temp]=false;
            ans+=M[make_pair(temp,node)];
            dfs(temp);
        }
        else if(color[V2[node][1]]==true)
        {
            temp=V2[node][1];
            color[temp]=false;
            ans+=M[make_pair(temp,node)];
            dfs(temp);
        }
        else
        {
            ans+=M[make_pair(1,node)];
        }
    }
}
void CLEAR()
{
    for(int i=0; i<105; i++)
    {
        V[i].clear();
        V2[i].clear();
    }
    memset(color,true,sizeof(color));
    M.clear();
    ans=0;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int tcase=1;
    sf(tcase);
    for(int test=1; test<=tcase; test++)
    {
        CLEAR();

        int a,b,e,n,sum=0;
        sf(n);
        for(int i=0; i<n; i++)
        {
            sff(a,b);
            sf(e);
            sum+=e;
            V[a].PB(b);
            V2[b].PB(a);
            M[ {a,b}]=e;

        }
        dfs(1);
        ans=min(ans,sum-ans);
        printf("Case %d: %d\n",test,ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
/*
1
9
1 2 7
2 3 8
4 3 2
5 4 10
6 5 11
6 7 1
8 7 9
8 9 8
9 1 2
special test*/
