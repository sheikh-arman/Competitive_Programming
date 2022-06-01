
/*
  Sk arman Hossain
  University of Barisal

 Problem name : lightoj-1175 - Jane and the Frost Giants
 Algorithm : BFS
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
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<PR>V;
char maze[210][210];
int n,m,label[210][210],jlabel[210][210];
bool color[210][211];
void CLEAR()
{
    memset(label,-1,sizeof(label));
    memset(jlabel,-1,sizeof(jlabel));
    memset(color,false,sizeof(color));
    V.clear();
}
void fire_bfs(int x,int y)
{
    queue<PR>q;
    q.push({x,y});
    label[x][y]=0;
    color[x][y]=true;
    while(!q.empty())
    {
        PR tmp;
        tmp=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            x=tmp.first+dx[i];
            y=tmp.second+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m)
            {
                if(color[x][y]==false&&maze[x][y]!='#')
                {
                    color[x][y]=true;
                    if(label[x][y]==-1)
                    {
                        label[x][y]=label[tmp.first][tmp.second]+1;
                        q.push({x,y});
                    }
                    else
                    {
                        if(label[x][y]>label[tmp.first][tmp.second]+1)
                        {
                            label[x][y]=label[tmp.first][tmp.second]+1;
                            q.push({x,y});
                        }
                    }


                }
            }
        }
    }
}
int j_bfs(int x,int y)
{
    queue<PR>q;
    q.push({x,y});
    jlabel[x][y]=0;
    if(x==0||y==0||x+1==n||y+1==m)
    {
        return 0;
    }
    while(!q.empty())
    {
        PR tmp;
        tmp=q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            x=tmp.first+dx[i];
            y=tmp.second+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m)
            {
                if((x==0||y==0||x+1==n||y+1==m)&&jlabel[tmp.first][tmp.second]+1<label[x][y])
                {
                    return jlabel[tmp.first][tmp.second]+1;
                }
                if(jlabel[x][y]==-1&&maze[x][y]!='#'&&jlabel[tmp.first][tmp.second]+1<label[x][y])
                {
                    jlabel[x][y]=jlabel[tmp.first][tmp.second]+1;
                    q.push({x,y});
                }
            }
        }
    }
    return -1;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    int tcase=1;
    sf(tcase);
    for(int test=1; test<=tcase; test++)
    {
        CLEAR();
        int x,y,fx,fy;
        sff(n,m);
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            for(int j=0; j<m; j++)
            {
                maze[i][j]=s[j];
                if(s[j]=='J')
                {
                    x=i;
                    y=j;
                }
                if(s[j]=='F')
                {
                    V.PB({i,j});
                }
            }
        }
        int l=V.size();
        for(int i=0; i<l; i++)
        {
            memset(color,0,sizeof(color));
            fire_bfs(V[i].first,V[i].second);
        }
        int ans=j_bfs(x,y);
        if(ans==-1)
        {
            printf("Case %d: IMPOSSIBLE\n",test);
        }
        else
        {
            printf("Case %d: %d\n",test,ans+1);
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

