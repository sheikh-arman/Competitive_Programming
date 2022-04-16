#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
vector<ll>edj[210];
ll color[210];
ll bfs(ll start)
{
    queue<ll>q;
    q.push(start);
    ll ck=1;
    color[start]=1;
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();
        // T(node);
        for(ll i:edj[node])
        {
            if(color[i]==0)
            {
                if(color[node]==1)
                {
                    color[i]=2;
                }
                else
                {
                    color[i]=1;
                }
                q.push(i);
            }
            else
            {
                if(color[i]==color[node])
                {
                    ck=-1;
                    while(!q.empty())q.pop();
                }

            }
        }
    }
    return ck;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);

    ll n,edge;
    while(1)
    {
        //T(1);
        cin>>n;
        if(n==0)break;
        cin>>edge;
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            color[i]=0;
        }
        for(ll i=0; i<edge; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
        }
        color[0]=1;
        ll ans=bfs(0);
        if(ans==-1)
        {
            cout<<"NOT BICOLORABLE.\n";
        }
        else
        {
            cout<<"BICOLORABLE.\n";
        }
    }

    return 0;
}




