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
ll rep[100010];
ll rep_rev[100010];
ll Find(ll node)
{
    return (rep[node]==node)?node:rep[node]=Find(rep[node]);
}
ll Find_rev(ll node)
{
    return (rep_rev[node]==node)?node:rep_rev[node]=Find_rev(rep_rev[node]);
}
ll ar_ck[100010];
ll ar[100010];
bool cmp(ll x,ll y)
{
    if(ar_ck[x]==0&&ar_ck[y]==0)
    {
        return x<y;
    }
    else
    {
        if(ar_ck[x]>0&&ar_ck[y]>0){
            if(ar_ck[x]>=ar[y]&&ar_ck[y]>=ar[x]){
                return x<y;
            }
            else{
                return false;
            }
        }
        if(ar_ck[x]==0){
            if(ar_ck[y]>=ar[x]){
                return y<x;
            }
            else{
                return false;
            }
        }
        if(ar_ck[y]==0){
            if(ar_ck[x]>=ar[y]){
                return y>x;
            }
            else{
                return false;
            }
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
        ll n,m;
        cin>>n>>m;
        vector<ll>ans_v;
        for(ll i=0; i<=n+1; i++)
        {
            ar_ck[i]=0;
            rep[i]=i;
            rep_rev[i]=i;
            ans_v.PB(0);
            ar[i]=0;
        }
        vector< pair<ll,ll> >V;
        for(ll i=0; i<m; i++)
        {
            ll x,y;
            cin>>x>>y;
            V.PB({y,x});
            ar_ck[x]=y;
        }
        VST(V);
        ll ck=1;
        for(ll i=0; i<m; i++)
        {
            ll y=V[i].first;
            ll x=V[i].second;
            ll cur=x;
            while(cur!=Find(cur))
            {
                cur=Find(cur);
            }
            if(cur>y)
            {
                ll cur=y;
                while(cur!=Find_rev(cur))
                {
                    cur=Find_rev(cur);
                }
                if(cur<1)
                {
                    ck=0;
                    break;
                }
                ans_v[cur]=x;
                ar[x]=cur;
                rep_rev[cur]=Find_rev(cur-1);
                rep[cur]=Find(cur+1);
            }
            else
            {
                ans_v[cur]=x;
                ar[x]=cur;
                rep[cur]=Find(cur+1);
                rep_rev[cur]=Find_rev(cur-1);
            }
        }
        for(ll i=1; i<=n; i++)
        {
            if(ar[i]==0)
            {
                ll cur=1;
                while(cur!=Find(cur))
                {
                    cur=Find(cur);
                }
                ans_v[cur]=i;
                rep[cur]=Find(cur+1);
            }
        }
        if(ck==0)
        {
            cout<<"-1\n";
        }
        else
        {
            sort(ans_v.begin(),ans_v.end(),cmp);
            for(ll i=1; i<=n; i++)
            {
                cout<<ans_v[i]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}





