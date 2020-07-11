/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
#define nl cout<<"\n";
#define N 200001
#define PR pair<ll,ll>
#define sf1(n) cin>>n
#define sf2(n, m) cin>>n>>m
#define sf3(n, m,k ) cin>>n>>m>>k
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define minus1 printf("-1\n")
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {vector<ll>V1,V2,V3;
        string s;
        ll n;
        cin>>s;
        n=s.size();
        for(ll i=0;i<n;i++){
            if(s[i]=='1'){
                V1.PB(i);
            }
            else if(s[i]=='2')V2.PB(i);
            else V3.PB(i);
        }
        if((ll)V1.size()==0||(ll)V2.size()==0||(ll)V3.size()==0){
            cout<<"0\n";continue;
        }
        V1.PB(LONG_MAX);
        V2.PB(LONG_MAX);
        V3.PB(LONG_MAX);
        ll ans=LONG_MAX;
        for(ll i=0;i<n;i++){
            if(s[i]=='1'){
                ll tm=V2[lower_bound(V2.begin(),V2.end(),i)-V2.begin()];
                tm=max(tm,V3[lower_bound(V3.begin(),V3.end(),i)-V3.begin()]);
                tm=tm-i+1;
                ans=min(ans,tm);
            }
            else if(s[i]=='2'){
                ll tm=V1[lower_bound(V1.begin(),V1.end(),i)-V1.begin()];
                tm=max(tm,V3[lower_bound(V3.begin(),V3.end(),i)-V3.begin()]);
                tm=tm-i+1;
                ans=min(ans,tm);
            }
            else{
                ll tm=V2[lower_bound(V2.begin(),V2.end(),i)-V2.begin()];
                tm=max(tm,V1[lower_bound(V1.begin(),V1.end(),i)-V1.begin()]);
                tm=tm-i+1;
                ans=min(ans,tm);
            }
        }
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


