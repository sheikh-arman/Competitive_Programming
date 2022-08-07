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
//string str="#guess";///For Testing the interactive

char in(ll pos){
	char ch;
	cout<<"? 1 "<<pos<<"\n";
    cin>>ch;
    //ch=str[pos];
    return ch;
}
ll fre(ll l,ll r){
	ll ans;
	cout<<"? 2 "<<l<<" "<<r<<"\n";
	cin>>ans;
	//set<char>st;
	//for(int i=l;i<=r;i++){
	//	st.insert(str[i]);
	//}
	//ans=st.size();
	return ans;
}
int main()
{
	fflush(stdout);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
       // n=str.size()-1;
        string s;
        s+='#';
        ll ar[n+10];
        for(int i=0;i<=n+2;i++){
        	ar[i]=0;
        }
        s+=in(1);
        ar[1]=1;
        vector<ll>V;
        V.PB(1);
		while(1){
			ll siz=s.size();
			if(siz>n){
				break;
			}
			ll frequency=fre(1,siz);
			if(frequency>(ll)V.size()){
				s+=in(siz);
			}
			else{
				ll left=0,right=V.size()-1,pos=1;
				while(left<=right){
					ll mid=(left+right)/2;
					if(ar[V[mid]]==fre(V[mid],siz)){
						pos=mid;
						left=mid+1;
					}
					else{
						right=mid-1;
					}
				}
				s+=s[V[pos]];
			}
			V.clear();
			set<char>st;
			ll pre=0;
			for(int i=siz;i>=1;i--){
				st.insert(s[i]);
				ll si=st.size();
				if(si>pre){
					V.PB(i);
				}
				pre=si;
				ar[i]=pre;
			}
			reverse(V.begin(),V.end());
		}
		s.erase(s.begin());
		cout<<"! "<<s<<"\n";
    }
    return 0;
}



