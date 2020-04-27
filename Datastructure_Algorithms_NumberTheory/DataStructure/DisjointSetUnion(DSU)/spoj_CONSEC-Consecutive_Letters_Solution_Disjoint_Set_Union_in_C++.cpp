/*
    Sk arman Hossain
    University of Barisal

    Problem name : spoj_CONSEC-Consecutive_Letters
    Solution : Disjoint Set Union(DSU)
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 200002
ll rep[N+10];
ll cnt_node[N+10];
ll Find(ll n)
{
    return (rep[n]==n)?n:rep[n]=Find(rep[n]);
}
void joint(ll u,ll v)
{
    ll ru=Find(u);
    ll rv=Find(v);
    if(rv!=ru)
    {
        if(cnt_node[ru]<cnt_node[rv])
            swap(ru,rv);
        cnt_node[ru]+=cnt_node[rv];
        rep[rv]=ru;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        string s,s2;
        cin>>s;
        s2=s;
        ll n=s.size();
        for(ll i=0; i<=n; i++)
        {
            rep[i]=i;
            cnt_node[i]=1;
        }
        vector<pair<ll,ll>>V;
        vector<ll>ans;
        ll q;
        cin>>q;
        for(ll i=0; i<q; i++)
        {
            ll a,b;
            cin>>a>>b;
            if(a==2)
            {
                s[b]='#';
            }
            V.push_back({a,b});
        }
        for(ll i=0; i<n-1; i++)
        {
            if(s[i]==s[i+1]&&s[i]!='#')
            {
                joint(i,i+1);
            }
        }

        reverse(V.begin(),V.end());
        for(ll i=0; i<q; i++)
        {
            ll a=V[i].first;
            ll b=V[i].second;
            if(a==1)
            {
                ll re=Find(b);
                ans.push_back(cnt_node[re]);
            }
            else
            {
                s[b]=s2[b];
                if(b-1>=0)
                {
                    if(s[b]==s[b-1])
                    {
                        joint(b-1,b);
                    }
                }
                if(b+1<n)
                {
                    if(s[b]==s[b+1])
                    {
                        joint(b+1,b);
                    }
                }
            }
        }
        //cout<<s<<" "<<s2<<"\n";
        ll siz=ans.size();
        cout<<"Case "<<test<<":\n";
        for(ll i=siz-1; i>=0; i--)
        {
            cout<<ans[i]<<"\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
/*
2
AABBBCCCC
5
1 0
2 1
1 0
2 2
1 3
XXYYY
3
1 3
2 3
1 2
*/

