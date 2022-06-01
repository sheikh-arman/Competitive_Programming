/*
Author:SK Arman HOSSAIN

Problem:UVA 12207_That_is_Your_Queue
Solution: queue
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll n,c,cnt=1;
    while(cin>>n>>c&&(n||c))
    {
        queue<ll>que;
        unordered_map<ll,ll>mp;
        unordered_map<ll,ll>mp2;
        for(ll i=1; i<=min(c,n); i++)
        {
            mp[i]=1;
            que.push(i);
        }
        cout<<"Case "<<cnt++<<":\n";
        for(ll i=1; i<=c; i++)
        {
            char ch;
            ll tm;
            cin>>ch;
            if(ch=='N')
            {
                cout<<que.front()<<"\n";
                mp[que.front()]=0;
                que.push(que.front());
                que.pop();
            }
            else
            {
                cin>>tm;
                queue<ll>tt;
                tt.push(tm);
                while(!que.empty())
                {
                    ll fr=que.front();
                    que.pop();
                    if(tm!=fr)
                    {
                        tt.push(fr);
                    }
                }
                que=tt;
            }
        }
    }
    return 0;
}
