#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FasrIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 100000000000000000

template<typename T>
using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using min_heap=priority_queue<ll,vector<ll>,greater<ll>>;
using min_heap_my=priority_queue<pair<pair<ll,ll>,ll>,vector<pair<pair<ll,ll>,ll>>,greater<pair<pair<ll,ll>,ll>>>;
ll ar_cost_c[10];

ll dx_ar[] = {-1,-1,-1,0,0,1,1,1};
ll dy_ar[] = {-1,0,1,-1,1,-1,0,1};
int main()
{
    //freopen("input.txt","r",stdin);
    ll tcase=1;
    scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m,p,q;
        //cin>>n>>m>>p>>q;
        scanf("%lld %lld %lld %lld",&n,&m,&p,&q);
        ll sx,sy,dx,dy;
        //cin>>sx>>sy>>dx>>dy;
        scanf("%lld %lld %lld %lld",&sx,&sy,&dx,&dy);
        for(ll i=0; i<8; i++)
        {
            ll a;
            scanf("%lld",&a);
            ar_cost_c[i]=a;
        }
        vector< pair<pair<ll,ll>,ll> >edj[n+2][m+2];
        for(ll i=0; i<p; i++)
        {
            ll a,b,c,d,w;
            scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&w);
            edj[a][b].pb({{c,d},w});
        }
        ll cost[n+2][m+2][13];
        ll obs[n+2][m+2];
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=m; j++)
            {
                for(ll k=0; k<=11; k++)
                {
                    cost[i][j][k]=Max;
                }
                obs[i][j]=0;
            }
        }
        for(ll i=0; i<q; i++)
        {
            ll a,b;
            scanf("%lld %lld",&a,&b);
            obs[a][b]=1;
        }
        min_heap_my pq;
        pq.push({{0,sx},sy});
        cost[sx][sy][9]=0;
        while(!pq.empty())
        {
            ll x=pq.top().first.second;
            ll y=pq.top().second;
            ll cst=pq.top().first.first;
            pq.pop();
            ll mi=cost[x][y][9];
            //cout<<x<<" "<<y<<" "<<mi<<" x\n";
            for(ll i=0; i<8; i++)
            {
                ll tm_x=dx_ar[i]+x;
                ll tm_y=dy_ar[i]+y;
                if(tm_x>=1&&tm_x<=n&&tm_y>=1&&tm_y<=m)
                {
                    if(obs[tm_x][tm_y]==0)
                    {
                        ll ck=0;
                        ll before=cost[tm_x][tm_y][i];
                        cost[tm_x][tm_y][i]=min(cost[x][y][i],mi+ar_cost_c[i]);
                        cost[tm_x][tm_y][9]=min(cost[tm_x][tm_y][9],cost[tm_x][tm_y][i]);
                        if(cost[tm_x][tm_y][i]<before)
                        {
                            pq.push({{cost[tm_x][tm_y][9],tm_x},tm_y});
                        }
                    }
                }
            }
            ll siz=edj[x][y].size();
            for(ll i=0; i<siz; i++)
            {
                ll xx=edj[x][y][i].first.first;
                ll yy=edj[x][y][i].first.second;
                ll cst2=edj[x][y][i].second;
                ll before=cost[xx][yy][9];
                cost[xx][yy][9]=min(cost[xx][yy][9],cost[x][y][9]+cst2);
                if(before>cost[xx][yy][9])
                {
                    pq.push({{cost[xx][yy][9],xx},yy});
                }
            }
        }
        ll mi_val=Max;
        //cout<<dx<<" "<<dy<<" "<<cost[dx][dy][9]<<" tt\n";
        if(cost[dx][dy][9]>=Max)
        {
            cost[dx][dy][9]=-1;
        }
        cout<<"Case "<<test<<": "<<cost[dx][dy][9]<<"\n";
    }
}


















