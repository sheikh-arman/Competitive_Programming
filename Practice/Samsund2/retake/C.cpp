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
string s[111];
ll label[110][110];
ll n,m;
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>n>>m;
        for(ll i=0; i<n; i++)
        {
            cin>>s[i];
        }
        ll cnt=0,pos_x=0,pos_y=0;
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                if(s[i][j]=='c')
                {
                    for(ll x=0; x<4; x++)
                    {
                        ll tm_x=i+dx[x];
                        ll tm_y=j+dy[x];
                        if(tm_x>=0&&tm_x<n&&tm_y>=0&&tm_y<m)
                        {
                            if(s[tm_x][tm_y]=='.')
                            {
                                s[tm_x][tm_y]='#';
                            }
                        }
                    }
                }
                if(s[i][j]=='b')cnt++;
                if(s[i][j]=='t')
                {
                    pos_x=i;
                    pos_y=j;
                }
                label[i][j]=-1;
            }
        }
        ll ck=1;
        queue<pair<ll,ll> >q;
        q.push({pos_x,pos_y});
        ll new_cnt=0;
        label[pos_x][pos_y]=0;
        while(!q.empty()&&ck)
        {
            pair<ll,ll> pa=q.front();
            q.pop();
            for(ll x=0; x<4; x++)
            {
                ll tm_x=pa.first+dx[x];
                ll tm_y=pa.second+dy[x];
                if(tm_x>=0&&tm_x<n&&tm_y>=0&&tm_y<m)
                {
                    if(s[tm_x][tm_y]=='.'&&label[tm_x][tm_y]==-1)
                    {
                        q.push({tm_x,tm_y});
                    }
                    else if(s[tm_x][tm_y]=='b'&&label[tm_x][tm_y]==-1)
                    {
                        new_cnt++;
                        q.push({tm_x,tm_y});
                    }
                    else if(s[tm_x][tm_y]=='c')
                    {
                        ck=0;
                    }
                    label[tm_x][tm_y]=1;
                }
            }
        }
        if(new_cnt==cnt&&ck)
        {
            cout<<"Case "<<test<<": yes\n";
        }
        else
        {
            cout<<"Case "<<test<<": no\n";
        }
    }
    return 0;
}






