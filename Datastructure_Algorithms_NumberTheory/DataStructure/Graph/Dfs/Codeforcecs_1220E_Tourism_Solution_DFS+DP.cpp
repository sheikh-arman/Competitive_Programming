
/*
    Sk arman Hossain
    University of Barisal

    Problem name : 1220E
    Algorithm : dfs + dp
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
#define  ff first
#define ss second
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<int>edge[200010];
ll w[200010],ma=0;
bool cycle[200010];
bool color[200010];
bool cycle_create(int node,int parent){
    color[node]=true;
    int l=edge[node].size();
    bool ckcycle=false;
    for(int i=0;i<l;i++){
        int tm=edge[node][i];
        if(color[tm]==true&&tm!=parent){
            ckcycle=true;
        }
        else if(color[tm]==false){
            color[tm]=true;
            int x=cycle_create(tm,node);
            if(ckcycle||x)
                ckcycle=true;
        }
    }
    return cycle[node]=ckcycle;
}
void dfs(int node,ll ans)
{
    ma=max(ans,ma);
    color[node]=1;
    int l=edge[node].size();
    for(int i=0; i<l; i++)
    {
        int tm=edge[node][i];
        if(color[tm]==false)
        {
            color[tm]=1;
            //ans+=w[tm];
            dfs(tm,ans+w[tm]);
        }
    }
}
int main()
{
    ///freopen("1input.txt","r",stdin);
    int tcase=1;
    for(int test=1; test<=tcase; test++)
    {
        memset(color,false,sizeof(color));
        int n,e;
        ll sum=0;
        sf(n);
        sf(e);
        for(int i=1; i<=n; i++)
        {
            int a;
            sf(a);
            w[i]=(ll)a;
        }
        for(int i=0; i<e; i++)
        {
            int a,b;
            sff(a,b);
            edge[a].PB(b);
            edge[b].PB(a);
        }
        int s;
        sf(s);
        cycle_create(s,0);
        memset(color,false,sizeof(color));
        if(cycle[s]==false)cycle[s]=true;
        for(int i=1;i<=n;i++){
            if(cycle[i]==true){
                color[i]=true;
                sum+=w[i];
                //printf("%d\n",i);
            }
        }
        for(int i=1;i<=n;i++){
            if(cycle[i]==true){
                color[i]=true;
                dfs(i,0);
            }
        }
        //printf("%d\n",ma);
        sum+=ma;
        printf("%lld\n",sum);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


