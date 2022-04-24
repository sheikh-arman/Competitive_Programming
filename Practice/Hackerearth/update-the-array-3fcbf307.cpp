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
        ll n;
        cin>>n;
        vector<ll>V;
        set<ll>st;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
            st.insert(a);
        }
        ll k;
        cin>>k;
        VST(V);
        ll cnt=0;
        ll odd=0,even=0;
        for(ll i:st)
        {
            if(i<=k)
            {
                cnt++;
            }
            if(i%2==0)even++;
            else odd++;

        }
        ll new_k=k-cnt;
        ll baki=n-st.size();
        if(baki>new_k||n%2!=0)
        {
            cout<<"-1\n";
        }
        else
        {
            if(even==odd&&(ll)st.size()==n)
            {
                cout<<"0\n";
            }
            else
            {
                ll need_even=0;
                ll need_odd=0;
                if(even>n/2)
                {
                    need_odd=n/2-odd;

                }
                else if(odd>n/2)
                {
                    need_even=n/2-even;
                }
                else
                {
                    need_even=n/2-even;
                    need_odd=n/2-odd;
                }

                ll cost=0,ck=1;
                for(ll i=1; i<=k&&need_odd>0; i+=2)
                {
                    auto pos=st.find(i);
                    if(pos==st.end()||*pos!=i)
                    {
                        cost++;
                        need_odd--;
                    }
                }
                for(ll i=2; i<=k&&need_even>0; i+=2)
                {
                    auto pos=st.find(i);
                    if(pos==st.end()||*pos!=i)
                    {
                        cost++;
                        need_even--;
                    }
                }
                if(need_even||need_odd)
                {
                    cout<<"-1\n";
                }
                else
                {
                    cout<<cost<<"\n";
                }
            }

        }
    }
    return 0;
}




