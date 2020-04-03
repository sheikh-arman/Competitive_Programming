
/*
Author:Sk Arman Hossain
University of Barishal
Problem: spoj-> NAKANJ - Minimum Knight moves
Solution:BFS
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dx[]={1,-1,0,0,1,-1,-1,1};
ll dy[]={0,0,1,-1,1,1,-1,-1};
ll knx[]={2,2,1,-1,-2,-2,1,-1};
ll kny[]={1,-1,2,2,1,-1,-2,-2};

ll label[12][12];
vector<pair<ll,ll>>temp;
ll bfs(pair<ll,ll> st,pair<ll,ll> en)
{
    if(st==en){
        return 0;
    }
    ll siz=temp.size();
    for(ll i=0;i<siz;i++){
        label[temp[i].first][temp[i].second]=-1;
    }
    temp.clear();
    label[st.first][st.second]=0;
    queue<pair<ll,ll>>q;
    q.push(st);
    temp.push_back(st);
    while(!q.empty())
    {
        pair<ll,ll> parent=q.front();
        q.pop();
        for(ll i=0; i<8; i++)
        {
            ll childx=parent.first+knx[i];
            ll childy=parent.second+kny[i];
            if(childx>=1&&childx<=8&&childy>=1&&childy<=8){
                if(childx==en.first&&childy==en.second){
                    return label[parent.first][parent.second]+1;
                }
                if(label[childx][childy]==-1){
                    label[childx][childy]=label[parent.first][parent.second]+1;
                    temp.push_back({childx,childy});
                    q.push({childx,childy});
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    for(ll i=1;i<=8;i++){
        for(ll j=1;j<=8;j++){
            label[i][j]=-1;
        }
    }
    ll tcase;
    cin>>tcase;
    while(tcase--)
    {
        string s1,s2;
        cin>>s1>>s2;
        ll x1,x2,y1,y2;
        x1=(s1[0]-'a')+1;
        y1=s1[1]-'0';

        x2=(s2[0]-'a')+1;
        y2=s2[1]-'0';
        ll ans=bfs({x1,y1},{x2,y2});
        cout<<ans<<"\n";
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************///
}
