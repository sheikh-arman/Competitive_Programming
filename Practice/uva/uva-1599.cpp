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
ll label[100010];
ll label_save[100010];
vector<pair<ll,ll>>edj[100010];
bitset<100010>color;
void bfs(ll node)
{
    label[node]=0;
    queue<ll>q;
    q.push(node);
    while(!q.empty())
    {
        ll pa=q.front();
        q.pop();
        ll siz=edj[pa].size();
        for(ll i=0; i<siz; i++)
        {
            ll child=edj[pa][i].first;
            if(label[child]==-1)
            {
                label[child]=label[pa]+1;
                q.push(child);
            }
        }
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        while(scanf("%lld %lld",&n,&m)!=EOF)
        {
            for(ll i=0; i<=n; i++)
            {
                edj[i].clear();
                label[i]=-1;
                color[i]=false;
            }
            for(ll i=0; i<m; i++)
            {
                ll a,b,w;
                scanf("%lld %lld %lld",&a,&b,&w);
                edj[a].PB({b,w});
                edj[b].PB({a,w});
            }

            bfs(1);
            for(ll i=1; i<=n; i++)
            {
                label_save[i]=label[i];
                label[i]=-1;
            }
            bfs(n);
            for(ll i=1; i<=n; i++)
            {
                if(label[i]+label_save[i]==label_save[n])
                {
                    color[i]=true;
                }
            }
            vector<ll>ans,V_1st,V_2nd;
            V_1st.PB(1);
            ll cnt=0;
            while(cnt<label_save[n])
            {
                cnt++;
                ll si=V_1st.size();
                ll mi=9999999999999999;
                V_2nd.clear();
                for(ll i=0; i<si; i++)
                {
                    ll node=V_1st[i];
                    ll siz=edj[node].size();
                    for(ll j=0; j<siz; j++)
                    {
                        ll child=edj[node][j].first;
                        ll cost=edj[node][j].second;
                        if(cost<mi)
                        {
                            mi=cost;
                        }
                    }
                }
                for(ll i=0; i<si; i++)
                {
                    ll node=V_1st[i];
                    ll siz=edj[node].size();
                    for(ll j=0; j<siz; j++)
                    {
                        ll child=edj[node][j].first;
                        ll cost=edj[node][j].second;
                        if(cost==mi)
                        {
                            V_2nd.push_back(child);
                        }
                    }
                }
                V_1st.clear();
                V_1st=V_2nd;
                ans.PB(mi);
            }
            ll siz=ans.size();
            printf("%lld\n",siz);
            for(ll i=0; i<siz; i++)
            {
                if(i>0)printf(" ");
                printf("%lld",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}





