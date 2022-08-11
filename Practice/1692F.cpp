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
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        ll ar[12];
        for(ll i=0;i<11;i++){
        	ar[i]=0;
        }
        for(ll i=0;i<n;i++){
        	ll a;
        	cin>>a;
        	ar[a%10]++;
        }
        vector<ll>V;
        for(ll i=0;i<10;i++){
        	ll cnt=min(3LL,ar[i]);
        	for(ll j=0;j<cnt;j++){
        		V.PB(i);
        	}
        }
        ll ck=0;
        ll siz=V.size();
        if(siz>2){
        	for(ll i=0;i<siz-2&&ck==0;i++){
        		for(ll j=i+1;j<siz-1&&ck==0;j++){
        			for(ll k=j+1;k<siz;k++){
        				ll sum=V[i]+V[j]+V[k];
        				if(sum%10==3){
        					ck=1;break;
        				}
        			}
        		}
        	}
        }
        if(ck){
        	YES;
        }
        else{
        	NO;
        }



    }
    return 0;
}




