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
char V[510][510];
vector<int> V2;
int cnt[510][510],m,n,color[510][510],ans;
void CLEAR()
{
    memset(cnt,-1,sizeof(cnt));
    memset(color,0,sizeof(color));
    //V2.clear();
}
void dfs(int l,int r)
{
    color[l][r]=1;
    for(int i=0; i<4; i++)
    {
        int x=l+dx[i],y=r+dy[i];
        if(x>=0&&y>=0&&x<m&&y<n)
        {
            //printf("%c\n",V[x][y]);
            if(color[x][y]==0)
            {
                char ch=V[x][y];
                if(ch=='.')
                {
                    color[x][y]=1;
                    dfs(x,y);
                }
                else if(ch=='C')
                {
                    color[x][y]=1;
                    ans++;
                    dfs(x,y);
                }
            }
        }
    }
}
void dfs2(int l,int r,int value)
{
    //color[l][r]=1;
    cnt[l][r]=value;
    for(int i=0; i<4; i++)
    {
        int x=l+dx[i],y=r+dy[i];
        if(x>=0&&y>=0&&x<m&&y<n)
        {
            char ch=V[x][y];

            //printf("%d %d %d\n",x,y,value);
            if(cnt[x][y]==-1&&(ch=='.'||ch=='C'))
            {
                cnt[x][y]=value;
                dfs2(x,y,value);
            }
        }
    }
}
int main()
{
    ///freopen("input.txt","r",stdin);
    int tcase=1;
    sf(tcase);
    for(int test=1; test<=tcase; test++)
    {
        CLEAR();
        int d;
        string s;
        sff(m,n);
        sf(d);
        for(int i=0; i<m; i++)
        {
            cin>>s;
            for(int j=0; j<n; j++)
            {
                V[i][j]=s[j];
            }
        }
        printf("Case %d:\n",test);
        for(int i=0; i<d; i++)
        {
           // memset(color,0,sizeof(color));
            ans=0;
            int l,r;
            sff(l,r);
            if(cnt[l-1][r-1]==-1)
            {
                dfs(l-1,r-1);
                //V2.PB(ans);
                dfs2(l-1,r-1,ans);
            }
            else
            {
                ans=cnt[l-1][r-1];
                //printf("%d ",ans);
            }
            printf("%d\n",ans);
        }

        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
