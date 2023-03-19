<<<<<<< HEAD

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
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e7+7;
ll a[N],b[N],c[N];
void seive(){
	ll i,j;
	a[1]=1;
	for(i=2;i<N;i++) a[i]=2;
	for(i=2;i*i<N;i++){
		if(a[i]<i) continue;
		for(j=i*i;j<N;j+=i) a[j]=min(a[j],i);
	}
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    seive();
    int t;
    cin>>t;
    int l=t;
    while(t--){
    	cout<<"Case "<<l-t<<": ";
    	ll n,i,j,s=0,s2=0,gcd,x=0,y=0,s3=0;
    	cin>>n;
    	map<ll,ll>m,m2;
    	for(i=0;i<n;i++){
    		cin>>b[i];
    		if(i==0) gcd=b[i];
    		else gcd=__gcd(gcd,b[i]);
    		s=b[i];
    		while(s>1){
    			m[a[s]]++;
    			s/=a[s];
    		}
    		// m[s]++;
    	}
    	set<ll>st;
    	for(i=0;i<n;i++){
    		cin>>c[i];
			s2=__gcd(b[i],c[i]);
			s2=(b[i]*c[i])/s2;
			while(s2>1){
				if(m[a[s2]]==0){x=1;break;}
				s2/=a[s2];
			}
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
    }
    return 0;
}