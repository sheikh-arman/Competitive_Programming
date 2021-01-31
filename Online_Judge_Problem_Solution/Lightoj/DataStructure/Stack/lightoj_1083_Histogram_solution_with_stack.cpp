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
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define minus1 printf("-1\n");
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
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n;
        vector<ll>V,pre(n),sup(n);
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        stack<PR>st;
        for(ll i=0; i<n; i++)
        {
            ll tm=V[i];
            if(st.empty())
            {
                pre[i]=1;
                st.push({tm,i});
                ///cout<<pre[i]<<" tt\n";
            }
            else
            {
                PR pr=st.top();
                ll pos=i;
                pre[i]=0;
                while(pr.first>=tm)
                {
                    pos=pr.second;st.pop();
                    if(st.empty())break;
                    pr=st.top();

                }
                if(pos==i)
                {
                    pre[i]=1;
                }
                else
                {
                    ll di=abs(i-pos);
                    pre[i]=di+pre[pos];
                }
                st.push({tm,i});
            }
        }
        while(!st.empty())st.pop();
        for(ll i=n-1; i>=0; i--)
        {
            ll tm=V[i];
            if(st.empty())
            {
                sup[i]=1;
                st.push({tm,i});
            }
            else
            {
                PR pr=st.top();
                ll pos=i;
                sup[i]=0;
                while(pr.first>=tm)
                {
                    pos=pr.second;st.pop();
                    if(st.empty())break;
                    pr=st.top();

                }
                if(pos==i)
                {
                    sup[i]=1;
                }
                else
                {
                    ll di=abs(i-pos);
                    sup[i]=di+sup[pos];
                }
                st.push({tm,i});
            }
        }
        ll ans=0;
//        for(ll i=0;i<n;i++){
//            cout<<V[i]<<" ";
//        }
//        cout<<"\n";
//         for(ll i=0;i<n;i++){
//            cout<<pre[i]<<" ";
//        }
//        cout<<"\n";
//         for(ll i=0;i<n;i++){
//            cout<<sup[i]<<" ";
//        }
//        cout<<"\n";
        for(ll i=0; i<n; i++)
        {
            ll tm=sup[i]+pre[i];
            tm=(V[i]*(tm-1));
            ans=max(ans,tm);
        }
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


