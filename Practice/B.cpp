/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
    Date:
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

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
int color[10000110];
bitset<10000010>mp;
vector<ll>prime_list;
void seive(){
    prime_list.PB(2);
    for(ll i=2;i<=10000000;i+=2)color[i]=2;
    for(ll i=3;i<=10000000;i+=2){
        if(color[i]==0){
            if(i<4000)
            prime_list.PB(i);
            color[i]=i;
            for(ll j=i*i;j<=10000000;j+=2*i){
                if(color[j]==0)
                   color[j]=i;
            }
        }
    }
}
vector<ll>V,V2;
vector<ll> fact(ll n){
    vector<ll>tm;
    for(ll i:prime_list){
        if(n%i==0){
            tm.PB(i);
            while(n%i==0)n/=i;
        }
        if(i*i>n)break;
    }
    if(n>1){
        tm.PB(n);
    }
    return tm;
}
int main()
{
    seive();
    //cout<<prime_list.size();
   /*  for(ll i=0;i<10;i++){
        cout<<prime_list[i]<<" tee\n";
    } */
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
<<<<<<< HEAD
        V.clear();
        V2.clear();
        ll n,ck=1;
=======
<<<<<<< HEAD
        ll n;
        cin>>n;
        vector<ll>V;
        for(ll i=0;i<n*2;i++){
            ll a;
            cin>>a;
            V.PB(a);
        }
        VST(V);
        ll ans=1000000000000;
        for(ll i=0;i<=n;i++){
            ans=min(ans,V[i+n-1]-V[i]);
        }
        cout<<ans<<"\n";
=======
        ll n,sum=0;
>>>>>>> refs/remotes/origin/master
        cin>>n;
        ll gcd=0;
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            gcd=__gcd(a,gcd);
            V.PB(a);
            while(a!=1){
                mp[color[a]]=1;
                a/=color[a];
            }
        }
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            V2.PB(a);
             while(a!=1){
                if(mp[color[a]]==0){
                    ck=0;break;
                }
                a/=color[a];
            }
            if(a!=1)ck=0;
        }
        for(ll i=0;i<n;i++){
            ll a=V[i];
            while(a!=1){
                mp[color[a]]=0;
                a/=color[a];
            }
        }
        ll ck2=1;
        if(V[0]>V2[0]){
            if(V[0]%V2[0]){
                ck2=0;
            }
            else{
                ll dif=V[0]/V2[0];
                vector<ll>tm=fact(gcd);
                vector<ll>tm2=fact(dif);
                for(ll i:tm){
                    mp[i]=1;
                }
                for(ll i:tm2){
                    if(mp[i]==0){
                        ck2=0;
                    }
                }
                for(ll i:tm)mp[i]=0;
                for(ll i:tm2)mp[i]=0;
                if(ck2){
                    for(ll i=0;i<n;i++){
                        if(V[i]%V2[i]||V[i]/V2[i]!=dif){
                            ck2=0;
                        }
                    }
                }
            }
        }
        else if(V[0]<V2[0]){
             if(V2[0]%V[0]){
                ck2=0;
            }
            else{
                ll dif=V2[0]/V[0];
                vector<ll>tm=fact(gcd);
                vector<ll>tm2=fact(dif);
                for(ll i:tm){
                    mp[i]=1;
                }
                for(ll i:tm2){
                    if(mp[i]==0){
                        ck2=0;
                    }
                }
                for(ll i:tm)mp[i]=0;
                for(ll i:tm2)mp[i]=0;
                if(ck2){
                    for(ll i=0;i<n;i++){
                        if(V2[i]%V[i]||V2[i]/V[i]!=dif){
                            ck2=0;
                        }
                    }
                }
            }
        }
        else{
            for(ll i=0;i<n;i++){
                if(V[i]!=V2[i])ck2=0;
            }
        }
        cout<<"Case "<<test<<": ";
        if(ck){
            cout<<"Yes ";
        }
        else{
            cout<<"No ";
        }
        if(ck2){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
<<<<<<< HEAD
=======
        

>>>>>>> refs/remotes/origin/master
>>>>>>> refs/remotes/origin/master
    }
    return 0;
}
