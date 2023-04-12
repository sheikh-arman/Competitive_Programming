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
ll n,m;
ll fix_x=8,fix_y=2;
ll query(ll i,ll j)
{
    cout<<"? "<<i<<" "<<j<<"\n";
    ll x;
    cin>>x;
    return x+1;
    //return max(abs(fix_x-i),abs(fix_y-j))+1;
}
int main()
{
    // cout<<"hjg\n";
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    cout.flush();
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>n>>m;
        ll dis1=query(1,1);
        if(dis1-1==0)
        {
            cout<<"! 1 1\n";
            continue;
        }
        ll dis2=query(n,1);
        if(dis2-1==0)
        {
            cout<<"! "<<n<<" 1\n";
            continue;
        }
        ll x=min(dis1,n),y=min(dis1,m);
        ll new_x=min(n,max(1LL,(n+1)-dis2)),new_y=min(dis2,m);
        if(x==new_x&&y==new_y)
        {
            cout<<"! "<<x<<" "<<y<<"\n";
            continue;
        }
        //cout<<x<<" "<<y<<" "<<new_x<<" "<<new_y<<" x\n";
        if(x==new_x)
        {
            dis1=min(query(x,1),m);
            cout<<"! "<<x<<" "<<dis1<<"\n";
            continue;

        }
        else if(y==new_y)
        {
            dis1=min(query(1,y),n);
            cout<<"! "<<dis1<<" "<<y<<"\n";
            continue;
        }
        else
        {
            assert(false);
        }
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}





