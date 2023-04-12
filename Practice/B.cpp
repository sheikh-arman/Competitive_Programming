<<<<<<< HEAD
=======
<<<<<<< HEAD

>>>>>>> ff4db7232ca74ce032463fd026d48ebdc0400ab5
/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
    Date:
 */

<<<<<<< HEAD
=======
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
   // cout<<"hjg\n";
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
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            V.PB(a);
        }
        VST(V);
        ll sum=V[0],ck=1;
        for(ll i=1;i<n;i++){
            if(V[i]>sum){
                ck=0;break;
            }
            sum+=V[i];
        }
        if(ck&&V[0]==1){
            YES;
        }
        else{
            NO;
        }
=======
>>>>>>> ff4db7232ca74ce032463fd026d48ebdc0400ab5
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
ll ar[3][200010];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,cnt=1;
        cin>>n;
		for(ll i=0;i<n;i+=2){
			ar[1][i]=cnt;
			ar[0][i+1]=cnt+1;
			cnt+=2;
		}
		for(ll i=n-3;i>=0;i-=2){
			ar[1][i]=cnt;
			ar[0][i+1]=cnt+1;
			cnt+=2;
		}
		ar[1][n-1]=cnt++;
		ar[0][0]=cnt;
		for(ll i=0;i<2;i++){
			for(ll j=0;j<n;j++){
				cout<<ar[i][j]<<" ";
			}
<<<<<<< HEAD
			cout<<"\n";
		}
=======
			//cout<<s2<<"  "<<a[s2]<<endl;
			//if(m[s2]==0) x=1;
			if(b[i]>c[i] && y==0){
				if(b[i]%c[i]) y=1;
				else st.insert(b[i]/c[i]);
				s3=b[i]/c[i];
			}
			else if(b[i]<=c[i] && y==0){
				if(c[i]%b[i]) y=1;
				else st.insert(c[i]/b[i]);
				s3=c[i]/b[i];    				
			}
    	}
    	if(x==0) cout<<"Yes ";
    	else cout<<"No ";
    	if(y==0 ){
    		if(st.size()==0) cout<<"Yes\n";
    		else if (st.size()==1 && gcd%s3==0)cout<<"Yes\n";
    		else cout<<"No\n";
    	}
    	else cout<<"No\n";
>>>>>>> 53f1cd93ed3d250b28360b312ec0e3e7a40bad68
>>>>>>> ff4db7232ca74ce032463fd026d48ebdc0400ab5
    }
    return 0;
 ///*****************************  ALHAMDULILLAH  *****************************/
}





