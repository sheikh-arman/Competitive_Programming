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
// ll X[] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[] = {1, 2, 2, 1, -1, -2, -2, -1};
//8 direction
// ll dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// ll dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//4 direction
// ll dx[]={1, -1, 0, 0};
// ll dy[]={0, 0, 1, -1};
void yesNo(bool ck)
{
    cout<<(ck? "YES\n":"NO\n");
}
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//------------------------------------------------------------------------------//


const ll P=29;
const ll N=5e5+50;
const ll mod=1e9+7;

vector<ll>lps(4*N);
void prefix_function(vector<ll>& text, ll len)
{
    ll j;
    for(ll i=1; i<len; i++)
    {
        j=lps[i-1];
        while(j>0 and text[i]!=text[j])
        {
            j=lps[j-1];
        }
        if(text[i]==text[j])
        {
            j++;
        }
        lps[i]=j;
    }
}

int main()
{

    //freopen("input/A1/input.txt", "r", stdin);
    //freopen("input/A1/outputFile.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t=1;
    cin>>t;
    for(ll T=1; T<=t; T++)
    {
        ll n, k;
        cin>>n>>k;
        string a, b;
        vector<ll> A(n), B(n);
        for(ll i=0; i<n; i++)
        {
            cin>>A[i];
        }
        for(ll i=0; i<n; i++)
        {
            cin>>B[i];
        }

        bool allSame=1;
        for(ll i=0; i<(n-1); i++)
        {
            if(B[i]!=B[i+1])
            {
                allSame=0;
                break;
            }
        }
        if(allSame)
        {
            cout<<"Case #"<<T<<": YES\n";
            continue;
        }

        ll idx=0;
        vector<ll> v(4*n);
        for(ll i=0; i<n; i++)
        {
            v[idx++]=B[i];
        }
        v[idx++]=-1;
        for(ll i=0; i<n; i++)
        {
            v[idx++]=A[i];
        }
        for(ll i=0; i<n; i++)
        {
            v[idx++]=A[i];
        }

        prefix_function(v, idx);

        // for(ll i=0; i<idx; i++){
        //   cout<<v[i]<<" ";
        // }cout<<"\n";
        // for(ll i=0; i<idx; i++){
        //   cout<<lps[i]<<" ";
        // }cout<<"\n";

        bool isZero=0;
        ll match=0, len=idx;
        for(ll i=0; i<len; i++)
        {
            if(lps[i]==n)
            {
                ll pos=i-(2*n);
                if(pos==0)
                {
                    isZero=1;
                }
                match++;
            }
        }
        //cout<<match<<" match\n";
        cout<<"Case #"<<T<<": ";
        if(match>0)
        {
            if(match==2 and isZero==1)
            {
                if(n==2 and k%2==1)
                {
                    cout<<"NO\n";
                }
                else if(k==1)
                {
                    cout<<"NO\n";
                }
                else
                {
                    cout<<"YES\n";
                }
            }
            else
            {
                if(isZero==0 and k==0)
                {
                    cout<<"NO\n";
                }
                else if(n==2 and isZero==0 and k%2==0)
                {
                    cout<<"NO\n";
                }
                else
                {
                    cout<<"YES\n";
                }
            }
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
