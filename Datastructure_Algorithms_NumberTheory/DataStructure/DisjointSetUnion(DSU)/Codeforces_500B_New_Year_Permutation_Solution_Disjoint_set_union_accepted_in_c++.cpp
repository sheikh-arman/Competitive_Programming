
/*
    Sk arman Hossain
    University of Barisal

    Problem name : 500B-New_Year_Permutation
    Algorithm :Disjoint set union(dsu)
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
vector<int>V;
deque<int>V2;
int rep[303];
bool color[303];
void initial(int n)
{
    for(int i=1; i<=n; i++)
    {
        rep[i]=i;
    }
}
int find_representative(int node)
{
    if(rep[node]==node)
    {
        return node;
    }
    else
    {
        rep[node]=find_representative(rep[node]);
        return rep[node];
    }
}
void joint_node(int nodex,int nodey)
{
    int u=find_representative(nodex);
    int v=find_representative(nodey);
    if(u!=v)
    {
        rep[u]=v;
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    int tcase=1;
    //sf(tcase);
    for(int test=1; test<=tcase; test++)
    {
        memset(color,0,sizeof(color));
        int n,e,ans=0;
        sf(n);
        for(int i=0; i<n; i++)
        {
            int a;
            sf(a);
            V.PB(a);
        }
        initial(n);
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            for(int j=0; j<n; j++)
            {
                if(s[j]=='1')
                    joint_node(V[i],V[j]);
            }
        }
        for(int i=0; i<n; i++)
        {
            int mi=INT_MAX;
            for(int j=0;j<n;j++){
                if(find_representative(V[i])==find_representative(V[j])&&color[V[j]]==0){
                    mi=min(mi,V[j]);
                }
            }
            V2.PB(mi);
            color[mi]=1;
        }
        for(int i=0; i<n; i++)
        {
            printf("%d ",V2[i]);
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


