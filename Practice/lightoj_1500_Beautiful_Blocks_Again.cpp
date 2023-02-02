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
vector<pair<ll,ll>>V;
vector<ll>V2,ans;
ll ar[1000010];
bitset<1000010>color;
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        V.clear();
        V2.clear();
        ans.clear();
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<n*m;i++){
            ar[i]=0;
            color[i]=0;
        }
        for(ll i=0;i<n*m;i++){
            ll a;
            cin>>a;
            V.PB({a,i});
            V2.PB(a);
        }
        VST(V);
        reverse(V.begin(),V.end());
        ll sum=0;
        for(ll i=0;i<n+m-1;i++){
            sum+=V[i].first;
            color[V[i].second]=1;
        }
        ll left=1,right=m,toggle=1;
        for(ll i=0;i<n*m;i++){
            if(toggle){
                if(ar[i]==1){
                    if(right>left){
                        ans.PB(right);
                        ar[i]++;
                        right--;
                    } 
                    if(right<=left){
                        toggle=0;
                        left=m;
                    }
                }
                else{
                    if(ar[left]<n-1){
                        ar[left]++;
                        ans.PB(left);
                    }
                    else{
                        left++;
                        if(left>right){
                            toggle=0;
                            left=m;
                        }
                        else{
                            ar[left]++;
                            ans.PB(left);
                        }
                    }
                }
            }
            else{
                
            }
        }
    }
    return 0;
}





