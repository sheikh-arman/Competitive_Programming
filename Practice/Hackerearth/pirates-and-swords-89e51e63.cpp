#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
vector<ll>price;
vector<ll>cost;
ll n,m,d;
ll checking(ll mid)
{
    ll tm_d=d,ck=1,j=0;
    for(ll i=mid; i>=0&&j<n; i--)
    {
        if(j<n&&price[j]+tm_d>=cost[i])
        {
            ll mi=min(cost[i],price[j]);
            ll dif=cost[i]-mi;
            if(dif>0)
            {
                tm_d-=dif;
            }
            j++;
        }
        else
        {
            ck=0;
            break;
        }
    }
    //cout<<mid<<" "<<ck<<" x\n";
    return ck;
}
int main()
{
    // freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    // cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {

        cin>>n>>m>>d;

        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            price.PB(a);
        }
        for(ll i=0; i<m; i++)
        {
            ll a;
            cin>>a;
            cost.PB(a);
        }
        VST(price);
        reverse(price.begin(),price.end());
        VST(cost);
        ll mi=n;
        ll left=0,right=m-1;
        while(left<=right)
        {
            ll mid=(left+right)/2;
            if(checking(mid))
            {
                mi=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        ll res=0;
        for(ll i=0; i<=mi; i++)
        {
            res+=cost[i];
        }
        ll ma_cost=max(res-d,0LL);
        cout<<mi+1<<" "<<ma_cost<<"\n";
    }
    return 0;
}




