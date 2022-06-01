/*
  Sk arman Hossain
  University of Barisal

 Problem name : 1094 - Farthest Nodes in a Tree
 Algorithm : DFS
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
char mat[20][20];
int x,y,cnt,label[20][20],ans,n;
void bfs(int x1,int y1,int target)
{
    char distan=target+'A';
    //printf("%c\n",distan);
    queue< pair<int,int> >q;
    q.push({x1,y1});
    label[x1][y1]=0;
    int ck=1;
    while(!q.empty()&&ck)
    {
        pair<int,int>temp;
        temp = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            x1=temp.first+dx[i];
            y1=temp.second+dy[i];
            if(x1>=0&&y1>=0&&x1<n&&y1<n)
            {
                if(label[x1][y1]==-1&&(mat[x1][y1]=='.'||mat[x1][y1]==distan))
                {
                    //printf("%d %d\n",x1,y1);
                    if(mat[x1][y1]==distan)
                    {
                        //printf("%d %d iner\n",x1,y1);
                        mat[x1][y1]='.';
                        ck=0;
                        label[x1][y1]=label[temp.first][temp.second]+1;
                        x=x1;
                        y=y1;
                        break;
                    }
                    else
                    {
                        label[x1][y1]=label[temp.first][temp.second]+1;
                        q.push({x1,y1});
                    }
                }
            }
        }

    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    int tcase=1;
    sf(tcase);
    for(int test=1; test<=tcase; test++)
    {
        cnt=0,ans=0;
        //int n;
        sf(n);
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            for(int j=0; j<n; j++)
            {
                mat[i][j]=s[j];
                if(mat[i][j]=='A')
                {
                    x=i;
                    y=j;
                }
                if(s[j]!='.'&&s[j]!='#')
                    cnt++;
            }
        }
        int ck1=1;
        mat[x][y]='.';
        for(int i=1; i<cnt&&ck1; i++)
        {
            memset(label,-1,sizeof(label));
            int xa=x,ya=y;
            bfs(xa,ya,i);
            if(xa==x&&ya==y)
            {
                ck1=0;
                break;

            }
            else
            {
                ans+=label[x][y];
            }
        }


        if(!ck1)
        {
            printf("Case %d: Impossible\n",test);
        }
        else
        {
            printf("Case %d: %d\n",test,ans);
        }

        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

