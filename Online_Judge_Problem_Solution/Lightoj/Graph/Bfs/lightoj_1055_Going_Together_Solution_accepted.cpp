/*
  Sk arman Hossain
  University of Barisal

 Problem name : 1238 - Power Puff Girls
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

class nod
{
public:
    int x1,y1,x2,y2,x3,y3;

};
bool operator<(const nod& t1, const nod& t2)
{
    return (t1.x1 < t2.x1||t1.y1<t2.y1);
}
vector<pair<int,int> >V;
vector<int>V2;
//int x1,y1,x2,y2,x3,y3;
char mat[11][11];
int color1[11][11],color2[11][11],color3[11][11],n;
int dist(nod temp){
    PR a,b,c;
    a.first=temp.x1;
    a.second=temp.y1;
    b.first=temp.x2;
    b.second=temp.y2;
    c.first=temp.x3;
    c.second=temp.y3;
    do{
        if (a == V[0] && b == V[1] && c == V[2]) return 1;
    }
    while (next_permutation(V.begin(), V.end()));
    return 0;
}
int bfs(nod node)
{
    int cnt=0;
     //printf("%d %d %d %d %d %d\n",node.x1,node.y1,node.x2,node.y2,node.x3,node.y3);
    queue<nod>q;
    map <pair<pair<PR,PR>, PR>, int> step;
    pair <pair<PR,PR>, PR> u, v;
    PR a,b,c,A,B,C;
    a=MP(node.x1,node.y1);
    b=MP(node.x2,node.y2);
    c=MP(node.x3,node.y3);
    u=MP(MP(a,b),c);

    step[u]=0;
    q.push(node);
    while(!q.empty())
    {
        node=q.front();
        A=MP(node.x1,node.y1);
        B=MP(node.x2,node.y2);
        C=MP(node.x3,node.y3);
        u=MP(MP(A,B),C);
        q.pop();
         if(dist(node))
            {
                return step[u];
            }
        for(int i=0; i<4; i++)
        {
            int nx1=node.x1+dx[i];
            int ny1=node.y1+dy[i];

            int nx2=node.x2+dx[i];
            int ny2=node.y2+dy[i];

            int nx3=node.x3+dx[i];
            int ny3=node.y3+dy[i];

            nod tmpnode=node;
            if(nx1>=0&&ny1<n&&nx1<n&&ny1>=0)
            {
                if(mat[nx1][ny1]!='#')
                {
                    tmpnode.x1=nx1;
                    tmpnode.y1=ny1;
                }
            }
            if(nx2>=0&&ny2<n&&nx2<n&&ny2>=0)
            {
                if(mat[nx2][ny2]!='#')
                {
                    tmpnode.x2=nx2;
                    tmpnode.y2=ny2;
                }
            }
            if(nx3>=0&&ny3<n&&nx3<n&&ny3>=0)
            {
                if(mat[nx3][ny3]!='#')
                {
                    tmpnode.x3=nx3;
                    tmpnode.y3=ny3;
                }
            }
            a=MP(tmpnode.x1,tmpnode.y1);
            b=MP(tmpnode.x2,tmpnode.y2);
            c=MP(tmpnode.x3,tmpnode.y3);
             if (a == b && b == c) {a = A; b = B; c = C;}
            if (a == b) {a = A; b = B;}
            if (a == c) {a = A; c = C;}
            if (c == b) {c = C; b = B;}
            v=MP(MP(a,b),c);
            tmpnode.x1=a.first;
            tmpnode.y1=a.second;
            tmpnode.x2=b.first;
            tmpnode.y2=b.second;
            tmpnode.x3=c.first;
            tmpnode.y3=c.second;
            //printf("%d %d %d %d %d %d %d\n",step.count(v),tmpnode.x1,tmpnode.y1,tmpnode.x2,tmpnode.y2,tmpnode.x3,tmpnode.y3);

            if (step.count(v)==0) {
                step[v] = step[u] + 1;
                q.push (tmpnode);
               // printf("%d %d %d %d %d %d\n",tmpnode.x1,tmpnode.y1,tmpnode.x2,tmpnode.y2,tmpnode.x3,tmpnode.y3);
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
        V.clear();
        nod node;
        sf(n);
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            int cnt=0;
            for(int j=0; j<n; j++)
            {
                mat[i][j]=s[j];
                if(s[j]=='A')
                {
                    node.x1=i;
                    node.y1=j;
                }
                else if(s[j]=='B')
                {
                    node.x2=i;
                    node.y2=j;
                }
                else if(s[j]=='C')
                {
                    node.x3=i;
                    node.y3=j;
                }
                 else if(s[j]=='X')
                {
                    V.PB({i,j});
                }
            }
        }
        int ck=bfs(node);
        if(ck!=-1)
        {
            printf("Case %d: %d\n",test,ck);
        }
        else
        {
            printf("Case %d: trapped\n",test);
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
