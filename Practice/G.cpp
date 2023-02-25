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
        ll n,sum=0;
        cin>>n;

        ll a[n+1],r[n+1],mx=0,id=0;
        a[0]=0;
        r[0]=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            r[i]=a[i];
            a[i]+=a[i-1];
            if(a[i]>mx){
                mx=a[i];
                id=i;
            }
        }

        ll ans[n+1],c[n+1];
        ans[id]=n+1;
        //cout<<id<<endl;
        for(ll i=id+1;i<=n;i++){
            ans[i]=ans[i-1]+r[i];
        }
        for(ll i=id-1;i>=0;i--){
            ans[i]=ans[i+1]-r[i+1];
        }

        for(ll i=0;i<=n;i++){
            c[i]=ans[i];
            //cout<<c[i]<<" ";
        }//cout<<endl;
        ll chk=0;
        sort(c,c+n+1);
        for(ll i=0;i<=n;i++) if(c[i]!=i+1) chk=1;
        if(chk){
            cout<<-1<<endl;
            continue;
        }

        for(ll i=0;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;

    }
    return 0;
}





