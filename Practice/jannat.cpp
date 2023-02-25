#include <bits/stdc++.h>
using namespace std;
const int nn=1e6+2;
int main() {
	//ios::sync_with_stdio(false);
    //cin.tie(NULL);
    string a;
    while(cin>>a){
    	int l=a.length(),i,k,j,s=0,s2=0;
    	long long b[l]={0};
    	if(l==1) cout<<"0\n";
    	else{
    		s=(l+1)/2;
	    	for(i=0;i<s;i++){
	    		if(a[i]!=a[l-i-1]){
	    			if(a[i]<a[l-1-i]) b[l-1-i]=26-(a[l-i-1]-a[i]);
	    			else b[l-i-1]=a[i]-a[l-i-1];
	    			//cout<<b[i]<<" ";
	    		}
	    	}
	    	s2=b[s];
	    	for(i=s+1;i<l;i++){
	    		if(b[i]<s2 ) s2+=26-(s2%26)+b[i];
	    		else s2+=(b[i]-s2);		
	    	}
    		cout<<s2<<"\n";
		}
	}
	return 0;
}