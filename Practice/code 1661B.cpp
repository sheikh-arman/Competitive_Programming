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
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    cin>>tcase;

    for(ll test=1; test<=tcase; test++)
    {
        ll a;
        cin>>a;
        if(a==0)
        {
            cout<<"0\n";
            continue;
        }
//        if(a==32768)
//        {
//            cout<<"1\n";
//            continue;
//        }
        ll ans=88;
        ll init=0;
        for(ll i=a; i<=a+20; i++)
        {
            ll cnt=0;
            ll num=i;
            while(num)
            {
                if(num%2==0)
                {
                    cnt++;
                }
                else
                {
                    break;
                }
                num/=2;
            }
            ll v1=15-cnt;
            ans=min(ans,v1+init);
            if(cnt==0)
            {
                num=i;
                while(num)
                {
                    if(num%2!=0)
                    {
                        cnt++;
                    }
                    else
                    {
                        break;
                    }
                    num/=2;
                }
                ll v2=15-(cnt-1);
                ans=min(ans,v2+init);
            }
            init++;
        }
        ans=min(ans,(ll)32768-a);
        cout<<ans<<" ";
    }
    cout<<"\n";
    return 0;
}





