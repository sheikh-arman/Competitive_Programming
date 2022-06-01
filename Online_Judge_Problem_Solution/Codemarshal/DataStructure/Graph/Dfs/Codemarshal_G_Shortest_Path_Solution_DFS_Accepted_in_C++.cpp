#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll dis[30010];
ll total[30010];
ll rep[30010];
bool color[30010];
ll cnt;
bool ck_loop[30010];
vector< pair<ll,ll> >edj[30010],V;
void dfs(ll node,bool status,ll representative)
{
    ck_loop[node]=status;
    color[node]=1;
    ll siz=edj[node].size();
    for(ll i=0; i<siz; i++)
    {
        ll child=edj[node][i].first;
        if(color[child]==false)
        {
            color[child]=1;
            ck_loop[child]=status;
            cnt+=edj[node][i].second;
            dis[child]=cnt;
            rep[child]=representative;
            dfs(child,status,representative);
        }
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    ll tcase;
    scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        V.clear();
        ll n,e;
        scanf("%lld %lld",&n,&e);
        for(ll i=0; i<=n; i++)
        {
            dis[i]=0;
            total[i]=0;
            ck_loop[i]=false;
            rep[i]=i;
            edj[i].clear();
            color[i]=false;
        }
        for(ll i=0; i<e; i++)
        {
            ll a,b,c;
            scanf("%lld%lld%lld",&a,&b,&c);
            //joint_node(a,b,c);
            edj[a].push_back({b,c});
            edj[b].push_back({a,c});
        }
        for(ll i=1; i<=n; i++)
        {
            ll x=edj[i].size();
            V.push_back({x,i});
        }
        sort(V.begin(),V.end());
        for(ll i=0; i<n; i++)
        {
            ll node=V[i].second;
            if(color[node]==false)
            {
                rep[node]=node;
                cnt=0;
                bool st=0;
                if(V[i].first==2)
                {
                    st=1;//

                }
                dfs(node,st,node);
                if(st){
                    cnt+=edj[node][1].second;
                }
                total[node]=cnt;
            }
        }
        ll qq;
        printf("Case %lld:\n",test);
        scanf("%lld",&qq);
        for(ll i=0; i<qq; i++)
        {
            ll a,b;
            scanf("%lld %lld",&a,&b);

            if(rep[a]!=rep[b])
            {
                printf("-1\n");
            }
            else
            {
                //printf("%lld %lld %lld xx\n",(ll)ck_loop[rep[a]],rep[a],total[rep[a]]);
                if(ck_loop[a]==true)
                {
                    ll ans=abs(dis[a]-dis[b]);
                    ans=min(ans,(total[rep[a]]-ans));
                    printf("%lld\n",ans);
                }
                else
                {
                    ll ans=abs(dis[a]-dis[b]);
                    printf("%lld\n",ans);
                }
            }

        }
    }
    return 0;
}

