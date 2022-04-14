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
ll n;
ll left1;
ll right1;
ll ma;
vector<ll>V;
void sol(ll lo,ll high)
{
    ll cnt=0,two=0;
    for(ll i=lo; i<=high; i++)
    {
        if(V[i]<0)cnt++;
        if(abs(V[i])==2)two++;
    }
    if(cnt%2!=0)
    {
        ll lft=lo,rht=high;
        ll lft_two=0,rht_two=0;
        while(1)
        {
            if(V[lft]<0)
            {
                if(abs(V[lft])==2)
                {
                    lft_two++;
                }
                ll new_two=two-lft_two;
                if(ma<new_two)
                {
                    left1=lft+1;
                    right1=high;
                    ma=new_two;
                }
                break;
            }
            else
            {
                if(V[lft]==2)
                    lft_two++;
                lft++;
            }
        }
        while(1)
        {
            if(V[rht]<0)
            {
                if(abs(V[rht])==2)
                {
                    rht_two++;
                }
                ll new_two=two-rht_two;
                if(ma<new_two)
                {
                    left1=lo;
                    right1=rht-1;
                    ma=new_two;
                }
                break;
            }
            else
            {
                if(V[rht]==2)
                    rht_two++;
                rht--;
            }
        }
    }
    else
    {
        if(ma<two)
        {
            left1=lo;
            right1=high;
            ma=two;
        }
    }

}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        V.clear();
        vector<ll>zero;
        cin>>n;
        ll check=1;;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
            if(a==0)
            {
                zero.PB(i);
                check=0;
            }
        }
        ma=0;
        left1=0;
        right1=0;
        for(ll i=0; i<n; i++)
        {
            if(V[i]==0)
            {
                check=0;
                sol(0,i-1);
                break;
            }
        }
        for(ll i=n-1; i>=0; i--)
        {
            if(V[i]==0)
            {
                check=0;
                sol(i+1,n-1);
                break;
            }
        }
        ll siz=zero.size();
        if(siz>1)
        {
            for(ll i=1; i<siz; i++)
            {
                if(zero[i]-zero[i-1]>1)
                {
                    sol(zero[i-1]+1,zero[i]-1);
                }
            }
        }
        if(check)
        {
            sol(0,n-1);
        }
        if(ma==0)
        {
            cout<<n<<" 0\n";
        }
        else
        {
            cout<<left1<<" "<<n-(right1+1)<<"\n";
        }
    }
    return 0;
}





