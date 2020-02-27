
/*
  Sk arman Hossain
  University of Barisal

 Problem name : lightoj-1141 - Number Transformation
 Algorithm : BFS
*/

#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define MP pair<ll,ll>
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
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<int>V[2010],V2,V3;
vector<ll> :: iterator it1,it2;
bool ckprime[2010];
int label[2010];
void CLEAR()
{
    memset(label,-1,sizeof(label));
}
int bfs(int node,int dis)
{
    queue<int>q;
    q.push(node);
    label[node]=0;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        int len=V[temp].size();
        for(int i=0; i<len; i++)
        {
            int x=V[temp][i]+temp;
            if(label[x]==-1&&x<=dis)
            {
                label[x]=label[temp]+1;
                q.push(x);
                if(dis==x)
                {
                    return label[x];
                }
            }
        }
    }
    return label[dis];
}
void prime()
{
    memset(ckprime,0,sizeof(ckprime));
    for(int i=2; i<=1000; i+=2)
    {
        V[i].PB(2);
        ckprime[i]=true;
    }
    for(int i=3; i<=1000; i+=2)
    {
        if(ckprime[i]==false)
        {
            for(int j=i+i; j<=1000; j+=i)
            {
                ckprime[j]=true;
                V[j].PB(i);
            }
        }
    }
}
int main()
{
    ///freopen("input.txt","r",stdin);
    int tcase=1;
    prime();
    sf(tcase);
    for(int test=1; test<=tcase; test++)
    {
        CLEAR();
        int n,tempn,t;
        sf(n);
        sf(t);
        ans=bfs(n,t);
        printf("Case %d: %d\n",test,ans);

    }
///*****************************  ALHAMDULILLAH  *****************************/
}

