
/*
    Sk arman Hossain
    University of Barisal

    Problem name :
    Algorithm :
 */

#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define PR pair<int,int>
#define sf1(n) scanf("%d", &n)
#define sf2(n, m) scanf("%d %d",&n,&m)
#define sf3(n, m,k ) scanf("%d %d %d",&n,&m,&k)
#define sfl1(n) scanf("%lld", &n)
#define sfl2(n, m) scanf("%lld %lld",&n,&m)
#define sfl3(n, m,k ) scanf("%lld %lld %lld",&n,&m,&k)
#define pfn(n) printf("%d\n",n)
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES printf("YES\n")
#define NO printf("NO\n")
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mem(ar,a) memset(ar,a,sizeof(ar))
#define mod 1000000007
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
//#include<tuple>
typedef unsigned long long int ull;
using namespace std;
int rep[100010];
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
    if(v==nodey)
        rep[v]=u;
    //printf("%d %d \n",v,u);
}
int main()
{
    freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    int t;
    sf1(t);
    while(t--)
    {
        int n,e;
        scanf("%d%d",&n,&e);
        initial(n);
        for(int i=0; i<e; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            joint_node(a,b);
        }
        set<int>s;
        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            int u=find_representative(i);
            //printf("%d %d\n",i,u);
            s.insert(u);
        }
        printf("%d\n",s.size());
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


