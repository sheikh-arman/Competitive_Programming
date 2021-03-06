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
vector<int>V[30010],V2,V3;
map< pair<int,int>,int >M;
bool color[30010];
int label[30010],newlabel[30010];
int ans=0,maxnode=0,farnode1,farnode2,maxweight,ck;
void dfs(int node,int weight)
{
    color[node]=false;
    int len=V[node].size();
    for(int i=0; i<len; i++)
    {
        int temp=V[node][i];
        if(color[temp]==true)
        {
            color[temp]=false;
            if(ans<M[make_pair(node,temp)]+weight)
            {
                ans=M[make_pair(node,temp)]+weight;
                maxnode=temp;
            }
            dfs(temp,weight+M[make_pair(node,temp)]);
        }
    }
}
void dfs2(int node,int weight)
{
    color[node]=false;
    int len=V[node].size();
    for(int i=0; i<len; i++)
    {
        int temp=V[node][i];
        if(color[temp]==true)
        {
            color[temp]=false;
                ans=M[make_pair(node,temp)]+weight;
                if(ck==1){
                    newlabel[temp]=ans;

                    }
                else {
                        label[temp]=ans;

                }
            dfs2(temp,weight+M[make_pair(node,temp)]);
        }
    }
}
void CLEAR()
{
    for(int i=0; i<30005; i++)
    {
        V[i].clear();
    }
    M.clear();
    ans=0;
    ck=0;
}
int main()
{
     ///freopen("input.txt","r",stdin);
    int tcase=1;
    sf(tcase);
    for(int test=1; test<=tcase; test++)
    {
        CLEAR();
        maxnode=0;
        int a,b,e,n;
        sf(n);
        for(int i=0; i<n-1; i++)
        {
            sff(a,b);
            sf(e);
            V[a].PB(b);
            V[b].PB(a);
            M[ {a,b}]=e;
            M[ {b,a}]=e;
        }
        memset(color,true,sizeof(color));
        dfs(0,0);

        memset(color,true,sizeof(color));
        ans=0;
        farnode1=maxnode;

        dfs(farnode1,0);

         memset(color,true,sizeof(color));
        memset(label,0,sizeof(label));
        farnode2=maxnode;
        dfs2(farnode1,0);

        ck=1;
         memset(newlabel,0,sizeof(newlabel));
         memset(color,true,sizeof(color));
        dfs2(farnode2,0);

        //printf("%d f %d\n",farnode1,farnode2);

        printf("Case %d:\n",test);
        for(int i=0; i<n; i++)
        {
            printf("%d\n",max(label[i],newlabel[i]));
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
