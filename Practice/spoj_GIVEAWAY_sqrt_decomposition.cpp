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
#define N 1000010
ordered_set block[800];
ll ar[N],len;
void sqrt_decompose(ll n)
{
    len = (ll) sqrt (n) + 1;
    ll siz=n/len;
    for(int i=0; i<=siz; i++)block[i].clear();
    for (int i=0; i<n; ++i)
    {
        block[i / len].insert(ar[i]);
    }
}
ll sqrt_query(ll l,ll r,ll val)
{
    ll sum = 0;
    int c_l = l / len,   c_r = r / len;
    if (c_l == c_r)
    {
        for (int i=l; i<=r; ++i)
        {
            if(ar[i]>=val)sum++;
        }
    }
    else
    {
        for (int i=(c_l*len)+len-1; i>=l; i--)
        {
            if(ar[i]>=val)sum++;
        }
        for (int i=c_l+1; i<c_r; i++)
        {
            ll res=block[i].order_of_key(val);
            sum+=(block[i].size()-res);
        }
        for (int i=c_r*len; i<=r; i++)
        {
            if(ar[i]>=val)sum++;
        }
    }
    return sum;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    // cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,sum=0;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            cin>>ar[i];
        }
        sqrt_decompose(n);
        ll q;
        cin>>q;
        for(ll i=0; i<q; i++)
        {
            ll a;
            cin>>a;
            if(a==0)
            {
                ll l,r,val;
                cin>>l>>r>>val;
                if(l>r)swap(l,r);
                l--;
                r--;
                sum=sqrt_query(l,r,val);
                cout<<sum<<"\n";
            }
            else
            {
                ll pos,val;
                cin>>pos>>val;
                pos--;
                ll blck=pos/len;
                ll new_pos=block[blck].order_of_key(ar[pos]);
                block[blck].erase(block[blck].find_by_order(new_pos));
                ar[pos]=val;
                block[blck].insert(ar[pos]);
            }
        }
    }
    return 0;
}
