/*
    Sk arman Hossain
    University of Barisal

    Problem : spoj_CLEANRBT-Cleaning_Robot
    Solution : DP + BFS
 */
#include<bits/stdc++.h>
#define PB push_back
typedef int ll;
using namespace std;
ll dx[] = {0,0,1,-1};
ll dy[] = {1,-1,0,0};
ll n,m;
ll dp[12][(1<<11)+13],cnt;
string s[23];
ll ck_map[23][23];
ll color[23][23];
ll weight[13][13];
ll change(ll nn,ll pos)
{
    return nn|=1<<pos;
}
ll c;
void bfs(ll ii,ll jj)
{
    queue<pair<ll,ll>>qu;
    qu.push({ii,jj});
    color[ii][jj]=0;
    while(!qu.empty())
    {
        pair<ll,ll>pa;
        pa=qu.front();
        qu.pop();
        for(ll i=0; i<4; i++)
        {
            ll x=pa.first+dx[i];
            ll y=pa.second+dy[i];
            if(x<m&&x>=0&&y<n&&y>=0)
            {
                if(color[x][y]==-1&&s[x][y]!='x')
                {
                    color[x][y]=color[pa.first][pa.second]+1;
                    if(s[x][y]=='*')
                    {
                        ll sou=ck_map[ii][jj];
                        ll dis=ck_map[x][y];
                        weight[sou][dis]=color[x][y];
                        c++;
                    }
                    qu.push({x,y});
                }
            }
        }
    }
}
ll sol(ll i,ll mask)
{
    //cout<<mask<<" t "<<(1<<cnt+1)-1<<"\n";
    if(mask==(1<<cnt+1)-1)
    {
        return 0;
    }
    if(dp[i][mask]!=-1)
    {
        return dp[i][mask];
    }
    ll ans=INT_MAX;
    for(ll j=1; j<=cnt; j++)
    {
        if(((1<<j)&mask)==0)
        {
            ans=min(ans,sol(j,change(mask,j))+weight[i][j]);
        }
    }
    return dp[i][mask]=ans;

}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    while(cin>>n>>m&&n&&m)
    {
        vector<pair<ll,ll>>V;
        cnt=0;
        ll x,y;
        for(ll i=0; i<m; i++)
        {
            cin>>s[i];
            for(ll j=0; j<n; j++)
            {
                ck_map[i][j]=0;
                if(s[i][j]=='*')
                {
                    cnt++;
                    ck_map[i][j]=cnt;
                    V.PB({i,j});
                }
                else if(s[i][j]=='o')
                {
                    x=i;
                    y=j;
                }
            }
        }
        if(cnt==0)
        {
            cout<<"0\n";
            continue;
        }
        for(ll j=0; j<m; j++)
        {
            for(ll k=0; k<n; k++)
            {
                color[j][k]=-1;
            }
        }
        c=0;
        ck_map[x][y]=0;
        bfs(x,y);
        if(c!=cnt)
        {
            cout<<"-1\n";
            continue;
        }
        for(ll i=0; i<cnt; i++)
        {
            for(ll j=0; j<m; j++)
            {
                for(ll k=0; k<n; k++)
                {
                    color[j][k]=-1;
                }
            }
            bfs(V[i].first,V[i].second);
        }
        for(ll i=0; i<=cnt; i++)
        {
            for(ll j=0; j<(1<<(cnt+1)); j++)
            {
                dp[i][j]=-1;
            }
        }
        ll ans=sol(0,1);
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

