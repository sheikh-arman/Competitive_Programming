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
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll>V,V2;
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            V.PB(a);
        }
        for(ll i=0;i<n;i++){
            ll cnt=1;
            ll j=i+1;
            while(j<n){
                if(V[j]==V[i]){
                    j++;
                    cnt++;
                }
                else{
                    break;
                }
            }
            i=j-1;
            V2.PB(cnt);
        }
        if((ll)V2.size()>k){
            cout<<"1\n";
            for(ll i=1;i<=k-1;i++){
                cout<<i<<" "<<i<<"\n";
            }
            cout<<k<<" "<<n<<"\n";
        }
        else{
            cout<<"0\n";
            ll siz=V2.size();
            ll cnt=1;
            V.clear();
            for(ll j=0;j<siz;j++){
                //cout<<j<<" "<<V2[j]<<" x\n";
                ll val=V2[j];
                ll ck=0;
                while(val){
                    ll baki=(siz-j)-1;
                    if(baki+1+(ll)V.size()==k){
                        ck=1;
                        break;
                    }
                    else{
                        V.PB(1);
                        val--;
                    }
                }
                V2[j]=val;
                if(ck)break;
            }
            for(ll j=0;j<siz;j++){
                if(V2[j])V.PB(V2[j]);
            }
            for(ll i:V){
                //cout<<i<<" tt\n";
                cout<<cnt<<" "<<cnt+(i-1)<<"\n";
                cnt+=i;
            }
        }
    }
    return 0;
}





