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
char mat[210][210];
int x,y,cnt,label[210][210],ans,n,m;
int s_tx=-1,s_ty=-1,d_tx=0,d_ty=0;
int bfs1(int x1,int y1)
{
    queue< pair<int,int> >q;
    q.push({x1,y1});
    label[x1][y1]=0;
    while(!q.empty())
    {
        pair<int,int>temp;
        temp = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            x1=temp.first+dx[i];
            y1=temp.second+dy[i];
            if(x1>=0&&y1>=0&&x1<n&&y1<m)
            {
                if(label[x1][y1]==-1&&(mat[x1][y1]=='.'||mat[x1][y1]=='D'))
                {
                    if(mat[x1][y1]=='D')
                    {
                        label[x1][y1]=label[temp.first][temp.second]+1;
                        return label[x1][y1];
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
    return -1;
}
int bfs2(int x1,int y1)
{
    queue< pair<int,int> >q;
    q.push({x1,y1});
    label[x1][y1]=0;
    while(!q.empty())
    {
        pair<int,int>temp;
        temp = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            x1=temp.first+dx[i];
            y1=temp.second+dy[i];
            if(x1>=0&&y1>=0&&x1<n&&y1<m)
            {
                if(label[x1][y1]==-1&&(mat[x1][y1]=='.'||mat[x1][y1]=='*'))
                {
                    //printf("%d %d\n",x1,y1);
                    if(mat[x1][y1]=='*')
                    {
                        //printf("%d %d iner\n",x1,y1);
                        s_tx=x1;
                        s_ty=y1;
                        label[x1][y1]=label[temp.first][temp.second]+1;
                        return label[x1][y1];
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
    return -1;
}
int bfs3(int x1,int y1,int lbl)
{
    queue< pair<int,int> >q;
    q.push({x1,y1});
    label[x1][y1]=0;
    int frequency=0;
    while(!q.empty())
    {
        pair<int,int>temp;
        temp = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            x1=temp.first+dx[i];
            y1=temp.second+dy[i];
            if(x1>=0&&y1>=0&&x1<n&&y1<m)
            {
                if(label[x1][y1]==-1&&(mat[x1][y1]=='.'||mat[x1][y1]=='*'))
                {
                    //printf("%d %d\n",x1,y1);
                    if(mat[x1][y1]=='*')
                    {
                        //printf("%d %d iner\n",x1,y1);
                        s_tx=x1;
                        s_ty=y1;
                        label[x1][y1]=label[temp.first][temp.second]+1;
                        if(label[x1][y1]==lbl)
                            frequency++;
                        //return label[x1][y1];
                    }
                    else
                    {
                        label[x1][y1]=label[temp.first][temp.second]+1;
                        if(label[x1][y1]<=lbl)
                            q.push({x1,y1});
                    }
                }
            }
        }

    }
    return frequency;
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
        int startx,starty,distx,disty;
        sff(n,m);
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            for(int j=0; j<m; j++)
            {
                mat[i][j]=s[j];
                if(mat[i][j]=='P')
                {
                    startx=i;
                    starty=j;
                }
                if(mat[i][j]=='D')
                {
                    distx=i;
                    disty=j;
                }
                if(s[j]=='*')
                    cnt++;
            }
        }
        if(cnt==1)
        {
            memset(label,-1,sizeof(label));
            ans=bfs1(startx,starty);
            if(ans==-1)
            {
                printf("Case %d: impossible\n",test);
            }
            else
            {
                printf("Case %d: %d\n",test,ans);
            }
        }
        else
        {
            memset(label,-1,sizeof(label));
            ans=bfs1(startx,starty);
            if(ans==-1)
            {
                ans=INT_MAX;
            }
            int sub1,sub2;
            s_tx=-1;
            s_ty=-1;
            memset(label,-1,sizeof(label));
            sub1=bfs2(startx,starty);
            d_tx=s_tx;
            d_ty=s_ty;
            s_ty=-1;
            s_tx=-1;
            memset(label,-1,sizeof(label));
            sub2=bfs2(distx,disty);
            int ans2=0;
            if(sub1==-1||sub2==-1)
            {
                ans2=INT_MAX;
            }
            else
            {
                ans2=sub1+sub2+1;
                if(s_tx==d_tx&&s_ty==d_ty){
                        memset(label,-1,sizeof(label));
                        int fre=bfs3(startx,starty,sub1);
                         memset(label,-1,sizeof(label));
                        int fre2=bfs3(distx,disty,sub1);
                        if(fre<=1&&fre2<=1){
                            ans2+=1;
                    }
                }
            }
            ans=min(ans,ans2);
            if(ans==INT_MAX)
            {
                printf("Case %d: impossible\n",test,ans);
            }
            else
            {
                printf("Case %d: %d\n",test,ans);
            }
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

