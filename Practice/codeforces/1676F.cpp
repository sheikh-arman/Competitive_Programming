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
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,k,sum=0;
        cin>>n>>k;
        map<ll,ll>mp;
        set<ll>st;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            st.insert(a);
            mp[a]++;
        }
        ll left=0,right=0,ans=-1,pre=-1,ck=0,ck2=0;
        ll res_l,res_r;
        vector<ll>V;
        for(ll i:st)
        {
            V.PB(i);
        }
        for(ll i=0; i<(ll)V.size(); i++)
        {
            if(mp[V[i]]>=k)
            {
                if(ans==-1)
                {
                    ans=0;
                    res_l=V[i];
                    res_r=V[i];
                }
                ll j=i+1;
                while(j<n&&mp[V[j]]>=k&&V[j]==V[j-1]+1)
                {
                    j++;
                }
                ll dif=(j-1)-i;
                if(dif>ans)
                {
                    res_l=V[i];
                    res_r=V[j-1];
                    ans=(j-1)-i;
                }
                i=j-1;
            }
        }
        if(ans==-1)
        {
            cout<<ans<<"\n";
        }
        else
        {
            cout<<res_l<<" "<<res_r<<"\n";
        }



    }
    return 0;
}




