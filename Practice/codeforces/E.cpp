#include<bits/stdc++.h>
using namespace std;
int dx[]= {1,-1,0,0,1,-1,-1,1};
int dy[]= {0,0,1,-1,1,1,-1,-1};
int mem[52][52][52][52];
int n;
string s[52];
int bfs(int ax,int ay, int bx, int by)
{
    int ans=INT_MAX;
    queue<pair<pair<int,int>,pair<int,int> > >q;
    q.push({{ax,ay},{bx,by}});
    mem[ax][ay][bx][by]=0;
    while(!q.empty())
    {
        ax=q.front().first.first;
        ay=q.front().first.second;
        bx=q.front().second.first;
        by=q.front().second.second;
        q.pop();
        if(ax==bx&&ay==by)
        {
            ans=min(mem[ax][ay][bx][by],ans);
            continue;
        }
        for(int i=0; i<4; i++)
        {
            int tm_ax=ax+dx[i];
            int tm_ay=ay+dy[i];
            int tm_bx=bx+dx[i];
            int tm_by=by+dy[i];
            int ck=0;
            if((tm_ax>=n||tm_ax<0)||(tm_ay>=n||tm_ay<0))
            {
                ck++;
                tm_ax=ax;
                tm_ay=ay;
            }
            else if((s[tm_ax][tm_ay]=='*'))
            {
                ck++;
                tm_ax=ax;
                tm_ay=ay;
            }

            if((tm_bx>=n||tm_bx<0)||(tm_by>=n||tm_by<0))
            {
                ck++;
                tm_bx=bx;
                tm_by=by;
            }
            else if((s[tm_bx][tm_by]!='.'))
            {
                ck++;
                tm_bx=bx;
                tm_by=by;
            }
            if(ck>1)
            {
                continue;
            }
            if(mem[tm_ax][tm_ay][tm_bx][tm_by]>mem[ax][ay][bx][by]+1)
            {
                mem[tm_ax][tm_ay][tm_bx][tm_by]=mem[ax][ay][bx][by]+1;
                q.push({{tm_ax,tm_ay},{tm_bx,tm_by}});
            }
        }
    }
    return ans;
}
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main()
{
    fast;
    cin>>n;
    int ax=0,ay=0,bx=0,by=0;
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
        for(int j=0; j<n; j++)
        {
            if(s[i][j]=='a')
            {
                ax=i;
                ay=j;
                s[i][j]='.';
            }
            if(s[i][j]=='b')
            {
                bx=i;
                by=j;
                s[i][j]='.';
            }
        }
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            for(int x=0; x<=n; x++)
            {
                for(int y=0; y<=n; y++)
                {
                    mem[i][j][x][y]=INT_MAX;
                }
            }
        }
    }
    int ans=bfs(ax,ay,bx,by);
    if(ans==INT_MAX)
    {
        cout<<"no solution\n";
    }
    else
    {
        cout<<ans<<"\n";
    }
    return 0;
}




