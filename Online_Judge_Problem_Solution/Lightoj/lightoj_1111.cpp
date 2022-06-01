#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define mp pair<ll,ll>
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
#define pb push_back
#define pi 3.1415926536
#define vst(v) sort(v.begin(),v.end())
#define fori(n) for(int i=0;i<n;i++)
//void FastIO() {ios_base:: sync_with_stdio(false); cin.tie(0); cout.precision(20);}
int dx[]= {0,0,1,1};
int dy[]= {1,1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<int>v[10000],v2,v3;
vector<int> :: iterator it1,it2;
bool visit[2000];
int visit2[2000];
void dfs(int n)
{
    visit[n]=1;
    int l=v[n].size();
    for(int i=0; i<l; i++)
    {
        int x=v[n][i];
        if(visit[x]==0)
        {
            //s.insert(x);
            visit2[x]++;
            visit[x]=1;
            dfs(x);
        }
        visit[x]=1;
    }
}

int main()
{
    ///freopen("input.txt","r",stdin);
    int tcase,cnt=0;
    sf(tcase);
    while(tcase--)
    {
        v2.clear();
        for(int i=0;i<=1010;i++){
            v[i].clear();
        }
        memset(visit2,0,sizeof(visit2));
        int n,ans=0,a,u,v1,k,m;
        sff(k,n);sf(m);
        for(int i=0; i<k; i++)
        {
            sf(a);
            v2.pb(a);
        }
        for(int i=0;i<m;i++){
            sff(u,v1);
            v[u].pb(v1);
        }
        for(int i=0;i<k;i++){
                memset(visit,0,sizeof(visit));
                visit2[v2[i]]++;
            dfs(v2[i]);
        }
        for(int j=1;j<=n;j++){
                if(visit2[j]==k)
                    ans++;

            }

       printf("Case %d: %d\n",++cnt,ans);
    }

///*****************************  ALHAMDULILLAH  *****************************/
}
