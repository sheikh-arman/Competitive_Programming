
/*
    Sk arman Hossain
    University of Barisal

    Problem name : Codeforces_764C_Timofey_and_a_tree
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
#define ff first
#define ss second
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<PR>V;
vector<int>edge[200010],V2;
int rep[200010];
int color[200010];
int color2[200010],nod;
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
        int n,e;
        sf(n);
        e=n-1;
        initial(n);
        for(int i=0; i<e; i++)
        {
            int a,b;
            sff(a,b);
            edge[a].PB(b);
            edge[b].PB(a);
            V.PB({a,b});
        }
        for(int i=1; i<=n; i++)
        {
            int a;
            sf(a);
            color[i]=a;
        }
        set<int>s;
        for(int i=0; i<e; i++)
        {
            if(color[V[i].first]==color[V[i].second])
            {
                joint_node(V[i].first,V[i].second);
            }
        }
        V.clear();
        for(int i=1; i<=n; i++)
        {
            V.PB({find_representative(i),i});
            s.insert(rep[i]);
        }
        VST(V);
        memset(color,0,sizeof(color));
        int siz=s.size(),ma=0;
        for(int i=0; i<n; i++)
        {
            int j=i+1,node;
            int l=edge[V[i].second].size();
            color[V[i].second]++;
            color2[V[i].second]++;
            V2.PB(V[i].second);
            if(color[V[i].second]>ma)
            {
                ma=color[V[i].second];
                nod=V[i].second;
            }
            for(int k=0; k<l; k++)
            {
                node=edge[V[i].second][k];
                color[node]++;
                color2[node]=1;
                V2.PB(node);
                if(color[node]>ma)
                {
                    ma=color[node];
                    nod=node;
                }
            }
            if(j<n)
            {
                while(j<n&&V[i].first==V[j].first)
                {


                    l=edge[V[j].second].size();
                    for(int k=0; k<l; k++)
                    {
                        node=edge[V[j].second][k];
                        if(color2[node]!=1)
                        {
                            color[node]++;
                            if(color[node]>ma)
                            {
                                ma=color[node];
                                nod=node;
                            }
                            color2[node]=1;
                            V2.PB(node);
                        }
                    }

                    j++;
                }
            }
            i=j-1;
            l=V2.size();
            for(int k=0; k<l; k++)
            {
                color2[V2[k]]=0;
            }
            V2.clear();
        }
        if(ma==siz)
        {
            printf("YES\n%d\n",nod);
        }
        else
        {
            printf("NO\n");
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
