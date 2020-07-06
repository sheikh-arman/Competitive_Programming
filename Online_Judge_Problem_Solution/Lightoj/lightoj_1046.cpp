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
int dx[]= {1,1,2,2,-1,-1,-2,-2};
int dy[]= {2,-2,1,-1,2,-2,1,-1};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
class pr{
public:
    int first,second;
};
pr V[12][12];
int V1[12][12];
int n,m;
bool color[12][12];
void CLEAR()
{
    memset(color,0,sizeof(color));
    memset(V1,0,sizeof(V1));
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            V[i][j].first=0;
            V[i][j].second=0;
        }
    }
}
void bfs(int x1,int y1,int rider)
{
    //printf("sfdyt\n");
    int cnt=0;
    queue<PR>q;
    q.push({x1,y1});
    V[x1][y1].first+=1;
    //V[x1][y1].second=0;
    color[x1][y1]=true;
    while(!q.empty())
    {
        PR tmp;
        tmp=q.front();
        q.pop();
        cnt=+1;
        for(int i=0; i<8; i++)
        {
            int x=tmp.first+dx[i];
            int y=tmp.second+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m)
            {
                if(color[x][y]==false)
                {
                    color[x][y]=true;
                    V[x][y].first+=1;
                    V1[x][y]=V1[tmp.first][tmp.second]+1;
                    q.push({x,y});
                }
            }
        }
    }
     for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                V[i][j].second+=((V1[i][j]/rider)+(V1[i][j]%rider!=0));
               // printf("%d ",V1[i][j]);
            }
           // nl;
        }
        //printf("en\n");
}
int main()
{
   // freopen("1input.txt","r",stdin);
    int tcase=1;
    sf(tcase);
    for(int test=1; test<=tcase; test++)
    {
        CLEAR();
        int cn=0;;
        sff(n,m);
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            for(int j=0; j<m; j++)
            {
                if(s[j]!='.')
                {
                    cn++;
                    memset(color,0,sizeof(color));
                    memset(V1,0,sizeof(V1));
                    bfs(i,j,(s[j]-'0'));
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(V[i][j].first==cn)
                {
                    ans=min(ans,V[i][j].second);
                }
              //  printf("%d ",V[i][j].second,i,j,V[i][j].first,ans);
            }
          //  nl;
        }
        if(ans==INT_MAX)
        {
            printf("Case %d: %d\n",test,-1);
        }
        else
        {
            printf("Case %d: %d\n",test,ans);
        }
        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
