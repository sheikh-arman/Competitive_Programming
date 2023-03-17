#include <bits/stdc++.h>
using namespace std;
const int nn=1e5+7;
#define ll long long 
int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n,i,j,z=0;
    	cin>>n;    	
    	ll s=0,s2=0,s3=0;
    	string a;
    	string b="FBFFBFFBFBFFBFFB";
    	cin>>a;
    	i=0;
    	if(a[0]=='B' && (n>1 && a[1]=='B')) {z=1;}
    	else if(a[0]=='B') i++;
    	for(;i<n;i++){
    		if(a[i]=='F'){
    			if(i<n-1 && a[i+1]=='B'){
    				if(s>1) {z=1;break;}
    				i++;
    				s++;
    				s2=0;
				}
				else if( i<n-1 && a[i+1]=='F'){
					if(i<n-2 && a[i+2]!='F' && s2<2){
						i+=2;
						s2++;						
					}
					else if(i>=n-2) i++;
					else {z=1;break;}
					s=0;
				}
    		}
    		else {z=1;break;}
    	}
    	if(z==0) cout<<"YES\n";
    	else cout<<"NO\n";
	}
    return 0;
}