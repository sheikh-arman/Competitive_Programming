/*
  Sk arman Hossain
  University of Barisal

 Problem name : 1039 - A toy company
 Algorithm : DFS
*/

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
#define yes printf("YES\n")
#define no printf("NO\n")
#define pb push_back
#define pi 3.1415926536
#define vst(v) sort(v.begin(),v.end())
#define fori(n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<int>v[100014];
int visit[100012],cnt1=0,cnt2=0;
void dfs(int node){
    int l=v[node].size();
    for(int i=0;i<l;i++){
        int x=v[node][i];
        if(visit[x]==0){
                if(visit[node]==1){
                    cnt1++;
                    visit[x]=2;
                }
                else{
                    visit[x]=1;cnt2++;
                }
            dfs(x);
        }
    }
}
int main()
{
    ///freopen("input.txt","r",stdin);
    int tcase=1,cnt=0;
    sf(tcase);
    while(tcase--)
    {
        for(int i=0;i<=20000;i++){
            v[i].clear();
        }
        memset(visit,0,sizeof(visit));
        int n,ans=0,a,ans2,tmp,u,v1,ma=0;
        sf(n);
        cnt1=0;cnt2=0;
        for(int i=0;i<n;i++){
            sff(u,v1);
            v[u].pb(v1);
            v[v1].pb(u);
        }

        for(int i=1;i<=20000;i++){
                cnt1=0;cnt2=0;
                if(visit[i]==0&&v[i].size()>0){
                    visit[i]=1;cnt2++;dfs(i);
                }
                ans+=max(cnt1,cnt2);
        }
        printf("Case %d: %d\n",++cnt,ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
