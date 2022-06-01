
/*
    Sk arman Hossain
    University of Barisal

    Problem name :Disjoint set union(dsu)
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
#define first ff
#define second ss
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
int rep[10000];
void initial(int n){
    for(int i=1;i<=n;i++){
        rep[i]=i;
    }
}
int find_representative(int node){
    if(rep[node]==node){
        return node;
    }
    else{
        rep[node]=find_representative(rep[node]);
        return rep[node];
    }
}
void union_node(int nodex,int nodey){
    int u=find_representative(nodex);
    int v=find_representative(nodey);
    if(u!=v){
        rep[u]=v;
    }
}
int main()
{
    ///freopen("1input.txt","r",stdin);
    int tcase=1;
    //sf(tcase);
    for(int test=1;test<=tcase;test++)
    {
        int n,e;
        printf("Input number of node:");
        sf(n);
        printf("Input number of edge:");
        sf(e);
        initial(n);
        printf("Input edge:\n");
        for(int i=0;i<e;i++){
            int a,b;
            sff(a,b);
            union_node(a,b);
        }
        int query;
        printf("Input number of query:");
        sf(query);
        printf("Input query:\n");
        for(int i=0;i<query;i++){
            int a,b;
            sff(a,b);
            int u=find_representative(a);
            int v=find_representative(b);
            if(rep[u]==rep[v]){
                printf("%d %d are friend\n",a,b);
            }
            else{
                printf("%d %d are not friend\n",a,b);
            }
        }
       // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


