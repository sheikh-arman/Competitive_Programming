#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e6+7;
//ll b[N],a[N];
const ll mod=1000000007 ;
ll dp[N][2];
string a;
ll fun(ll l,int x){
	if(l==0){
		if(x==0) return 1;
		return 0;
	}
	if(dp[l][x]!=-1) return dp[l][x];
	if(x==1) return dp[l][x]=(2*fun(l-1,0))%mod;
	else return  dp[l][x]=((fun(l-1,1)%mod)+(fun(l-1,0)%mod))%mod;
}
ll big_mod(ll n,ll p)
{
    if(p==0)
    {
        return 1LL;
    }
    if(p==1)
    {
        return n;
    }
    if(p%2==0)
    {
        ll tm=big_mod(n,p/2);
        ll val=((tm%mod)*(tm%mod))%mod;
        return val;
    }
    else
    {
        ll val=((big_mod(n,p-1)%mod)*(n%mod))%mod;
        return val;
    }
}
int main() {
	//freopen("1input.txt","r",stdin);
    //freopen("2output.txt","w",stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int tt=t;
    memset(dp,-1,sizeof(dp));
    while(t--){
    	cout<<"Case "<<tt-t<<": ";
    	ll n,i=0,j,s=0,s2=0,z=0,l,zz=0;
    	cin>>a;
    	n=a.length();
		
    	char c=a[0];
    	if(a[0]=='W'){
    		s=3;
    		for(i=0;i<n && a[i]=='W';i++) s2++;
	    	for(j=1;j<s2-1;j++){
	    		s*=2;
	    		s%=mod;
	    	}
	    	if(s2==n && n>1){s*=2;s%=mod;}
	    	else if(n>1){
	    		s+=(s*big_mod(3,mod-2))%mod;
				//s+=s/3;
	    		s%=mod;
	    	}
	    	if(s2==1 && n>1) s=2;
	    	s%=mod;
	    	if(i<n) c=a[i];
	    }
	    else s=1;	
    	//cout<<s<<endl;    	
    	i++;
    	l=0;
    	for(;i<n;i++){
    		if(a[i]!='W'){		
				int x=0;
				//cout<<a[i]<<" "<<c<<endl;
				if(a[i]==c) x=1;
				//cout<<l<<" "<<x<<" "<<s<<endl;
				if(l>0)s*=fun(l,x)%mod;
				s%=mod;
				c=a[i];
				l=0;
    		}
    		else l++;   		
    	}
    	//cout<<l<<" "<<s<<endl;
    	if(l>0){
    		while(l--){
    			s%=mod;
	    		s*=2;
	    		s%=mod;
    		}
    	}
        cout<<s<<"\n";
    	 
    }
    return 0;
}