#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 1000000000000000000

template<typename T>
using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using min_heap=priority_queue<ll,vector<ll>,greater<ll>>;

ll n;
string a,b,c;

ll dp[101][101];
ll solve(ll l,ll r)
{
    if(l+1>r)
    {
        return 1;
    }
    if(dp[l][r]!=-1) return dp[l][r];

    ll flag=1;
    for(ll i=l; i<=r-1; i++)
    {
        ll j=i;
        if((a[j]=='X' && c[j]=='X') || b[j]=='X' || (a[j+1]=='X' && c[j+1]=='X') || b[j+1]=='X' || (a[j]=='X' && c[j+1]=='X') || (a[j+1]=='X' && c[j]=='X')) continue;
        ll chk1=solve(l,i-1);
        ll chk2=solve(i+2,r);
        //cout<<l<<" "<<i-1<<" "<<chk1<<endl;
       // cout<<i+2<<" "<<r<<" "<<chk2<<endl;
        if(chk1==chk2) flag=0;
    }
    return dp[l][r]=flag;
}

int main()
{
    freopen("1input.txt","r",stdin);
    FastIO;
    ll t,ii=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b>>c;
        memset(dp,-1,sizeof(dp));
        ll chk=solve(0,n-1);
        if(!chk) cout<<"Case "<<++ii<<": Jhinuk\n";
        else cout<<"Case "<<++ii<<": Grandma\n";

    }

}

