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
string s[110];
ll n,m;
ll prex[110][110];
ll prey[110][110];
void bfs()
{
    queue<pair<ll,ll>>q;
    q.push({0,0});
    while(!q.empty())
    {
        pair<ll,ll> tp=q.front();
        q.pop();
        for(ll i=0; i<4; i++)
        {
            ll x=dx[i]+tp.first;
            ll y=dy[i]+tp.second;
            if(x>=0&&y>=0&&x<n&&y<m)
            {
                if(s[x][y]!='*'&&prex[x][y]==-1&&prey[x][y]==-1)
                {
                    prex[x][y]=tp.first;
                    prey[x][y]=tp.second;
                    if(s[x][y]!='F')
                    {
                        q.push({x,y});
                    }
                }
            }
        }
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    fflush(stdout);
    ll tcase=1;
    // cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {

        cin>>n>>m;
        ll x,y;
        for(ll i=0; i<n; i++)
        {
            cin>>s[i];
            for(ll j=0; j<m; j++)
            {
                if(s[i][j]=='F')
                {
                    x=i;
                    y=j;
                    prex[i][j]=-1;
                    prey[i][j]=-1;
                }
            }
        }
        ll savex=x,savey=y;
        vector<pair<ll,ll>>V;
        while(prex[x][y]!=-1)
        {
            V.PB({x,y});
            ll tmx=prex[x][y];
            ll tmy=prey[x][y];
            x=tmx;
            y=tmy;
        }
        V.PB({0,0});
        reverse(V.begin(),V.end());
        ll siz=V.size();
        ll l_swap=0,d_swap=0;
        ll con_l_swap=0,con_d_swap=0;
        ll currx=0,curry=0;
        ll pre_currx=0,pre_curry=0;
        for(ll i=1; i<siz; i++)
        {
            pre_currx=currx;
            pre_curry=curry;
            if(V[i].first!=currx)
            {
                if(V[i].first>currx)
                {
                    if(d_swap)
                    {
                        if(con_d_swap)
                        {
                            cout<<"U\n";
                        }
                        else
                        {
                            cout<<"D\n";
                        }
                        cin>>currx>>curry;
                        currx--;
                        curry--;
                    }
                    else
                    {
                        cout<<"D\n";
                        cin>>currx>>curry;
                        currx--;
                        curry--;
                        if(currx==pre_currx&&curry==pre_curry)
                        {
                            d_swap=1;
                            con_d_swap=1;
                            cout<<"U\n";
                            cin>>currx>>curry;
                            currx--;
                            curry--;
                        }
                        else
                        {
                            d_swap=1;
                        }
                    }
                }
                else
                {

                    if(con_d_swap)
                    {
                        cout<<"D\n";
                    }
                    else
                    {
                        cout<<"U\n";
                    }
                    cin>>currx>>curry;
                    currx--;
                    curry--;
                }
            }
            else
            {
                if(V[i].second>curry)
                {
                    if(l_swap)
                    {
                        if(con_l_swap)
                        {
                            cout<<"R\n";
                        }
                        else
                        {
                            cout<<"L\n";
                        }
                        cin>>currx>>curry;
                        currx--;
                        curry--;
                    }
                    else
                    {
                        cout<<"R\n";
                        cin>>currx>>curry;
                        currx--;
                        curry--;
                        if(currx==pre_currx&&curry==pre_curry)
                        {
                            l_swap=1;
                            con_l_swap=1;
                            cout<<"L\n";
                            cin>>currx>>curry;
                            currx--;
                            curry--;
                        }
                        else
                        {
                            l_swap=1;
                        }
                    }
                }
                else
                {
                    if(con_l_swap)
                    {
                        cout<<"L\n";
                    }
                    else
                    {
                        cout<<"R\n";
                    }
                    cin>>currx>>curry;
                    currx--;
                    curry--;
                }
            }
        }
    }
    return 0;
}




