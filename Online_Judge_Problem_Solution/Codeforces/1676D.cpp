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
ll mem1[210][210];
ll mem2[210][210];
ll ar[210][210];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                cin>>ar[i][j];
            }
        }
        for(ll i=0; i<n; i++)
        {
            ll x=i,y=0,sum=0;
            while(x>=0&&y<m)
            {
                sum+=ar[x][y];
                x--;
                y++;
            }
            x=i;
            y=0;
            while(x>=0&&y<m)
            {
                mem1[x][y]=sum;
                x--;
                y++;
            }

            x=i;
            y=0;
            sum=0;
            while(x<n&&y<m)
            {
                sum+=ar[x][y];
                x++;
                y++;
            }
            x=i;
            y=0;
            while(x<n&&y<m)
            {
                mem2[x][y]=sum;
                x++;
                y++;
            }
        }
        for(ll j=1; j<m; j++)
        {
            ll x=n-1,y=j;
            ll sum=0;
            while(x>=0&&y<m)
            {
                sum+=ar[x][y];
                x--;
                y++;
            }
            x=n-1;
            y=j;
            while(x>=0&&y<m)
            {
                mem1[x][y]=sum;
                x--;
                y++;
            }

            x=0;
            y=j;
            sum=0;
            while(x<n&&y<m)
            {
                sum+=ar[x][y];
                x++;
                y++;
            }
            x=0;
            y=j;
            while(x<n&&y<m)
            {
                mem2[x][y]=sum;
                x++;
                y++;
            }
        }
        ll ans=0;
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                ans=max(ans,mem1[i][j]+mem2[i][j]-ar[i][j]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}




