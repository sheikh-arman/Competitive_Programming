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
void ck(ll n,ll k)
{
    ll num=n;
    ll ar[n+1];
    for(ll i=0; i<=n; i++)ar[i]=0;
    ll cnt=0;
    for(ll i=0; n>1; i=(i+1)%num)
    {
        if(ar[i]==0)
        {
            cnt++;
        }
        if(cnt==k)
        {
            n--;
            ar[i]=1;
            cnt=0;
        }
    }
    for(ll i=0;i<num;i++){
        if(ar[i]==0){
            cout<<i+1<<((i+1)%2?" ODD":" EVEN")<<"\n";
        }
    }
}
int main()
{

    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,k;
        cin>>n>>k;
        ck(n,k);
//        if(k==1)
//        {
//            if(n%2==0)
//            {
//                cout<<"EVEN\n";
//            }
//            else
//            {
//                cout<<"ODD\n";
//            }
//        }
//        else
//        {
//            if(n%2==0)
//            {
//                cout<<"ODD\n";
//            }
//            else
//            {
//                if(k%2==0)
//                {
//                    cout<<"ODD\n";
//                }
//                else
//                {
//                    cout<<"EVEN\n";
//                }
//            }
//        }
    }
    return 0;
}




