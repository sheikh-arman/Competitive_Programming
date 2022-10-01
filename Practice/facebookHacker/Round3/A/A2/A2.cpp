/*
    Sk arman Hossain
    University of Barisal

    Problem name : https://www.codechef.com/problems/TREETR
    Algorithm : graph_linear with dfs + segment tree
 */
#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> policy_set;

#define nl printf("\n");
#define N 200001
#define PR pair<ll,ll>
#define sf(n) scanf("%lld", &n)
#define sf2(n, m) scanf("%lld %lld",&n,&m)
#define sf3(n, m,k ) scanf("%lld %lld %lld",&n,&m,&k)
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES printf("YES\n")
#define NO printf("NO\n")
#define minus1 printf("-1\n")
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};

#define N 1000010
ll tree2[(4*N)+10];
ll ar[N+10];
ll build(ll n,ll b,ll e)
{
    if(b==e)
    {
        return tree2[n]=ar[b];
    }
    ll p=build(n*2,b,(b+e)/2);
    ll q=build(n*2+1,(b+e)/2+1,e);
    return tree2[n]=p^q;
}
ll query(ll n,ll b,ll e,ll l,ll r)
{
    if(b>=l&&e<=r)
    {
        return tree2[n];
    }
    else if(e<l||b>r)
    {
        return 0;
    }
    ll p=query(n*2,b,(b+e)/2,l,r);
    ll q=query(n*2+1,(b+e)/2+1,e,l,r);
    return p^q;
}
ll update(ll n,ll b,ll e,ll l,ll r)
{
    if(b>=l&&e<=r)
    {
        return tree2[n]=ar[b];
    }
    else if(e<l||b>r)
    {
        return tree2[n];
    }
    ll p=update(n*2,b,(b+e)/2,l,r);
    ll q=update(n*2+1,(b+e)/2+1,e,l,r);
    return tree2[n]=p^q;
}
policy_set V[1000010];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        for(ll i=0; i<=1000000; i++)
        {
            V[i].clear();
        }
        for(ll i=1; i<=n; i++)
        {
            cin>>ar[i];
            V[ar[i]].insert(i);
        }
        ll xx=build(1,1,n);
        ll q;
        cin>>q;
        ll ans=0;
        for(ll i=0; i<q; i++)
        {
            ll a;
            cin>>a;
            if(a==1)
            {
                ll l,val;
                cin>>l>>val;
                V[ar[l]].erase(l);
                ar[l]=val;
                update(1,1,n,l,l);
                V[val].insert(l);
            }
            else
            {
                ll l,r;
                cin>>l>>r;
                if(l>r)swap(l,r);
                if(r-l<1)
                {
                    ans++;
                     //cout<<i+1<<" "<<ans<<" xyyyyy\n\n";
                    continue;
                }
                if((r-l)%2==0)
                {
                    ll val1=query(1,1,n,l,r);
                    //cout<<val1<<" hi\n";
                    if(val1<=1000000)
                    {
                        ll va=V[val1].order_of_key(l);
                        //cout<<va<<" ";
                        ll an=*V[val1].find_by_order(va);
                        //cout<<an<<" xxx\n";
                        if(an>=l&&an<=r)
                        {
                           // YES;
                            ans++;
                        }
                    }
                    //cout<<i+1<<" "<<l<<" "<<r<<" range\n";
//                    for(ll j=1;j<=n;j++){
//                        cout<<ar[j]<<" ";
//                    }
//                    cout<<" ses\n";
//                    cout<<i+1<<" "<<ans<<" xyyyyy\n\n";

                }

            }
        }
        cout<<"Case #"<<test<<": "<<ans<<"\n";
    }
    return 0;
}

