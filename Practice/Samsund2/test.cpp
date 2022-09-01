#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e18
double PI=2*acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
// ll dx[]={1,-1,0,0};
// ll dy[]={0,0,1,-1};
void yesNo(bool ck)
{
    cout<<(ck? "YES\n":"NO\n");
}
typedef tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//------------------------------------------------------------------------------//


const ll P=29;
const ll N=2e5+50;
const ll mod=1e9+7;

bool cmp(pair<ll,ll>& a, pair<ll,ll>& b)
{
    if(a.F==b.F) return a.S<b.S;
    return a.F<b.F;
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t=1;
    for(ll T=1; T<=t; T++)
    {
        ll n, q;
        cin>>n;
        ll factor, id;
        vector<pair<ll,ll>> v;
        for(ll i=0; i<n; i++)
        {
            cin>>factor>>id;
            v.pb({factor, id});
        }
        sort(all(v), cmp);
        vector<ll>A(n), ID(n);
        for(ll i=0; i<n; i++)
        {
            A[i]=v[i].F, ID[i]=v[i].S;
        }
        cin>>q;
        for(ll i=1; i<=q; i++)
        {
            ll val;
            cin>>val;
            ll idx=lower_bound(all(A), val)-A.begin();
            if(idx==0)
            {
                cout<<ID[idx]<<"\n";
            }
            else if(idx==n)
            {
                cout<<ID[n-1]<<"\n";
            }
            else
            {
                ll a=abs(A[idx]-val), b=abs(A[idx-1]-val);
                if(a<b)
                {
                    cout<<ID[idx]<<"\n";
                }
                else
                {
                    cout<<ID[idx-1]<<"\n";
                }
            }
        }
    }
    return 0;
}
