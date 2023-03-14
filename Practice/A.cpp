#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int nn=2e5+7;
ll a[nn];
vector<int>v;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){    	
	    ll n,k,d,w,i,j=1,s=1,s2=0,z=0,s3=0;
	    cin>>n>>k>>d>>w;
	    for(i=0;i<n;i++)cin>>a[i];
	    sort(a,a+n);
	    ll x=min(a[0]+w,a[n-1]),y=0;
	    for(i=0;i<n-1;i++){
	    	if(a[i]<=x) {y++;a[i]=x;}
	    	else{
	    		if(a[i]-x>d || (y+1)%k==1){
		    		x=min(a[i]+w,a[n-1]);
		    		a[i]=x;
		    		y=1;
	    		}
	    		else y++;
	    	}
	    }
	    s2=d+a[0];s3=0;s=1;
	    for(i=0;i<n;i++){
	    	s3++;
	    	if(s3>k){
	    		s++;
	    		s2=a[i]+d;
	    		s3=1;
	    	}
	    	else if(a[i]>s2){
	    		s++;
	    		s2=a[i]+d;	
	    		s3=1;    		
	    	}
	    }
	    cout<<s<<endl;
    }
	return 0;
}
			