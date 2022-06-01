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
vector<int>V,V2,V3,edge[50010],ans;
int path[50010],ma;
bool color[50010];
vector<ll> :: iterator it1,it2;
void CLEAR(){
    V.clear();
    ans.clear();
    memset(path,-1,sizeof(path));
    memset(color,false,sizeof(color));
    ma=0;
}
void bfs(int start){
    queue<int>q;
    q.push(start);
    color[start]=true;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        int l=edge[tmp].size();
        for(int i=0;i<l;i++){
            int x=edge[tmp][i];
            if(color[x]==false){
                color[x]=true;
                if(path[x]!=-1){
                    if(path[x]>tmp){
                        path[x]=tmp;
                    }
                }
                else{
                    path[x]=tmp;
                }
                q.push(x);
            }
        }
    }
}
int main()
{
    ///freopen("1input.txt","r",stdin);
    int tcase=1;
    sf(tcase);
    for(int test=1;test<=tcase;test++)
    {
        CLEAR();
        int n;
        sf(n);
        for(int i=0;i<n;i++){
            int a;
            sf(a);
            V.PB(a);
            ma=max(a,ma);
        }
        for(int i=1;i<n;i++){
            edge[V[i-1]].PB(V[i]);
            edge[V[i]].PB(V[i-1]);
        }
        for(int i=0;i<=ma;i++){
            VST(edge[i]);
        }
        bfs(V[0]);
        int x=V[n-1];
        ans.PB(x);
        while(path[x]!=-1){
            if(path[x]!=-1){
                ans.PB(path[x]);
                x=path[x];
            }
        }

        reverse(ans.begin(),ans.end());
        int l=ans.size();
        printf("Case %d:\n",test);
        for(int i=0;i<l;i++){
            printf("%d",ans[i]);
            if(i<l-1){
                printf(" ");
            }
        }
        printf("\n");
        for(int i=0;i<=ma;i++){
            edge[i].clear();
        }

       // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
