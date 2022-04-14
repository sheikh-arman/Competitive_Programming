#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
vector<ll>V[30];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        for(ll i=0; i<27; i++)
        {
            V[i].clear();
        }
        ll n;
        string s;
        cin>>s;
        n=s.size();
        for(ll i=0; i<n; i++)
        {
            V[s[i]-'a'].PB(i);
        }
        ll cnt=0;
        for(ll i=0; i<n; i++)
        {
            ll ch=s[i]-'a';
            ll left=i;
            ll right=upper_bound(V[ch].begin(),V[ch].end(),i)-V[ch].begin();
            //right++;
            //cout<<ch<<" "<<i<<" "<<right<<" t\n";
            if(right>=(ll)V[ch].size())
            {
                continue;
            }
            right=V[ch][right];
            ll ck=0;
            for(ll j=0; j<26; j++)
            {
                if(ch!=j)
                {
                    ll pos1=lower_bound(V[j].begin(),V[j].end(),left)-V[j].begin();
                    if(pos1+1>=(ll)V[j].size()||pos1>=(ll)V[j].size())
                    {
                        continue;
                    }
                    if(V[j][pos1]>left&&V[j][pos1+1]<right)
                    {
                        ck=1;
                        break;
                    }
                }
            }
            // cout<<i<<" "<<cnt<<" "<<right<<" x\n";
            if(ck==0)
            {
                cnt+=2;
                i=right;
            }
        }
        cout<<n-cnt<<"\n";
    }
    return 0;
}




