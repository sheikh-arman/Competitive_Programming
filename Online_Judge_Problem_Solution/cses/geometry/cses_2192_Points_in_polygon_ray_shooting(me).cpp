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
ll area(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3)
{
    ll ans=x1*(y2-y3);
    ans+=x2*(y3-y1);
    ans+=x3*(y1-y2);
    //ans=abs(ans);
    return ans;
}
vector<ll>V1,V2;
ll n,m;
ll boundary(ll x,ll y)
{
    for(ll i=1; i<=n; i++)
    {
        ll tm=area(x,y,V1[i-1],V2[i-1],V1[i%n],V2[i%n]);
        // cout<<tm<<" "<<x<<" "<<y<<" "<<V1[i-1]<<" "<<V2[i-1]<<" "<<V1[i%n]<<" "<<V2[i%n]<<" x\n";
        if(tm==0&&(abs(x-V1[i-1])+abs(x-V1[i%n])==abs(V1[i-1]-V1[i%n]))&&(abs(y-V2[i-1])+abs(y-V2[i%n])==abs(V2[i-1]-V2[i%n])))return 1;
    }
    return 0;
}
ll checking(ll tm,ll tm2)
{
    return ((tm<0&&tm2<0)||(tm>0&&tm2>0))^1;
}
int main()
{
    // cout<<area(1,1,1,1,2,2);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>n>>m;
        for(ll i=0; i<n; i++)
        {
            ll x,y;
            cin>>x>>y;
            V1.PB(x);
            V2.PB(y);
        }

        for(ll i=0; i<m; i++)
        {
            ll x,y;
            cin>>x>>y;
            if(boundary(x,y))
            {
                cout<<"BOUNDARY\n";
            }
            else
            {
                ll pointx=1e9+500,pointy=1e9+100;
                while(1)
                {
                    ll ck=1;
                    for(ll j=0; j<n&&ck; j++)
                    {
                        ll tm=area(x,y,pointx,pointy,V1[j],V2[j]);
                        if(tm==0)ck=0;
                    }
                    if(ck)break;
                    pointy++;
                    //pointx++;
                }
                ll cnt=0;
                for(ll j=1; j<=n; j++)
                {
                    ll tm=area(x,y,pointx,pointy,V1[j%n],V2[j%n]);
                    ll tm2=area(x,y,pointx,pointy,V1[j-1],V2[j-1]);
                    ll tm3=area(V1[j%n],V2[j%n],V1[j-1],V2[j-1],x,y);
                    ll tm4=area(V1[j%n],V2[j%n],V1[j-1],V2[j-1],pointx,pointy);
                    if(checking(tm,tm2)&&checking(tm3,tm4))cnt++;
                }
                if(cnt&1)
                {
                    cout<<"INSIDE\n";
                }
                else
                {
                    cout<<"OUTSIDE\n";
                }
            }
        }
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}







