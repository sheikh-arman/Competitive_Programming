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
vector<ll>V;
ll cnt;
bool Merge(ll l,ll r)
{
    ll mid=(l+r)/2,ck=1;
    if(V[l]>V[r])
    {
        cnt++;
    }
    else if(V[mid+1]>V[mid])
    {

    }
    else
    {
        ck=0;
    }
    deque<ll>A,B;
    for(ll i=l; i<=mid; i++)
    {
        A.PB(V[i]);
    }
    for(ll i=mid+1; i<=r; i++)
    {
        B.PB(V[i]);
    }
    ll cn=l;
    while(A.size()||B.size())
    {
        if(A.size()==0)
        {
            V[cn++]=B.front();
            B.pop_front();
        }
        else if(B.size()==0)
        {
            V[cn++]=A.front();
            A.pop_front();
        }
        else
        {
            if(A[0]<=B[0])
            {
                V[cn++]=A.front();
                A.pop_front();
            }
            else
            {
                V[cn++]=B.front();
                B.pop_front();
            }
        }
    }
    return ck;
}
ll merge_sort(ll l,ll r)
{
    if(l==r)return 1;
    ll a=merge_sort(l,(l+r)/2);
    ll b=merge_sort((l+r)/2+1,r);
    ll ans=a&b;
    ans&=Merge(l,r);
    return ans;
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
        ll n;
        cin>>n;
        V.clear();
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        cnt=0;
        ll ans=merge_sort(0,n-1);
        if(!ans)
        {
            cnt=-1;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}





