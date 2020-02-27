
/*
    Sk arman Hossain
    University of Barisal

    Problem name :uva_p11503_Virtual Friends
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
int rep[100100],ans[100100];
void initial(int n)
{
    for(int i=0; i<=n; i++)
    {
        rep[i]=i;
        ans[i]=1;
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
void union_node(int nodex,int nodey)
{
    int u=find_representative(nodex);
    int v=find_representative(nodey);
    if(u!=v)
    {
        int temp=ans[find_representative(u)];
        rep[u]=v;
        ans[find_representative(v)]+=temp;
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    int tcase=1,n,d;
    sf(tcase);
    for(int test=1; test<=tcase; test++)
    {
        memset(rep,0,sizeof(rep));
        memset(ans,1,sizeof(rep));
        int n;
        sf(n);
        map<string,int>m;
        //map<int,int>ans;
        string s,s2;
        initial(n);
        int cnt=0;
        //while(getchar() != '\n');
        for(int i=0; i<n; i++)
        {
            cin>>s>>s2;
            int a,b;
            if(m.count(s)!=0)
                a=m[s];
            else
            {
                m[s]=cnt;
                a=cnt;
                cnt++;
            }
            if(m.count(s2)!=0)
                b=m[s2];
            else
            {
                m[s2]=cnt;
                b=cnt;
                cnt++;
            }
            union_node(a,b);
            int x=a,y=b;
            x=find_representative(a);
            printf("%d\n",ans[x]);
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}



