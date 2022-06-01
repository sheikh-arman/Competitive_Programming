
/*
  Sk arman Hossain
  University of Barisal

 Problem name : lightoj-1238 - Power Puff Girls
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
char V[510][510];
int cnt[510][510],m,n;
void CLEAR()
{
    memset(cnt,0,sizeof(cnt));
}
void bfs(int l,int r)
{
    queue<pair<int,int> >q;
    cnt[l][r]=0;
    q.push({l,r});
    while(!q.empty())
    {
        pair<int,int>temp;
        temp=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int x=temp.first+dx[i],y=temp.second+dy[i];
            if(x>=0&&y>=0&&x<m&&y<n)
            {
                //printf("%c\n",V[x][y]);
                char ch=V[x][y];
                if(cnt[x][y]==0&&ch!='m'&&ch!='#')
                {
                    char ch=V[x][y];
                    //if(ch=='.')
                    //{
                        cnt[x][y]=cnt[temp.first][temp.second]+1;
                        q.push({x,y});

                   //}
//                    else if(ch=='a'||ch=='b'||ch=='c')
//                    {
//                        ct++;
//                        return cnt[temp.first][temp.second]+1;
//                    }
                }
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
        int d,x,y,ax,bx,cx,ay,by,cy,ans;
        string s;
        sff(m,n);
        //sf(d);
        for(int i=0; i<m; i++)
        {
            cin>>s;
            for(int j=0; j<n; j++)
            {
                V[i][j]=s[j];
                if(s[j]=='h')
                {
                    x=i;
                    y=j;
                }
                else if(s[j]=='a'){
                    ax=i;ay=j;
                }
                else if(s[j]=='b'){
                    bx=i;by=j;
                }
                else if(s[j]=='c'){
                    cx=i;cy=j;
                }
            }
        }
        bfs(x,y);
        ans=max(cnt[ax][ay],max(cnt[bx][by],cnt[cx][cy]));
        printf("Case %d: %d\n",test,ans);


        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

