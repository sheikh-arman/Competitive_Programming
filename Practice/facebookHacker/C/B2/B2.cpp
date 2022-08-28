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
ll mat[3010][3010];
int main()
{
    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=m; j++)
            {
                mat[i][j]=0;
            }
        }
        string s[3010];
        for(ll i=0; i<n; i++)
        {
            cin>>s[i];
            for(ll j=0; j<m; j++)
            {
                if(s[i][j]=='#')
                {
                    mat[i][j]=1;
                }
            }
        }
        queue<pair<ll,ll>>q;
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                if(mat[i][j]==0)
                {
                    ll cnt=0;
                    for(ll k=0; k<4; k++)
                    {
                        ll tm_x=i+dx[k];
                        ll tm_y=j+dy[k];
                        if(tm_x>=0&&tm_x<n&&tm_y>=0&&tm_y<m)
                        {
                            if(mat[tm_x][tm_y]==0)
                            {
                                cnt++;
                            }
                        }
                    }
                    if(cnt<2)
                    {
                        q.push({i,j});
                    }
                }
            }
        }
        while(!q.empty())
        {
            pair<ll,ll>pa=q.front();
            q.pop();
            if(mat[pa.first][pa.second]==1)continue;
            ll cnt=0;
            ll i=pa.first;
            ll j=pa.second;
            mat[i][j]=1;
            for(ll k=0; k<4; k++)
            {
                ll tm_x=i+dx[k];
                ll tm_y=j+dy[k];
                if(tm_x>=0&&tm_x<n&&tm_y>=0&&tm_y<m)
                {
                    if(mat[tm_x][tm_y]==0)
                    {
                        ll cnt=0;
                        i=tm_x;
                        j=tm_y;
                        for(ll kk=0; kk<4; kk++)
                        {
                            tm_x=i+dx[kk];
                            tm_y=j+dy[kk];
                            if(tm_x>=0&&tm_x<n&&tm_y>=0&&tm_y<m)
                            {
                                if(mat[tm_x][tm_y]==0)
                                {
                                    cnt++;
                                }

                            }
                        }
                        if(cnt<2)
                        {
                            q.push({i,j});
                        }
                        break;
                    }
                }
            }
        }
        ll ck=1;
        for(ll i=0; i<n&&ck; i++)
        {
            for(ll j=0; j<m&&ck; j++)
            {
                if(mat[i][j]==1&&s[i][j]=='^')
                {
                    ck=0;
                    break;
                }
            }
        }
        if(ck)
        {
            cout<<"Case #"<<test<<": Possible\n";
            for(ll i=0; i<n; i++)
            {
                for(ll j=0; j<m; j++)
                {
                    if(mat[i][j]==0)s[i][j]='^';
                    cout<<s[i][j];
                }
                cout<<"\n";
            }
        }
        else
        {
            cout<<"Case #"<<test<<": Impossible\n";
        }
    }
    return 0;
}
/*
1
4 4
..#.
.#.#
....
.#^.


*/




