

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

#define MAX 200010
vector<ll>prime_list;
ll cum[MAX+20];
ll ar[MAX+20];
bool prime_ck[MAX+10];
void seive()
{
    prime_ck[0]=prime_ck[1]=true;
    prime_list.push_back(2);
    for(ll i=4; i<=MAX; i+=2)
    {
        prime_ck[i]=true;
    }
    for(ll i=3; i<=MAX; i+=2)
    {
        if(prime_ck[i]==0)
        {
            prime_list.push_back(i);
            for(ll j=i*i; j<=MAX; j+=(i+i))
            {
                prime_ck[j]=1;
            }
        }
    }
}
vector<ll>V[MAX+10];
int main()
{
    seive();
    ll siz=prime_list.size();
    for(ll ii=0; ii<siz; ii++)
    {
        ll i=prime_list[ii];
        for(ll j=i; j<=MAX; j+=i)
        {
            V[j].PB(i);
        }
    }
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m,ma=0;
        cin>>n>>m;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            cum[a]++;
            ma=max(ma,a);
        }
        //cout<<cum[5]<<" x\n";


        ar[1]=n;
        for(ll i=2; i<=MAX; i++)
        {
            ll cnt=0;
            for(ll j=i; j<=MAX; j+=i)
            {
                cnt+=cum[j];
            }
            ar[i]=cnt;
        }
        for(ll i=0; i<m; i++)
        {
            ll a;
            cin>>a;
            if(a==1)
            {
                cout<<n<<"\n";
                continue;
            }
            ll siz=V[a].size();
            ll ans=n;
            for(ll i=1; i<(1<<siz); i++)
            {
                ll cnt=0,pos=0;
                ll num=i,mul=1;
                while(num)
                {
                    if(num%2)
                    {
                        ll val=V[a][pos];
                        mul=(mul*val);
                        cnt++;
                    }
                    pos++;
                    num/=2;
                    if(mul>n)continue;
                }
                if(mul>ma)continue;
                //cout<<ar[mul]<<" t\n";
                if(cnt%2)
                {
                    ans-=(ar[mul]);
                }
                else
                {
                    ans+=(ar[mul]);
                }
            }
            cout<<ans<<"\n";
        }



    }
    return 0;
}





