#include<bits/stdc++.h>
#define rep(i,x,y)for(int i=(x);i<=(y);i++)
#define ll long long
using namespace std;
const int N=2e5+5;
int n,a[N];
ll sum[N],cur,ans;
ll cal(int x,int y)
{
    if(x<=y)return cur+(ll)a[x]*(y-x)-(sum[y]-sum[x]);
    else return cur+(sum[x-1]-sum[y-1])-(ll)a[x]*(x-y);
}
int main()
{
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i],cur+=(ll)a[i]*i;
    ans=cur;
    rep(i,1,n)
    {
        int l=1,r=n,m1,m2;
        while((r-l)>=3)
        {
            m1=l+(r-l)/3,m2=r-(r-l)/3;
            if(cal(i,m1)>cal(i,m2))r=m2;
            else l=m1;
        }
        rep(j,l,r)ans=max(ans,cal(i,j));
    }
    cout<<ans;
    return 0;
}
