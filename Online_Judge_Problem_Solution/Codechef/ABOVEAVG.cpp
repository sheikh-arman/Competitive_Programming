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
ll n,x,m;
ll checking(ll pos)
{
    ll total_sum=m*n;
    ll ase=(pos*(m+1));
    if(ase>total_sum)
    {
        return 0;
    }
    else
    {
        return 1;
    }
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

        cin>>n>>x>>m;
        if(x==m)
        {
            cout<<"0\n";
        }
        else
        {
            ll left=0,right=n-1,ans=n-1;
            ll need_sum=n*m;
            while(left<=right)
            {
                ll mid=(left+right)/2;
                if(checking(mid))
                {
                    ans=mid;
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}




