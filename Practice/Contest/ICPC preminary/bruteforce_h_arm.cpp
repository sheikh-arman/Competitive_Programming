#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FasrIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 100000000000000000

template<typename T>
using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using min_heap=priority_queue<ll,vector<ll>,greater<ll>>;
using min_heap_my=priority_queue<pair<pair<ll,ll>,ll>,vector<pair<pair<ll,ll>,ll>>,greater<pair<pair<ll,ll>,ll>>>;
ll ar_cost_c[10];

ll dx_ar[] = {-1,-1,-1,0,0,1,1,1};
ll dy_ar[] = {-1,0,1,-1,1,-1,0,1};
int main()
{
    //freopen("input.txt","r",stdin);
    ll tcase=1000;
    //scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        string s,s2;
        cin>>s>>s2;
        set<string>st;
        ll siz1=s.size();
        ll siz2=s2.size();
        string tm_pre;
        for(ll i=0; i<siz1; i++)
        {
            string tm_sup;
            string ans;

            for(ll j=siz2-1; j>=0; j--)
            {
                string tm_sup2=tm_sup;
                reverse(tm_sup2.begin(),tm_sup2.end());
                ans=tm_pre;
                ans+=tm_sup2;
                st.insert(ans);
                tm_sup+=s2[j];
            }
            string tm_sup2=tm_sup;
            reverse(tm_sup2.begin(),tm_sup2.end());
            ans=tm_pre;
            ans+=tm_sup2;
            st.insert(ans);
            tm_pre+=s[i];
        }
        string tm_sup;
        for(ll j=siz2-1; j>=0; j--)
        {
            string tm_sup2=tm_sup;
            reverse(tm_sup2.begin(),tm_sup2.end());
            string ans=tm_pre;
            ans+=tm_sup2;
            st.insert(ans);
            tm_sup+=s2[j];
        }
        string tm_sup2=tm_sup;
        reverse(tm_sup2.begin(),tm_sup2.end());
        string ans=tm_pre;
        ans+=tm_sup2;
        st.insert(ans);
        cout<<st.size()<<"\n";
//        for(auto i:st){
//            cout<<i<<" x\n";
//        }
    }
}

//fc de
















