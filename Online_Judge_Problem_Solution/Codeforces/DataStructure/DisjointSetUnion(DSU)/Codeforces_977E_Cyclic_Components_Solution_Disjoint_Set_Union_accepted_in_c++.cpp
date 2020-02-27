
/*
    Sk arman Hossain
    University of Barisal

    Problem name : 977E-Cyclic Components
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
vector<PR>V;
vector<int>edge[200020];
int rep[200020];
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
        int n,e,ans=0;
        sf(n);
        sf(e);
        initial(n);
        for(int i=0; i<e; i++)
        {
            int a,b;
            sff(a,b);
            edge[a].PB(b);
            edge[b].PB(a);
            joint_node(a,b);
        }
        for(int i=1; i<=n; i++)
        {
            V.PB({find_representative(i),i});
        }
        VST(V);
//        for(int i=0; i<n; i++)
//        {
//            cout<<V[i].first<<" "<<V[i].second<<endl;
//        }
        int i=0,j=1;
        while(j<n)
        {
            if(V[j].first!=V[i].first)
            {
                i=j;
                j++;
            }
            else
            {
                int cnt=0;
                if(edge[V[i].second].size()==2)
                {
                    cnt++;
                }
                while(V[j].first==V[i].first&&j<n)
                {
                   // printf("%d %d %d in\n",cnt,V[j].second,edge[V[j].second].size());
                    if(edge[V[j].second].size()==2)
                    {
                        cnt++;
                    }
                    j++;
                }
               // printf("%d %d %d\n",j-i,cnt,V[i].second);
                if(j-i>2&&(cnt==j-i))
                {
                    ans++;
                }
                i=j;
                j++;
            }

        }
        printf("%d\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


