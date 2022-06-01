/*
Author:Sk Arman Hossain
University of Barishal
Problem: spoj-> AKBAR - Akbar , The great
Solution:BFS
*/


#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
#define N 1000010
bitset<1000010>color;
ll label[N],ck;
vector<ll>edj[N],temp;
void bfs(ll parent,ll len)
{
    if(len==0){
        if(color[parent]==true){
            ck=1;return;
        }
        else{
            color[parent]=true;return;
        }
    }
    label[parent]=0;
    queue<ll>q;
    color[parent]=true;
    q.push(parent);
    while(!q.empty())
    {
        parent=q.front();
        temp.PB(parent);
        q.pop();
        ll siz=edj[parent].size();
        for(ll i=0; i<siz; i++)
        {
            ll child=edj[parent][i];

            if(label[parent]<len&&label[child]==-1)
            {
                if(color[child]==true){
                    ck=1;return;
                }
                label[child]=label[parent]+1;
                color[child]=true;
                q.push(child);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tcase;
    cin>>tcase;
    while(tcase--)
    {
        ll node,edge,len;
        cin>>node>>edge>>len;
        for(ll i=0; i<=node; i++)
        {
            color[i]=false;
            edj[i].clear();
            label[i]=-1;
        }
        for(ll i=0; i<edge; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
        }
        ck=0;
        for(ll i=0; i<len; i++)
        {
            ll a,b;
            cin>>a>>b;
            if(!ck)
            {
                temp.clear();
                bfs(a,b);
                ll siz=temp.size();
                for(ll j=0; j<siz; j++)
                {
                    label[j]=-1;
                }
            }
        }
        for(ll i=1;i<=node;i++){
            if(color[i]==false){
                ck=1;break;
            }
        }
        if(ck){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
        }
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************///
}
