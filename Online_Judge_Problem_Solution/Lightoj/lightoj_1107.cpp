/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
#define nl cout<<"\n";
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
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define minus1 printf("-1\n");
#define PB push_back
#define VST(v) sort(v.begin(),v.end())
#define VSTr(v) sort(v.begin(),v.end(),greater<long long int>())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
double PI = 2 * acos(0.0);
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
ll SET(ll NUM,ll POS) {
    return NUM | (1<<POS);
}
bool isOn(ll NUM,ll POS) {
    return (bool)(NUM & (1<<POS));
}

ll ck(PR pos1,PR pos2,ll x,ll y){
    ll cnt=0;
    if(pos1.ff==pos2.ff){
        if(x>pos1.ff){
            cnt+=1;
        }
        else if(x<pos1.ff){
            cnt-=1;
        }
        else{
            cnt+=15;
        }
    }
    else{
        if(y>pos1.ss){
            cnt+=1;
        }
        else if(y<pos1.ss){
            cnt-=1;
        }
        else{
            cnt+=15;
        }
    }
    return cnt;

}
int main()
{
    fast;
  //  freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        vector<PR>V;
        ll x,y,x2,y2;
        cin>>x>>y>>x2>>y2;
        V.PB({x,y});
        V.PB({x2,y});
        V.PB({x2,y2});
        V.PB({x,y2});
        ll q;
        cout<<"Case "<<test<<":\n";
        cin>>q;
        ll x1,y1;
        for(ll i=0;i<q;i++){
            cin>>x1>>y1;
            ll ans1=0,ans2=0;
            ans1+=ck(V[0],V[1],x1,y1);
            ans2+=ck(V[1],V[2],x1,y1);
            ans1+=ck(V[3],V[2],x1,y1);
            ans2+=ck(V[0],V[3],x1,y1);
            if(ans1==0&&ans2==0){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}





