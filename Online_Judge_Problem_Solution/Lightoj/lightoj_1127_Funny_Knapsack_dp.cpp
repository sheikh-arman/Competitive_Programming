/*
    Sk arman Hossain
    University of Barisal

    Problem : lightoj 1127
    Solution : dp
 */

#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll n,w;
vector<ll>V1,V2,pre,sup;
ll dp(ll pos,ll sum,ll siz,ll ck)
{
    if(sum>w)
    {
        return 0;
    }
    if(pos>=siz)
    {
        if(ck==0)
        {
            pre.PB(sum);
        }
        else
        {
            sup.PB(sum);
        }
        return 0;
    }
    ll x=0;
    if(ck==0)
    {
        x=dp(pos+1,sum+V1[pos],siz,ck);
        x=dp(pos+1,sum,siz,ck);
    }
    else
    {
        x=dp(pos+1,sum+V2[pos],siz,ck);
        x=dp(pos+1,sum,siz,ck);
    }
    return x;
}
int main()
{
	//freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        pre.clear();
        sup.clear();
        V1.clear();
        V2.clear();
        ll n;
        cin>>n>>w;
        vector<ll>V;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        ll mid=n/2;
        for(ll i=0; i<mid; i++)
        {
            V1.PB(V[i]);
        }
        for(ll i=mid; i<n; i++)
        {
            V2.PB(V[i]);
        }
		ll x=dp(0,0,mid,0);
		ll siz=V2.size();
		x=dp(0,0,siz,1);
		ll ans=0;
		sort(sup.begin(),sup.end());
		siz=pre.size();
		for(ll i=0;i<siz;i++){
			ll pos=upper_bound(sup.begin(),sup.end(),(w-pre[i]))-sup.begin();
			ans+=pos;
		}
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
    return 0;
}

