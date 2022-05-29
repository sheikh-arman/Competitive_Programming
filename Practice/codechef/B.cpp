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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> policy_set;

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
vector<ll>prime_list;
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
int main()
{
    seive();
    //for(ll i=0;i<10;i++)cout<<prime_list[i]<<" \n";
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        vector<ll>V;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        ll gcd=V[0];
        for(ll i=1; i<n; i++)
        {
            gcd=__gcd(min(gcd,V[i]),max(gcd,V[i]));
        }
        n=gcd;
        ll sq=sqrt(n+1);
        vector<ll>ans;
        ll siz=prime_list.size();
        for(ll i=0;; i++)
        {
            if(prime_list[i]*prime_list[i]>n||i>=siz)
            {
                break;
            }
            if(n%prime_list[i]==0)
            {
                ans.PB(prime_list[i]);
                while(n%prime_list[i]==0)
                {
                    n/=prime_list[i];
                }
            }
        }
        if(n>1)
        {
            ans.PB(n);
        }
        if((ll)ans.size()==0){
            cout<<"-1\n";continue;
        }
        VST(ans);
        ll ck=1;
        for(ll i:ans)
        {
            if(ck==0)
            {
                cout<<" ";
            }
            cout<<i;
            ck=0;
        }
        cout<<"\n";





    }
    return 0;
}




