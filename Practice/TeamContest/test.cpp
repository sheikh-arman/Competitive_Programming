
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t=1;
    //cin>>t;
    for(ll T=1; T<=t; T++)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        ll n;
        cin>>n;
        vector<ll> A, B;
        ll time, dir;
        for(ll i=0; i<n; i++)
        {
            cin>>time>>dir;
            if(!dir) A.push_back(time);
            else B.push_back(time);
        }
        ll a=A.size(), b=B.size(), i=0, j=0, currTime=0;
        while(i<a and j<b)
        {
            if(A[i]<B[j])
            {
                currTime=max(currTime, A[i++])+10;
                while(i<a and currTime>A[i])
                {
                    currTime=A[i]+10, i++;
                }
            }
            else
            {
                currTime=max(currTime, B[j++])+10;
                while(j<b and currTime>B[j])
                {
                    currTime=B[j]+10, j++;
                }
            }
        }
        if(i<a)
        {
            currTime=max(currTime, A[a-1])+10;
        }
        if(j<b)
        {
            currTime=max(currTime, B[b-1])+10;
        }
        cout<<currTime<<"\n";
    }
    return 0;
}
