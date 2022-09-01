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
vector<string>V,ans;
int main()
{
    queue<string>q;
    q.push(".");
    q.push("-");
    while(!q.empty())
    {
        string s=q.front();
        q.pop();
        if((ll)s.size()==10)
        {
            V.PB(s);
            continue;
        }
        string s2=s;
        s+='.';
        s2+='-';
        q.push(s);
        q.push(s2);
    }
     ll cnt=450;
                for(ll i=0; i<100; i++)
                {
                    cout<<V[cnt++]<<" t\n";
                }
//    cout<<V.size();
//    for(ll i=0; i<V.size(); i++)
//    {
//        cout<<i<<" "<<V[i]<<" x\n";
//    }
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ans.clear();
        ll n;
        cin>>n;
        string s;
        cin>>s;
        char ch;
        ll siz=s.size();
        //cout<<n<<" "<<siz<<" tt\n";
        if(siz>10)
        {
            if(siz%10==0)
            {
                for(ll i=0; i<1024; i++)
                {
                    ll ck=0;
                    for(ll j=0; j<n; j+=10)
                    {
                        ll ck2=1;
                        for(ll k=0; k<10; k++)
                        {
                            if(V[i][k]!=s[j+k])
                            {
                                ck2=0;
                            }
                        }
                        ck+=ck2;
                    }
                    if(ck==0)
                    {
                        ans.PB(V[i]);
                    }
                    if((ll)ans.size()>=n-1)break;
                }
            }
            else
            {
                for(ll i=0; i<n; i++)
                {
                    ans.PB(V[i]);
                }
            }
        }
        else
        {
            if(10LL%siz==0)
            {

                for(ll i=0,j=0; i<1024; i++)
                {
                    ll ck=0;
                    for(ll j=0; j<10; j++)
                    {
                        if(V[i][j]!=s[j%siz])
                        {
                            ck=1;
                            break;
                        }
                    }
                    if(ck==1)
                    {
                        ans.PB(V[i]);
                    }
                    if((ll)ans.size()>=n-1)break;

                }
            }
            else
            {
                ll cnt=450;
                for(ll i=0; i<n; i++)
                {
                    ans.PB(V[cnt++]);
                }
            }
        }
        cout<<"Case #"<<test<<":\n";
        for(ll i=0; i<n-1; i++)
        {
            cout<<ans[i]<<"\n";
        }
    }
    return 0;
}





