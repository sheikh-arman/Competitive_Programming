#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
vector<ll>for_hash1;
vector<ll>power_p;
void pow_p()
{
    ll POWER=1;
    ll P=base1,M=MOD1;
    power_p.PB(POWER);
    for(ll i=1; i<=1000000; i++)
    {
        POWER=((POWER%M)*(P%M))%M;
        power_p.push_back(POWER);
    }
}
ll hash1(string S,ll status)
{
    ll P=base1,M=MOD1;
    ll SIZ=S.size();
    ll ANS=0;
    for(ll i=0; i<SIZ; i++)
    {
        ll VAL=(ANS*P)%M;
        ANS=(((S[i]-'a'+1)%M)+(VAL%M))%M;
        if(status==0)
            for_hash1.push_back(ANS);
    }
    return ANS;
}
ll seg_hash(ll l,ll r)
{
    ll P=base1,M=MOD1;
    ll ans=for_hash1[r];
    if(l>0)
    {
        ll dif=(r-l)+1;
        ans-=(for_hash1[l-1]*power_p[dif])%M;
        ans+=M;
        ans%=M;
    }
    return ans;
}
string s;ll n;
ll ck(ll val){
    for(ll i=val-1;i<n;i++){
        ll main_str=seg_hash(i-(val-1),i);
        for(ll j=i+val;j<n;j++){
            ll new_seg=seg_hash(j-(val-1),j);
            if(new_seg==main_str){
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    pow_p();
    //freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    //cin>>tcase;
    cin>>n;
    cin>>s;
    ll tx=hash1(s,0);
    ll l=1,r=n/2;
    ll ans=0;
    while(l<=r){
        ll mid=(l+r)/2;
        if(ck(mid)){
            ans=mid;
            l=mid+1;
            //cout<<mid
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}

