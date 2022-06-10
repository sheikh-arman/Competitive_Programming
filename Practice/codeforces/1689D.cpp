/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
    Date:
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define sf(n) scanf("%lld",&n);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define nl cout<<"\n";
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
#define MAX 2000010
#define T(n) printf("test : %d\n",n);
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
string s[1010];
ll ansx,ansy,n,m,ma;
ll label[1010][1010];
void bfs(ll start,ll en)
{
    if(start>=0&&start<n&&en>=0&&en<m)
    {
        ll tm_ne=0;
        queue<pair<ll,ll>>q;
        q.push({start,en});
        label[start][en]=0;
        while(!q.empty())
        {
            ll u=q.front().first;
            ll v=q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                ll x=dx[i]+u;
                ll y=dy[i]+v;
                if(x>=0&&x<n&&y>=0&&y<m)
                {
                    if(label[x][y]==-1)
                    {
                        label[x][y]=label[u][v]+1;
                        if(s[x][y]=='B')
                        {
                            ll ne=abs(x-start)+abs(en-y);
                            tm_ne=max(tm_ne,ne);
                        }
                        q.push({x,y});
                    }
                }
            }
        }
        if(ma>tm_ne)
        {
            ansx=start;
            ansy=en;
            ma=tm_ne;
        }
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        n,m;
        cin>>n>>m;
        ll x1=LONG_LONG_MAX,x2=-1,y1=LONG_LONG_MAX,y2=-1;
        for(ll i=0; i<n; i++)
        {
            cin>>s[i];
            for(ll j=0; j<m; j++)
            {
                if(s[i][j]=='B')
                {
                    x1=min(x1,i);
                    x2=max(x2,i);
                    y1=min(y1,j);
                    y2=max(y2,j);
                }
            }
        }
        // cout<<x1<<" "<<x2<<" x\n";
        //cout<<y1<<" "<<y2<<" x\n";
        x1+=abs(x1-x2)/2;
        y1+=abs(y1-y2)/2;
        ma=LONG_MAX;
        for(ll i=0; i<8; i++)
        {
            for(int ii=0; ii<=n; ii++)
            {
                for(int j=0; j<=m; j++)
                {
                    label[ii][j]=-1;
                }
            }
            bfs(x1+dx[i],y1+dy[i]);
        }
        cout<<ansx+1<<" "<<ansy+1<<"\n";



    }
    return 0;
}





