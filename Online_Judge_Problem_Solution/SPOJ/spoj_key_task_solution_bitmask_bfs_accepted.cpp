/*
    Sk arman Hossain
    University of Barisal
    Problem name :
    Algorithm :
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
#define ff first
#define ss second
#define MP make_pair
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
string s[110];
int row,col;
int bitmask[110][110][16];
//map <pair<pair<PR,PR>,PR>, int> step;
int bfs(int x1,int y1)
{
    queue <pair<PR,int> > q;
    bitmask[x1][y1][0]=0;
    //printf("%d \n",bitmask[x1][y1][5]);
    q.push({{x1,y1},0});
    while(!q.empty())
    {
        pair<PR,int>u;
        int mask;
        u=q.front();
        PR tm=u.ff;
        mask=u.ss;
        x1=tm.ff;
        y1=tm.ss;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int tmx=x1+dx[i];
            int tmy=y1+dy[i];
            if(tmy>=0&&tmy<col&&tmx>=0&&tmx<row)
            {
                //printf("%c %d %d %d\n",s[tmx][tmy],bitmask[tmx][tmy][5],tmx,tmy);
                if(s[tmx][tmy]!='#')
                {
                    if(bitmask[tmx][tmy][mask]==-1)
                    {
                        int tm_mask=mask;
                        if(s[tmx][tmy]=='X')
                        {
                            return bitmask[x1][y1][mask]+1;;
                        }
                        else if(s[tmx][tmy]=='.')
                        {
                            bitmask[tmx][tmy][tm_mask]=bitmask[x1][y1][mask]+1;
                            q.push({{tmx,tmy},tm_mask});
                        }
                        else if(s[tmx][tmy]=='B'&&(tm_mask&(1<<0)))
                        {
                            bitmask[tmx][tmy][tm_mask]=bitmask[x1][y1][mask]+1;
                            q.push({{tmx,tmy},tm_mask});
                        }
                        else if(s[tmx][tmy]=='R'&&(tm_mask&(1<<1)))
                        {
                            bitmask[tmx][tmy][tm_mask]=bitmask[x1][y1][mask]+1;
                            q.push({{tmx,tmy},tm_mask});
                        }
                        else if(s[tmx][tmy]=='Y'&&(tm_mask&(1<<2)))
                        {
                            bitmask[tmx][tmy][tm_mask]=bitmask[x1][y1][mask]+1;
                            q.push({{tmx,tmy},tm_mask});
                        }
                        else if(s[tmx][tmy]=='G'&&(tm_mask&(1<<3)))
                        {
                           bitmask[tmx][tmy][tm_mask]=bitmask[x1][y1][mask]+1;
                            q.push({{tmx,tmy},tm_mask});
                        }
                        else if(s[tmx][tmy]=='b')
                        {
                            tm_mask=tm_mask|(1<<0);
                             bitmask[tmx][tmy][tm_mask]=bitmask[x1][y1][mask]+1;
                             //bitmask[tmx][tmy][tm_mask]=bitmask[x1][y1][mask];
                            q.push({{tmx,tmy},tm_mask});
                        }
                        else if(s[tmx][tmy]=='r')
                        {
                            tm_mask=tm_mask|(1<<1);
                             bitmask[tmx][tmy][tm_mask]=bitmask[x1][y1][mask]+1;
                            // bitmask[tmx][tmy][tm_mask]=bitmask[x1][y1][mask];
                            q.push({{tmx,tmy},tm_mask});
                        }
                        else if(s[tmx][tmy]=='y')
                        {
                           tm_mask=tm_mask|(1<<2);
                             bitmask[tmx][tmy][tm_mask]=bitmask[x1][y1][mask]+1;
                             //bitmask[tmx][tmy][tm_mask]=bitmask[x1][y1][mask];
                            q.push({{tmx,tmy},tm_mask});
                        }
                        else if(s[tmx][tmy]=='g')
                        {
                            tm_mask=tm_mask|(1<<3);
                            bitmask[tmx][tmy][tm_mask]=bitmask[x1][y1][mask]+1;
                            //bitmask[tmx][tmy][tm_mask]=bitmask[x1][y1][mask];
                            q.push({{tmx,tmy},tm_mask});
                        }
                        else if(s[tmx][tmy]=='*')
                        {
                             bitmask[tmx][tmy][tm_mask]=bitmask[x1][y1][tm_mask]+1;
                            q.push({{tmx,tmy},tm_mask});
                        }

                        // printf("%c %d %d %d u\n",s[tmx][tmy],bitmask[tmx][tmy][5],tmx,tmy);
                    }
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
    //sf(tcase);
    while(scanf("%d%d",&row,&col)!=EOF)
    {
        memset(bitmask,-1,sizeof(bitmask));

        int x,y;
        if(row==0&&col==0)
        {
            return 0;
        }
        for(int i=0; i<row; i++)
        {
            cin>>s[i];
            for(int j=0; j<col; j++)
            {
                if(s[i][j]=='*')
                {
                    x=i;
                    y=j;
                }

            }
        }
        int ans=bfs(x,y);
        if(ans==-1)
        {
            printf("The poor student is trapped!\n");
        }
        else
        {
            printf("Escape possible in %d steps.\n",ans);
        }
        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
