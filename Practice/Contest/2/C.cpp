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
ll mod=1e9+7;
char str[1000010];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    //cin>>tcase;
    scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        unordered_map<string,ll>mp,mp2;
        vector<string>V1,V2;
        //cin>>n>>m;
        scanf("%lld%lld",&n,&m);
        for(ll i=0; i<n; i++)
        {
            //char s;
            string s;
            //cin>>s;
            // char str[1000010];
            scanf("%s",str);
            for(ll j=0; str[j]!='\0'; j++)
            {
                s+=str[j];
            }
            mp[s]++;
            V1.PB(s);
        }
        set<string>st;
        for(ll j=0; j<m; j++)
        {
            string s;
            //cin>>s;
            //char str[1000010];
            scanf("%s",str);
            for(ll j=0; str[j]!='\0'; j++)
            {
                s+=str[j];
            }

            mp2[s]++;
            st.insert(s);
            V2.PB(s);
        }
        ll ans=0;
        for(auto i:st)
        {
            ans+=(mp[i]*mp2[i]);
            if(ans>mod)
                ans%=mod;
        }
        ll q;
        //cin>>q;
        scanf("%lld",&q);
        for(ll i=0; i<q; i++)
        {
            ll a,b,c;
            char s;
            //cin>>a>>b>>c>>s;
            scanf("%lld %lld %lld %c",&a,&b,&c,&s);
            b--;
            c--;
            ll temp=0;
            if(a==1)
            {
                string head=V1[b];
                temp=mp[head]*mp2[head];
                ans-=temp;
                if(ans<0)
                {
                    ans+=mod;
                }
                if(ans>mod)
                    ans%=mod;
                mp[head]--;
                ans+=mp[head]*mp2[head];
                if(ans<0)
                {
                    ans+=mod;
                }
                if(ans>mod)
                    ans%=mod;
                V1[b][c]=s;
                head=V1[b];
                temp=mp[head]*mp2[head];
                ans-=temp;
                if(ans<0)
                {
                    ans+=mod;
                }
                if(ans>mod)
                    ans%=mod;
                mp[head]++;
                ans+=mp[head]*mp2[head];
                if(ans<0)
                {
                    ans+=mod;
                }
                if(ans>mod)
                    ans%=mod;
            }
            else
            {
                string head=V2[b];
                temp=mp[head]*mp2[head];
                ans-=temp;
                if(ans<0)
                {
                    ans+=mod;
                }
                if(ans>mod)
                    ans%=mod;
                mp2[head]--;
                ans+=mp[head]*mp2[head];
                if(ans<0)
                {
                    ans+=mod;
                }
                if(ans>mod)
                    ans%=mod;
                V2[b][c]=s;

                head=V2[b];
                temp=mp[head]*mp2[head];
                ans-=temp;
                if(ans<0)
                {
                    ans+=mod;
                }
                if(ans>mod)
                    ans%=mod;
                mp2[head]++;
                ans+=mp[head]*mp2[head];
                if(ans<0)
                {
                    ans+=mod;
                }
                if(ans>mod)
                    ans%=mod;
            }
            //cout<<ans<<"\n";
            if(ans<0)
            {
                ans+=mod;
            }
            if(ans>mod)
                ans%=mod;
            printf("%lld\n",ans);
        }


        // cout<<ans<<"\n";
    }
    return 0;
}




