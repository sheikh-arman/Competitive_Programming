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
ll cum[20010];
ll difference1[20010];
ll difference2[20010];
ll ar[20010];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    // cin>>tcase;

    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        ll sum=0;
        for(ll i=1; i<=n; i++)
        {
            cin>>ar[i];
            sum+=ar[i];
            cum[i]=sum;
        }
        sum=0;
        for(ll i=1; i<n; i++)
        {
            if(i%2!=0)
            {
                sum+=ar[i]-ar[i+1];
                difference1[i]=sum;
            }
            else
            {
                difference1[i]=sum;
            }
        }
        difference1[n]=sum;
        sum=0;
        for(ll i=2; i<n; i++)
        {
            if(i%2==0)
            {
                sum+=ar[i]-ar[i+1];
                difference2[i]=sum;
            }
            else
            {
                difference2[i]=difference2[i-1];
            }
        }
        difference2[n]=sum;
        ll q;
        cin>>q;
        for(ll i=0; i<q; i++)
        {
            ll l,r;
            cin>>l>>r;
            if(l>r)swap(l,r);
            ll dif=(r-l)+1;
            if(dif%2==0)
            {
                if(l%2!=0)
                {
                    cout<<difference1[r]-difference1[l-1]<<"\n";
                }
                else
                {
                    cout<<difference2[r]-difference2[l-1]<<"\n";
                }
            }
            else
            {
                cout<<cum[r]-cum[l-1]<<"\n";
            }
        }




    }
    return 0;
}





