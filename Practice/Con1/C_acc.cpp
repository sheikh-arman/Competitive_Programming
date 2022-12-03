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
ll ar[310][310];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m,rot;
        cin>>n>>m>>rot;
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                cin>>ar[i][j];
            }
        }
        deque<ll>V;
        ll cnt=0;
        ll ma=min(n,m)/2;
        while(cnt<ma)
        {
            V.clear();
            for(ll i=cnt; i<n-cnt; i++)
            {
                V.PB(ar[i][cnt]);
            }
            for(ll i=cnt+1; i<m-cnt; i++)
            {
                V.PB(ar[(n-cnt)-1][i]);
            }
            for(ll i=((n-cnt)-1)-1; i>=cnt; i--)
            {
                V.PB(ar[i][(m-cnt)-1]);
            }
            for(ll i=(m-cnt-1)-1; i>=(cnt+1); i--)
            {
                V.PB(ar[cnt][i]);
            }
            ll siz=V.size();
            ll tm_tot=rot%siz;
            while(tm_tot--)
            {
                V.push_front(V[siz-1]);
                V.pop_back();
            }
            ll current=0;
            for(ll i=cnt; i<n-cnt; i++)
            {
                ar[i][cnt]=V[current++];
            }
            for(ll i=cnt+1; i<m-cnt; i++)
            {
                ar[(n-cnt)-1][i]=V[current++];;
            }
            for(ll i=((n-cnt)-1)-1; i>=cnt; i--)
            {
                ar[i][(m-cnt)-1]=V[current++];;
            }
            for(ll i=(m-cnt-1)-1; i>=(cnt+1); i--)
            {
                ar[cnt][i]=V[current++];;
            }
            cnt++;
        }
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                if(j>0)cout<<" ";
                cout<<ar[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}





