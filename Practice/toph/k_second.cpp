#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll hashCnt=2;
ll base[]= {129,137,31,29};
ll mod[]= {1479386893,1928476349,1000000007,1000000009};
vector<ll>hashing[5];
vector<ll>hash_power[5];
void power(ll hashNo)
{
    ll POWER=1;
    for(ll j=0; j<5010; j++)
    {
        hash_power[hashNo].PB(POWER);
        POWER*=base[hashNo];
        POWER%=mod[hashNo];
    }
}
void hash_func(string s,ll hashNo)
{
    ll n=s.size();
    ll hash_val=0;
    for(ll i=0; i<n; i++)
    {
        hash_val=((hash_val*base[hashNo])%mod[hashNo])+(s[i]-'A'+1);
        hash_val%=mod[hashNo];
        hashing[hashNo].PB(hash_val);
    }
}
ll seg_hash(ll l,ll r,ll hashNo)
{
    ll hash_val=hashing[hashNo][r];
    if(l>0)
    {
        ll dif=(r-l)+1;
        hash_val-=(hashing[hashNo][l-1]*hash_power[hashNo][dif])%mod[hashNo];
        hash_val+=mod[hashNo];
        hash_val%=mod[hashNo];
    }
    return hash_val;
}
string s;ll n;
ll ck(ll val){
    for(ll i=val-1;i<n;i++){
        ll main_str=seg_hash(i-(val-1),i,0);
        ll main_str2=seg_hash(i-(val-1),i,1);
        for(ll j=i+val;j<n;j++){
            ll new_seg=seg_hash(j-(val-1),j,0);
            ll new_seg2=seg_hash(j-(val-1),j,1);
            if(new_seg==main_str&&new_seg2==main_str2){
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    power(0);
    power(1);
    //freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    //cin>>tcase;
    cin>>n;
    cin>>s;
    hash_func(s,0);
    hash_func(s,1);
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

