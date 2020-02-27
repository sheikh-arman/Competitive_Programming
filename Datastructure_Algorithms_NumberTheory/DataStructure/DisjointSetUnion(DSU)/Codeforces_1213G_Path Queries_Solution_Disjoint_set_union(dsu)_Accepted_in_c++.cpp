
/*
    Sk arman Hossain
    University of Barisal

    Problem name : Path Queries
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
#define  ff first
#define  ss second
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
ll ans[200110];
ll cnt_node[200110];
int rep[200110];
vector<pair <PR,int> >V;
bool cmp(pair <PR,int>tm1,pair <PR,int> tm2)
{
    return(tm1.ss<tm2.ss);
}
void initial(int n)
{
    for(int i=1; i<=n; i++)
    {
        rep[i]=i;
        cnt_node[i]=1;
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
void joint_node(int nodex,int nodey,int len)
{
    int u=find_representative(nodex);
    int v=find_representative(nodey);
    if(u!=v)
    {
        ll tm1=cnt_node[u];
        tm1=(tm1*(tm1-1))/2;

        ll tm2=cnt_node[v];
        tm2=(tm2*(tm2-1))/2;

        rep[u]=v;

        cnt_node[v]+=cnt_node[u];
        ans[len]-=(tm1+tm2);

        ll tm=cnt_node[v];
        ans[len]+=(tm*(tm-1))/2;
    }
}
int main()
{
    ///freopen("1input.txt","r",stdin);
    int tcase=1;
    //sf(tcase);
    for(int test=1; test<=tcase; test++)
    {
        memset(ans,0,sizeof(ans));
        int n,e,q,ma_len=0;
        sff(n,q);
        e=n-1;
        initial(n);
        for(int i=0; i<e; i++)
        {
            int a,b,c;
            sff(a,b);
            sf(c);
            ma_len=max(c,ma_len);
            V.PB({{a,b},c});
        }
        ll last=0;
        if(e>0)
        {
            sort(V.begin(),V.end(),cmp);
            for(int i=0; i<e; i++)
            {
                int j=i+1;
                ans[V[i].ss]=last;
                joint_node(V[i].ff.ff,V[i].ff.ss,V[i].ss);
                last=ans[V[i].ss];
                while(j<e)
                {
                    if(V[i].ss==V[j].ss)
                    {
                        ans[V[j].ss]=last;
                        joint_node(V[j].ff.ff,V[j].ff.ss,V[j].ss);
                        last=ans[V[j].ss];
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }
                i=j-1;
            }
            for(int i=1;i<=ma_len;i++){
                if(ans[i]==0){
                    ans[i]=ans[i-1];
                }
            }
        }
        for(int i=0; i<q; i++)
        {
            int x;
            sf(x);
            x=min(x,ma_len);
            printf("%lld ",ans[x]);
        }
        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


