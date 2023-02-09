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
#define pb push_back
#define all(V) V.begin(),V.end()
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
#define MAX 200000000010
#define T(n) printf("test : %d\n",n);
ll dx[]= {1,-1,0,0};
ll dy[]= {0,0,1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;

        string s[n+2];
        for(ll i=0;i<=m+1;i++){
            s[0]+='x';
            s[n+1]+='x';
        }
        for(ll i=1;i<=n;i++){
            cin>>s[i];
            s[i]="x"+s[i]+"x";
        }

        ll loop=1;
        while(loop){
            loop=0;
            priority_queue< pair< ll, pair<ll,ll> >, vector< pair< ll, pair<ll,ll> > >, greater< pair< ll, pair<ll,ll> > > > pq;
            ll vis[n+2][m+2],par[n+2][m+2];
            memset(vis,-1,sizeof(vis));
            for(ll i=0;i<=n+1;i++){
                for(ll j=0;j<=m+1;j++){
                    if(s[i][j]=='x'){
                        pq.push({0ll,{i,j}});
                        vis[i][j]=0;
                        par[i][j]=-1;
                    }
                }
            }
            
            while(!pq.empty()){

                ll u=pq.top().second.first;
                ll v=pq.top().second.second;
                pq.pop();

                for(ll i=0;i<4;i++){
                    if(u+dx[i]<0 || u+dx[i]>n+1 || v+dy[i]<0 || v+dy[i]>m+1) continue;
                    ll p=u+dx[i],q=v+dy[i];
                    if(s[p][q]=='*'){
                        loop=1;
                        if(vis[p][q]==-1) vis[p][q]=MAX;
                        if(vis[u][v]+1<vis[p][q]){
                            vis[p][q]=vis[u][v]+1;
                            par[p][q]=i;
                        }
                    }
                    if(s[p][q]!='.') continue;
                    if(vis[p][q]!=-1 && vis[p][q]<vis[u][v]+1) continue;
                    vis[p][q]=vis[u][v]+1;
                    pq.push({vis[p][q],{p,q}});
                    par[p][q]=i;
                }
            }

            ll u,v,d=-1;
            for(ll i=1;i<=n;i++){
                for(ll j=1;j<=m;j++){
                    if(vis[i][j]>d && s[i][j]=='*'){
                        d=vis[i][j];
                        u=i,v=j;
                    }
                }
            }
            if(d==-1) break;
            while(par[u][v]!=-1){
                s[u][v]='#';
                ll i=par[u][v];
                u-=dx[i];
                v-=dy[i];
            }
            for(ll i=0;i<=n+1;i++) cout<<s[i]<<endl;
        }
        ll ok=0;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                if(s[i][j]=='*'){
                    ok=1;
                    break;
                }
            }
        }

        if(ok) cout<<"Case "<<test<<": "<<"no"<<endl;
        else cout<<"Case "<<test<<": "<<"yes"<<endl;

    }
    return 0;
}





