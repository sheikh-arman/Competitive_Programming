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
//ll ar[]={0,4,2,5,1,3};
ll ar[]={0,9,8,7,6,5,1,2,3,4};
ll sol(ll l,ll r){
	cout<<"? "<<l<<" "<<r<<"\n";
	//cout<<l<<" "<<r<<" hi\n";
    vector<ll>V;
    ll ck=0;
    for(ll i=l;i<=r;i++){
        ll a;
        cin>>a;
        V.PB(a);
        //V.PB(ar[i]);
    }
    ll cnt_in=0;
    ll n=V.size();
    for(ll i=0;i<n;i++){
    	if(V[i]>=l&&V[i]<=r){
    		cnt_in++;
    	}
    	//cout<<V[i]<<" ";
    }
    //cout<<" x\n";
    if(cnt_in%2==0){
    	ck=-1;
    }
    //cout<<ck<<" t\n";
	return ck;
}
int main()
{
	fflush(stdout);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    // /fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;;
        cin>>n;
        ll left=1,right=n;
        while(left<right){
        	//if(left==right)break;
        	ll mid=(left+right)/2;
        	ll ck=sol(left,mid);
        	if(ck!=-1){
        		right=mid;
        	}
        	else{
        		left=mid+1;
        	}
        }
        cout<<"! "<<left<<"\n";
    }
    return 0;
}




