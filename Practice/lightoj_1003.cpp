#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
map<string,ll>m;
ll deg[20010];
vector<ll>edj[20010];
int main()
{
    ll TCASE=1;
    scanf("%lld",&TCASE);
    for(ll TEST=1; TEST<=TCASE; TEST++)
    {
        m.clear();
        ll n,cnt=1;
        ll ck=0;
        scanf("%lld",&n);
        for(ll i=0; i<=n*2; i++)
        {
            deg[i]=0;
            edj[i].clear();
        }
        queue<ll>q;
        for(ll i=0; i<n; i++)
        {

            char ch1[20],ch2[20];
            scanf("%s%s",ch1,ch2);
            if(m[ch1]==0)
            {
                m[ch1]=cnt++;
            }
            if(m[ch2]==0)
            {
                m[ch2]=cnt++;
            }
            ll val1=m[ch1];
            ll val2=m[ch2];
            edj[val1].PB(val2);
            deg[val2]++;
        }
        for(ll i=1;i<cnt;i++){
            if(deg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            ll val=q.front();
            q.pop();
            for(ll i:edj[val]){
                deg[i]--;
            }
            for(ll i:edj[val]){
                if(deg[i]==0)q.push(i);
            }
        }
        for(ll i=1;i<cnt;i++){
            if(deg[i]>0)ck=1;
        }
        if(ck==0)
        {
            printf("Case %lld: Yes\n",TEST);
        }
        else
        {
            printf("Case %lld: No\n",TEST);
        }
    }
}

