/*
    Author : SK Arman Hossain
    University of Barishal
    Problem: UVA-247_Calling_Ciecles
    Solution:Strongly Connected Component
*/
#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
vector< pair<ll,ll> >V;
vector<ll>edj[30],trans_edj[30],ans;
ll ending[30],cnt;
bitset<30>color;
void topo_sort(ll node)
{
    cnt++;
    color[node]=true;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            topo_sort(i);
        }
    }
    ending[node]=cnt++;
}
void dfs(ll node)
{
    ans.PB(node);
    color[node]=true;
    for(ll i:trans_edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            dfs(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll n,e,TEST=1,ck=0;
    while(cin>>n>>e&&(n||e))
    {
        map<string,ll>m;
        map<ll,string>trans_m;
        V.clear();
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            trans_edj[i].clear();
            color[i]=false;
        }
        ll cc=1;
        for(ll i=0; i<e; i++)
        {
            ll a,b;
            string s1,s2;
            cin>>s1>>s2;
            if(!m[s1]){
                m[s1]=cc;
                trans_m[cc]=s1;
                cc++;
            }
            if(!m[s2]){
                m[s2]=cc;
                trans_m[cc]=s2;
                cc++;
            }
            a=m[s1];
            b=m[s2];
            edj[a].PB(b);
            trans_edj[b].PB(a);
        }
        cnt=1;
        cc--;
        for(ll i=1; i<=cc; i++)
        {
            if(color[i]==false)
            {
                topo_sort(i);
            }
        }
        for(ll i=1; i<=cc; i++)
        {
            V.PB({ending[i],i});
        }
        sort(V.begin(),V.end());
        //reverse(V.begin(),V.end());
        for(ll i=0; i<=cc; i++)color[i]=false;
        if(ck){
            cout<<"\n";
        }
        cout<<"Calling circles for data set "<<TEST++<<":\n";
        for(ll i=cc-1; i>=0; i--)
        {
            if(color[V[i].second]==false)
            {
                ans.clear();
                dfs(V[i].second);
                ll siz=ans.size();
                for(ll j=0; j<siz; j++)
                {
                    cout<<trans_m[ans[j]];
                    if(j<siz-1)
                    {
                        cout<<", ";
                    }
                    else
                    {
                        cout<<"\n";
                    }
                }
            }
        }
        ck=1;
    }
    ///***************Alhamdulillah*************///
    return 0;
}


