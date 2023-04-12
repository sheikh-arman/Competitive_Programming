#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll N=1e7+17;
ll a[N],b[N],c[N],ck[N];
void seive()
{
    ll i,j;
    a[1]=1;
    for(i=2; i<N; i++) a[i]=i;
    for(i=2; i*i<N; i++)
    {
        if(a[i]<i) continue;
        for(j=i*i; j<N; j+=i) a[j]=min(a[j],i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    seive();
    int t;
    cin>>t;
    int l=t;
    while(t--)
    {
        cout<<"Case "<<l-t<<": ";
        ll n,i,j,s=0,s2=0,gcd,x=0,y=0,s3=0,y2=0,y1=0;
        cin>>n;
        //map<ll,ll>m;
        for(i=0; i<n; i++)
        {
            cin>>b[i];
            if(i==0) gcd=b[i];
            else gcd=__gcd(gcd,b[i]);
            s=b[i];
            while(s>1)
            {
                //m[a[s]]++;
                ck[a[s]]=1;
                s/=a[s];
            }
            ck[s]=1;
        }
        set<ll>st;
        for(i=0; i<n; i++)
        {
            cin>>c[i];
            s2=c[i];
            while(s2>1)
            {
                if(ck[a[s2]]==0)
                {
                    x=1;
                    break;
                }
                s2/=a[s2];
            }
            if(b[i]>c[i] && y==0)
            {
                if(b[i]%c[i]) y=1;
                else
                {
                    y1=1;
                    st.insert(b[i]/c[i]);
                    s3=b[i]/c[i];
                }
            }
            else if(b[i]<=c[i] && y==0)
            {
                if(c[i]%b[i]) y=1;
                else
                {
                    y2=1;
                    st.insert(c[i]/b[i]);
                    s3=c[i]/b[i];
                }
            }
        }
        //cout<<x<<" "<<y<<" "<<y1<<" "<<y2<<endl;
        if(x==0) cout<<"Yes ";
        else cout<<"No ";
        if(y==0 )
        {
            if(y1==1 && y2==1) cout<<"No\n";
            //else if(st.size()==0) cout<<"Yes\n";
            else if (st.size()==1)
            {
                ll z=s3;
                while(z>1)
                {
                    if(gcd%a[z])
                    {
                        y=1;
                        cout<<"No\n";
                        break;
                    }
                    z/=a[z];
                }
                if(y==0) cout<<"Yes\n";
            }
            else cout<<"No\n";
        }
        else cout<<"No\n";
        for(i=0; i<n; i++)
        {
            s=b[i];
            while(s>1)
            {
                //m[a[s]]++;
                ck[a[s]]=0;
                s/=a[s];
            }
            ck[s]=0;
        }
    }
    return 0;
}
