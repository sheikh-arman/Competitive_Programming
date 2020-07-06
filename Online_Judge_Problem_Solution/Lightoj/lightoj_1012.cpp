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
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
#define WHITE 2
#define GRAY 3
#define BLACK 4
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
int nod[100][100];
vector<pair<int,int> >v2;
//vector<pair<int,int> > :: iterator it1,it2;
vector<int> :: iterator it1,it2;
int dis[100],ans=1,n,m;
int node,edge;
void bfs(int a,int b){
    nod[a][b]=0;
    ans=1;
    queue<pair<int,int>>q;
    q.push({a,b});
    while(!q.empty()){
        pair<int,int> x;
        x=q.front();
        q.pop();
        //color[x]=GRAY;

        for(int i=0;i<4;i++){
                int x1,y1;
        x1=x.first+dx[i];
        y1=x.second+dy[i];

            if(nod[x1][y1]==1&&x1>=0&&y1>=0&&x1<m&&y1<n){
                ans++;//printf("(%d , %d) %d %d\n",x1,y1,ans,nod[x1][y1]);
                nod[x1][y1]=2;
                q.push({x1,y1});
            }
//            else if(nod[x1][y1]!=2){
//                printf("(%d , %d) %d %d\n",x1,y1,ans,nod[x1][y1]);
//            }
        }
    }
}
int main (){
    ///freopen("input.txt","r",stdin);
    ll tcase=1;
    int cnt=0;
    sf(tcase);
    while(tcase--)
    {
        int e,a,b,ck=0;
        char ch;
        string s;
        sff(n,m);
        for(int i=0;i<m;i++){
                cin>>s;
                for(int j=0;j<n;j++){
                    //scanf("%c",&ch);
                    if(s[j]=='.')
                     nod[i][j]=1;
                     else if(s[j]=='#')
                        nod[i][j]=0;
                     else {
                        a=i;b=j;
                     }
                }
        }
        bfs(a,b);
        printf("Case %d: %d\n",++cnt,ans);
    }
    return 0;
}
