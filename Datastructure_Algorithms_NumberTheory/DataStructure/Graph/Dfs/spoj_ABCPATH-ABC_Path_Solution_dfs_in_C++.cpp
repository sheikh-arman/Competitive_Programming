/*
    Author : SK Arman Hossain
    University of Barishal
    Problem: dfs editorial
    Solution:
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 55
bitset<N>color[N];
ll ans=0,n,m;
ll dx[] = {0,0,1,-1,1,-1,-1,1};
ll dy[] = {1,-1,0,0,1,1,-1,-1};
ll ar[N][N];
void dfs(ll x,ll y,ll cnt=1)
{
    ans=max(ans,cnt);
    color[x][y]=true;
    for(ll i=0; i<8; i++)
    {
        ll tmx=x+dx[i];
        ll tmy=y+dy[i];
        if(tmx>=0&&tmx<n&&tmy>=0&&tmy<m)
        {
            if(color[tmx][tmy]==false&&ar[tmx][tmy]==ar[x][y]+1)
            {
                color[tmx][tmy]=true;
                dfs(tmx,tmy,cnt+1);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
    while(cin>>n>>m&&(n||m))
    {
        vector<pair<ll,ll>>V;
        ans=0;
        for(ll i=0; i<n; i++)
        {
            string s;
            cin>>s;
            for(ll j=0; j<m; j++)
            {
                ar[i][j]=s[j]-'A';
                if(s[j]=='A'){
                    V.push_back({i,j});
                }
                color[i][j]=false;
            }
        }
        ll siz=V.size();
        for(ll i=0;i<siz;i++){
            dfs(V[i].first,V[i].second);
        }
        cout<<"Case "<<test++<<": "<<ans<<"\n";
    }

    return 0;
}
