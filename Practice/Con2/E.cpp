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
priority_queue< string, vector<string>, greater<string > >pq2;
priority_queue< string >pq;
int main()
{
//    pq.push("zaac");
//    pq.push("zabc");
//    pq.push("zacd");
//    pq.push("zaaa");
////    while(!pq.empty()){
////        cout<<pq.top()<<"\n";
////        pq.pop();
////    }

    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        string s;
        ll sum=0;
        vector<string>V;
        for(int i=0; i<n; i++)
        {
            cin>>s;

            if((ll)s.size()>0)
            {
                V.PB(s);
                reverse(s.begin(),s.end());
                pq.push(s);
            }
            sum+=s.size();
        }
        s.clear();
        string s2;
        for(ll i=0; i<sum; i++)
        {
            s+='a';
            s2+='a';
        }
        ll cnt=sum;
        while(!pq.empty()&&cnt--)
        {
            string tm=pq.top();
            pq.pop();
            s[cnt]=tm[0];
            tm.erase(tm.begin());
            if((ll)tm.size()>0)
            {
                pq.push(tm);
            }
        }
        n=V.size();
        for(int i=0; i<n; i++)
        {
            pq2.push(V[i]);
        }
        cnt=0;
        while(!pq2.empty())
        {
            string tm=pq2.top();
            pq2.pop();
            s2[cnt++]=tm[0];
            tm.erase(tm.begin());
            if((ll)tm.size()>0)
            {
                pq2.push(tm);
            }
        }
        if(s2<s)
        {
            s=s2;
        }
        cout<<s<<"\n";
    }
    return 0;
}




