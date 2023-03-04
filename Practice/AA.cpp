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
int main()
{
    // cout<<"hjg\n";
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,ck=0;
        cin>>n;
        vector<ll>V,track1,track2;
        set<ll>st;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
            st.insert(a);
            if(a==1)ck=1;
        }
        if((ll)st.size()==1)
        {
            cout<<"0\n";
            continue;
        }
        if(ck)
        {
            cout<<"-1\n";
            continue;
        }
        ll pos1=-1,pos2=-1;
        st.clear();
        for(ll i=0; i<n-1&&pos1==-1; i++)
        {
            for(ll j=i+1; j<n; j++)
            {
                ll a=V[i],b=V[j];
                ll p=i,q=j;
                if(a>b)
                {
                    swap(a,b);
                    swap(p,q);
                }
                while(a!=b&&a!=2&&a!=1)
                {
                    //cout<<a<<" "<<b<<" x\n";
                    b=b/a+(b%a!=0);
                    track1.PB(q);
                    track2.PB(p);
                    swap(p,q);
                    swap(a,b);
                }
                if(a==2)
                {
                    pos1=p;
                    V[q]=b;
                    break;
                }
                else
                {
                    track1.clear();
                    track2.clear();
                }
            }
        }
        //cout<<pos1<<" tut\n";
        if(pos1!=-1)
        {
            for(ll i=0; i<n; i++)
            {
                if(i!=pos1)
                {
                    while(V[i]!=2)
                    {
                        track1.PB(i);
                        track2.PB(pos1);
                        V[i]=(V[i]/2)+(V[i]%2!=0);
                    }
                }
            }
        }
        else
        {
            ll a=V[0];
            ll b=V[1];
            ll p=0,q=1;
            if(a>b)
            {
                swap(a,b);
                swap(p,q);
            }
            while(a!=b&&a!=-1)
            {
                cout<<"a\n";
                b=b/a+(b%a!=0);
                track1.PB(q);
                track2.PB(p);
                swap(p,q);
                swap(a,b);
            }
            for(ll i=2; i<n; i++)
            {
                while(V[i]!=V[0])
                {
                cout<<"b\n";
                    track1.PB(i);
                    track2.PB(0);
                    V[i]/=V[0];
                }
            }
        }
        cout<<track1.size()<<"\n";
        ll siz=track1.size();
        for(ll i=0; i<siz; i++)
        {
            cout<<track1[i]+1<<" "<<track2[i]+1<<"\n";
        }
    }
    return 0;
}





