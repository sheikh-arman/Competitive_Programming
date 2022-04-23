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
deque<ll>dq[200010];
ll ans[200010];
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
            ar[i]=a;
            dq[a].PB(i);
            st.insert(a);
        }
        vector<pair<ll,ll>>tm;
        for(ll i:st)
        {
            tm.PB({i,dq[i].size()});
        }
        ll cnt=0;

        if((ll)st.size()==1)
        {
            break;
        }
        else if((ll)st.size()==2)
        {
            for(ll i=0; i<tm[1].second; i++)
            {
                ll num1=tm[0].first;
                ll num2=tm[1].first;
                swap(ar[dq[num1][0]],ar[dq[num2][0]]);
                dq[num1].pop_front();
                dq[num2].pop_front();
            }
        }
        else
        {
            ll fir=0;
            ll sec=1;
            ll last=st.size()-1;
            while(cnt<n)
            {
                ll num1=tm[fir].first;
                ll num2=tm[sec].first;
                ll num3=tm[last].first;
                if((ll)dq[num1].size()==0)
                {
                    if(sec<last-1)
                    {
                        fir=sec+1;
                        swap(fir,sec);
                    }
                }
            }
        }



        for(ll i=0; i<n; i++)
        {
            if(i>0)
            {
                cout<<" ";
            }
            cout<<ar[i];
        }
        cout<<"\n";
    }
    return 0;
}




