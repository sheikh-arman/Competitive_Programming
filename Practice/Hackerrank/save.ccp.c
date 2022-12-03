
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
#define MAX 100010
#define T(n) printf("test : %d\n",n);
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};

ll rep[MAX+10];
ll cnt_node[MAX+10];
ll rnk[MAX+10];
//ordered_set for_id[MAX+10];
//ordered_set ::iterator it;
ll ar_1st[2*MAX+10];
ll ar_id[2*MAX+10];

ll Find(ll node)
{
    return (rep[node]==node?node:rep[node]=Find(rep[node]));
}

int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;

        ll cnt_rnk=n;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            rnk[a]=cnt_rnk;
        }
        for(ll i=0; i<=n; i++)
        {
            rep[i]=i;
            cnt_node[i]=1;

        }
        for(ll i=0; i<m; i++)
        {
            ll a;
            cin>>a;
            if(a==1)
            {
                ll u,v;
                cin>>u>>v;
                u=Find(u);
                v=Find(v);
                if(u!=v)
                {
                    if(cnt_node[u]>cnt_node[v])
                    {
                        swap(u,v);
                    }
                    ll siz=for_id[u].size();
////                    for(ll j=0; j<siz; j++)
////                    {
////                        ll val=*for_id[u].find_by_order(j);
////                        for_id[v].insert(val);
////                    }
//                    vector<pair<ll,ll>>V;
//                    V.PB({ar_1st[u],ar_id[u]});
//                    //V.PB({ar_2st[u],ar_2st_id[u]});
//                    V.PB({ar_1st[v],ar_id[v]});
//                    //V.PB({ar_2nd[v],ar_2nd_id[v]});
//                    sort(V.begin(),V.end(),cmp);
//                    ar_1st[v]=V[0].first;
//                    ar_id[v]=V[0].second;

                    cnt_node[v]+=cnt_node[u];
                    cnt_node[u]=0;
                    rep[u]=v;
                }
            }
            else if(a==2)
            {
                ll u;
                cin>>u;
                rnk[u]++;
                ll val=rnk[u];
                ll id=u;
                u=Find(u);
                ll pre_rnk=ar_1st[u];
                ll pre_id=ar_id[u];
                if(val>pre_rnk)
                {
                    ar_1st[u]=val;
                    ar_id[u]=id;
                }
                else if(val==pre_rnk)
                {
                    ar_id[u]=max(id,pre_id);
                }
            }
            else
            {
                ll u;
                cin>>u;
                u=Find(u);
                cout<<ar_id[u]<<"\n";
            }
        }




    }
    return 0;
}





