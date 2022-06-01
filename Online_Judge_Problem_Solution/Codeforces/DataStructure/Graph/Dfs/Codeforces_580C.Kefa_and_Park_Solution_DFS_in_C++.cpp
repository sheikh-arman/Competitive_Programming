/*
    Author : SK Arman Hossain
    University of Barishal
    Problem: Codeforces_580C.Kefa_and_Park
    Solution: DFS
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
#define pb push_back
#define pi 3.1415926536
#define vst(v) sort(v.begin(),v.end())
#define fori(n) for(int i=0;i<n;i++)
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
int color[200000];
int cost[200000];
int ck[200000];
int cat[200000];
int m;
vector<int>v[200000];
void dfs(int n){
    color[n]=1;
    int s=v[n].size();
    for(int i=0;i<s;i++){
        int x=v[n][i];
        if(color[x]!=1){
            if(cat[x]==1&&(cat[n]==1||cat[n]==0)){
                cost[x]=cost[n]+1;
                if(cost[x]>m){
                    ck[x]=-1;
                }
            }
            if(ck[n]==-1){
                ck[x]=-1;
            }
            dfs(x);
        }
    }
}
int main()
{
    ///freopen("input.txt","r",stdin);
    ///while(1){
    int n,a,x,y,cnt=0;
    sff(n,m);
    for(int i=1;i<=n;i++){
            sf(a);
        cat[i]=a;
    }
    if(cat[1]==1)
        cost[1]=1;
    for(int i=1;i<n;i++){
            sff(x,y);
            v[x].pb(y);
            v[y].pb(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        if(v[i].size()==1&&ck[i]!=-1&&i!=1){
            cnt++;
        }
        //printf("%d ",ck[i]);
    }
    printf("%d\n",cnt);
///*****************************  ALHAMDULILLAH  *****************************/
}
