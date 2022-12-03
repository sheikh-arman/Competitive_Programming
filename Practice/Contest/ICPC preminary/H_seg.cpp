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
string s,t;
#define N 200010
class node
{
public:
    ll prop;
    ll ar[30];
    ll sum=0;
};

node seg_tree_for_s[(3*N)+10000];
node seg_tree_for_t[(3*N)+10000];
void build_s(ll n,ll b,ll e)
{
    if(b==e)
    {
        seg_tree_for_s[n].prop=-1;
        for(ll i=0; i<26; i++)
        {
            seg_tree_for_s[n].ar[i]=0;
        }
        ll val=s[b-1]-'a';
        seg_tree_for_s[n].ar[val]=1;
        return;
    }
    build_s(n*2,b,(b+e)/2);
    build_s((n*2)+1,((b+e)/2)+1,e);
    seg_tree_for_s[n].prop=-1;
    for(ll i=0; i<26; i++)
    {
        seg_tree_for_s[n].ar[i]=seg_tree_for_s[n*2].ar[i]+seg_tree_for_s[(n*2)+1].ar[i];
    }
}
void propagation_s(ll n,ll b,ll e)
{
    ll rng=(e-b)+1;
    ll mid=(b+e)/2;
    ll prop=seg_tree_for_s[n].prop;
    seg_tree_for_s[n*2].prop=seg_tree_for_s[n].prop;
    seg_tree_for_s[(n*2)+1].prop=seg_tree_for_s[n].prop;
    for(ll i=0; i<26; i++)
    {
        seg_tree_for_s[n].ar[i]=0;
    }
    seg_tree_for_s[n*2].ar[prop]=rng;
    seg_tree_for_s[(n*2)+1].ar[prop]=rng;
    seg_tree_for_s[n].prop=-1;
}
ll query_s(ll n,ll b,ll e,ll i,ll j,ll val)
{
    if(b>=i&&e<=j)
    {
        return seg_tree_for_s[n].ar[val];
    }
    if(e<i||b>j)
    {
        return 0;
    }
    if(seg_tree_for_s[n].prop!=-1)
        propagation_s(n,b,e);
    ll p=query_s(n*2,b,(b+e)/2,i,j,val);
    ll q=query_s(n*2+1,(b+e)/2+1,e,i,j,val);
    return p+q;
}
void update_s(ll n,ll b,ll e,ll i,ll j,ll val)
{
    if(b>=i&&e<=j)
    {
        seg_tree_for_s[n].prop=val;
        ll rng=(e-b)+1;
        for(ll ii=0; ii<26; ii++)
        {
            seg_tree_for_s[n].ar[ii]=0;
        }
        seg_tree_for_s[n].ar[val]=rng;
        return;
    }
    if(e<i||b>j)
    {
        return;
    }
    if(seg_tree_for_s[n].prop!=-1)
        propagation_s(n,b,e);
    update_s(n*2,b,(b+e)/2,i,j,val);
    update_s(n*2+1,(b+e)/2+1,e,i,j,val);
    for(ll ii=0; ii<26; ii++)
    {
        seg_tree_for_s[n].ar[ii]=seg_tree_for_s[n*2].ar[ii]+seg_tree_for_s[(n*2)+1].ar[ii];
    }
}


void build_t(ll n,ll b,ll e)
{
    if(b==e)
    {
        seg_tree_for_t[n].prop=-1;
        for(ll i=0; i<26; i++)
        {
            seg_tree_for_t[n].ar[i]=0;
        }
        ll val=t[b-1]-'a';
        seg_tree_for_t[n].ar[val]=1;
        return;
    }
    build_t(n*2,b,(b+e)/2);
    build_t((n*2)+1,((b+e)/2)+1,e);
    seg_tree_for_t[n].prop=-1;
    for(ll i=0; i<26; i++)
    {
        seg_tree_for_t[n].ar[i]=seg_tree_for_t[n*2].ar[i]+seg_tree_for_t[(n*2)+1].ar[i];
    }
}
void propagation_t(ll n,ll b,ll e)
{
    ll rng=(e-b)+1;
    ll mid=(b+e)/2;
    ll prop=seg_tree_for_t[n].prop;
    seg_tree_for_t[n*2].prop=seg_tree_for_t[n].prop;
    seg_tree_for_t[(n*2)+1].prop=seg_tree_for_t[n].prop;
    for(ll i=0; i<26; i++)
    {
        seg_tree_for_t[n].ar[i]=0;
    }
    seg_tree_for_t[n*2].ar[prop]=rng;
    seg_tree_for_t[(n*2)+1].ar[prop]=rng;
    seg_tree_for_t[n].prop=-1;
}
ll query_t(ll n,ll b,ll e,ll i,ll j,ll val)
{
    if(b>=i&&e<=j)
    {
        return seg_tree_for_t[n].ar[val];
    }
    if(e<i||b>j)
    {
        return 0;
    }
    if(seg_tree_for_t[n].prop!=-1)
        propagation_t(n,b,e);
    ll p=query_t(n*2,b,(b+e)/2,i,j,val);
    ll q=query_t(n*2+1,(b+e)/2+1,e,i,j,val);
    return p+q;
}
void update_t(ll n,ll b,ll e,ll i,ll j,ll val)
{
    if(b>=i&&e<=j)
    {
        seg_tree_for_t[n].prop=val;
        ll rng=(e-b)+1;
        for(ll ii=0; ii<26; ii++)
        {
            seg_tree_for_t[n].ar[ii]=0;
        }
        seg_tree_for_t[n].ar[val]=rng;
        return;
    }
    if(e<i||b>j)
    {
        return;
    }
    if(seg_tree_for_t[n].prop!=-1)
        propagation_t(n,b,e);
    update_t(n*2,b,(b+e)/2,i,j,val);
    update_t(n*2+1,(b+e)/2+1,e,i,j,val);
    for(ll ii=0; ii<26; ii++)
    {
        seg_tree_for_t[n].ar[ii]=seg_tree_for_t[n*2].ar[ii]+seg_tree_for_t[(n*2)+1].ar[ii];
    }
}


int main()
{
    FasrIO;
    //freopen("input.txt","r",stdin);
    ll tcase=1000;
    //scanf("%lld",&tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>s>>t;
        ll siz1=s.size();
        ll siz2=t.size();
        build_s(1,1,siz1);
        build_t(1,1,siz2);
        ll q;
        cin>>q;
        for(ll i=0; i<q; i++)
        {
            ll a;
            cin>>a;
            if(a==1)
            {
                ll x,y;
                char ch;
                cin>>x>>y>>ch;
                ll val=ch-'a';
                update_s(1,1,siz1,x,y,val);
            }
            else if(a==2)
            {
                ll x,y;
                char ch;
                cin>>x>>y>>ch;
                ll val=ch-'a';
                update_t(1,1,siz2,x,y,val);
            }
            else
            {
                ll a,b,x,y;
                char ch;
                cin>>a>>b>>x>>y;
                ll total=(abs(a-b)+2)*(abs(x-y)+2);
                ll sub=0;
                for(ll j=0; j<26; j++)
                {
                    ll tm1=query_s(1,1,siz1,a,b,j);
                    ll tm2=query_t(1,1,siz2,x,y,j);
                    sub+=(tm1*tm2);
                }
                //cout<<total<<" "<<sub<<" x\n";
                ll ans=total-sub;
                cout<<ans<<"\n";
            }
        }

    }
}

//fc de
















