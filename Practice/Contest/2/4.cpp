#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
/// Hashing OK
ll hashCnt=1;
ll base[]= {129,137};
ll mod[]= {1479386893,1928476349};
vector<ll>hashing[3];
vector<ll>hash_power[3];
void power()
{
    for(ll i=0; i<hashCnt; i++)
    {
        ll POWER=1;
        for(ll j=0; j<MAX; j++)
        {
            hash_power[i].PB(POWER);
            POWER*=base[0];
            if(POWER>mod[0])
                POWER%=mod[0];
        }
    }
}
ll hash_func(string s,ll hashNo)
{
    hashNo=0;
    ll n=s.size();
    ll hash_val=0;
    for(ll i=0; i<n; i++)
    {
        hash_val=((hash_val*base[hashNo]))+(s[i]-'A'+1);
        if(hash_val>mod[hashNo])
            hash_val%=mod[hashNo];
        //hashing[hashNo].PB(hash_val);
    }
    return hash_val;
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
ll mod2=1e9+7;
char str[1000010];
int main()
{
    power();
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    //cin>>tcase;
    scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        unordered_map<ll,ll>mp,mp2;
        vector<string>V1,V2;
        vector<ll>V1_val,V2_val;
        //cin>>n>>m;
        scanf("%lld%lld",&n,&m);
        for(ll i=0; i<n; i++)
        {
            string s;
            scanf("%s",str);
            for(ll j=0; str[j]!='\0'; j++)
            {
                s+=str[j];
            }
            ll val=hash_func(s,0);
            mp[val]++;
            V1.PB(s);
            V1_val.PB(val);
        }
        set<ll>st;
        for(ll j=0; j<m; j++)
        {
            string s;
            scanf("%s",str);
            for(ll j=0; str[j]!='\0'; j++)
            {
                s+=str[j];
            }
            ll val=hash_func(s,0);
            mp2[val]++;
            st.insert(val);
            V2.PB(s);
            V2_val.PB(val);
        }
        ll ans=0;
        for(auto i:st)
        {
            ans+=(mp[i]*mp2[i]);
            if(ans>mod2)
                ans%=mod2;
        }
        ll q;
        scanf("%lld",&q);
        for(ll i=0; i<q; i++)
        {
            ll a,b,c;
            char s;
            scanf("%lld %lld %lld %c",&a,&b,&c,&s);
            b--;
            c--;
            ll temp=0;
            if(a==1)
            {
                if(V1[b][c]==s)
                {
                    cout<<ans<<"\n";
                    continue;
                }
                string head=V1[b];
                ll val=V1_val[b];
                temp=mp[val]*mp2[val];
                ans-=temp;
                if(ans<0)
                {
                    ans+=mod2;
                }
                if(ans>mod2)
                    ans%=mod2;
                mp[val]--;
                ans+=mp[val]*mp2[val];
                if(ans<0)
                {
                    ans+=mod2;
                }
                if(ans>mod2)
                    ans%=mod2;
                V1[b][c]=s;
                head[c]=s;
                val=hash_func(head,0);
                V1_val[b]=val;
                temp=mp[val]*mp2[val];
                ans-=temp;
                if(ans<0)
                {
                    ans+=mod2;
                }
                if(ans>mod2)
                    ans%=mod2;
                mp[val]++;
                ans+=mp[val]*mp2[val];
                if(ans<0)
                {
                    ans+=mod2;
                }
                if(ans>mod2)
                    ans%=mod2;
            }
            else
            {
                if(V2[b][c]==s)
                {
                    cout<<ans<<"\n";
                    continue;
                }
                string head=V2[b];
                ll val=V2_val[b];
                temp=mp[val]*mp2[val];
                ans-=temp;
                if(ans<0)
                {
                    ans+=mod2;
                }
                if(ans>mod2)
                    ans%=mod2;
                mp2[val]--;
                ans+=mp[val]*mp2[val];
                if(ans<0)
                {
                    ans+=mod2;
                }
                if(ans>mod2)
                    ans%=mod2;
                V2[b][c]=s;
                head[c]=s;
                val=hash_func(head,0);
                temp=mp[val]*mp2[val];
                V2_val[b]=val;
                ans-=temp;
                if(ans<0)
                {
                    ans+=mod2;
                }
                if(ans>mod2)
                    ans%=mod2;
                mp2[val]++;
                ans+=mp[val]*mp2[val];
                if(ans<0)
                {
                    ans+=mod2;
                }
                if(ans>mod2)
                    ans%=mod2;
            }
            if(ans<0)
            {
                ans+=mod2;
            }
            if(ans>mod2)
                ans%=mod2;
            printf("%lld\n",ans);
        }
    }
    return 0;
}


