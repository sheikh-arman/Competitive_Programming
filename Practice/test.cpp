#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300;
const ll inf=1e18;
ll a[N][N],h,w;
map<pair<ll,ll>,ll>mp,mp2,mp3_for_loop_ckeck;
//vector<pair<ll,ll>>dist;
ll dr[4]= {1,-1,0,0};
ll dr2[4]= {0,0,1,-1};
void dijkstra(ll r2,ll c2)
{
    mp2[ {r2,c2}]=0;
    set<pair<ll,pair<ll,ll>>>s;
    s.insert({0,{r2,c2}});
    while(!s.empty())
    {
        auto x=*(s.begin());
        s.erase(x);
        ll r=x.second.first,c=x.second.second;
        for(int i=0; i<4; i++)
        {
            if(r+dr[i]>=0 && r+dr[i]<h && c+dr2[i]>=0 && c+dr2[i]<w)
            {
                if(mp2[ {r+dr[i],c+dr2[i]}]>mp2[ {r,c}]+a[r+dr[i]][c+dr2[i]])
                {
                    //s.erase({mp2[{r+dr[i],c+dr2[i]}],{r+dr[i],c+dr2[i]}});
                    mp2[ {r+dr[i],c+dr2[i]}]=mp2[ {r,c}]+a[r+dr[i]][c+dr2[i]];
                    s.insert({mp2[{r+dr[i],c+dr2[i]}],{r+dr[i],c+dr2[i]}});
                }
            }
        }
    }
}
int main()
{
    freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll r,c,r2,c2,i,j,s=0,s2=0,z=0,crc=0;
    cin>>h>>w;
    cin>>r>>c>>r2>>c2;
    r--;
    c--;
    r2--;
    c2--;
    string str[h];
    for(i=0; i<h; i++)
    {
        for(j=0; j<w; j++)
        {
            cin>>a[i][j];
            mp2[ {i,j}]=inf;
        }
    }
    for(i=0; i<h; i++) cin>>str[i];
    dijkstra(r,c);
    z=inf;
    s=0;
    mp[ {r2,c2}]=0;
    ll loop_siz=-1;
    mp3_for_loop_ckeck[ {r2,c2}]++;
    while(1)
    {
        ll x,y;
        if(str[r2][c2]=='U') x=-1,y=0;
        else if(str[r2][c2]=='D') x=1,y=0;
        else if(str[r2][c2]=='L') x=0,y=-1;
        else x=0,y=1;

        if(x+r2>=0 && x+r2<h && y+c2>=0 && y+c2<w)
        {
            r2+=x;
            c2+=y;
            if(loop_siz!=-1)
            {
                ll tm=mp2[ {r2,c2}]-mp[ {r2,c2}];
                if(tm<=0)
                {
                    z=min(z,mp[ {r2,c2}]);
                }
                else
                {
                    ll cn=(tm+(loop_siz-1))/loop_siz;
                    z=min(z,(cn*loop_siz)+mp[ {r2,c2} ]);
                }
            }
            s++;
            if(mp3_for_loop_ckeck.count({r2,c2})&&loop_siz==-1)
            {
                loop_siz=s-(mp[ {r2,c2} ]);
            }
            if(mp3_for_loop_ckeck[ {r2,c2} ]>2)
            {
                break;
            }
            mp3_for_loop_ckeck[ {r2,c2}]++;
            mp[ {r2,c2}]=s;
            if(mp[ {r2,c2}]>=mp2[ {r2,c2}])
            {
                z=min(z,mp[ {r2,c2} ]);
            }
        }
        else break;
    }
    if(z==inf) cout<<"-1\n";
    else cout<<z<<"\n";
    return 0;
}
