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
ll ar[MAX+100];
int main()
{
    for(ll i=0; i<=MAX; i++)ar[i]=0;
   // freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        vector<ll>A,B;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            A.PB(a);
          //  cout<<a<<" ";
        }
       // cout<<" t\n";
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            B.PB(a);
          //  cout<<a<<" ";
        }
       // cout<<" test\n";
        ll ck=1;
        ll current=0;
        ll i=0;
        for(i=0; i<n&&current<n; )
        {
            if(B[i]!=A[current])
            {
                if(i>0)
                {
                    if(B[i-1]==B[i])
                    {
                        if(ar[B[i]]>0)
                        {
                            ar[B[i]]--;i++;
                        }
                        else
                        {
                            ar[A[current++]]++;
                        }
                    }
                    else
                    {
                        ar[A[current++]]++;
                    }
                }
                else
                {
                    ar[A[current++]]++;
                }
               // cout<<i<<" xnot\n";
            }
            else
            {
                current++;
                i++;
            }

        }
        while(i<n){
            if(i>0){
                if(B[i]==B[i-1]){
                    if(ar[B[i]]>0){
                        ar[B[i]]--;i++;
                    }
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        for(ll ii:A)
        {
           // cout<<ii<<" "<<ar[ii]<<" x\n";
            if(ar[ii]>0)
            {
                ck=0;
            }
            ar[ii]=0;
        }
       // cout<<" x\n";
        if(ck)
        {
            YES;
        }
        else
        {
            NO;
        }
        for(ll ii:A){
            ar[ii]=0;
        }
    }
    return 0;
}





