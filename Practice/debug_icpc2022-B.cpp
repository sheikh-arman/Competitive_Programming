#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e7+7;
ll a[N],b[N],c[N];
void seive()
{
    for(ll i=1;i<N;i++){
        a[i]=i;
    }
    for(ll i=2;i<N;i+=2){
        a[i]=2;
    }
    for(ll i=3;i<N;i+=2){
        if(i==a[i]){
            for(ll j=i*i;j<N;j+=i+i){
                a[j]=min(a[j],i);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    seive();
//    for(ll i=1;i<20;i++){
//        cout<<i<<" "<<a[i]<<" x\n";
//    }
    int t;
    cin>>t;
    int l=t;
    while(t--)
    {
        cout<<"Case "<<l-t<<": ";
        ll n,i,j,s=0,s2=0,gcd,x=0,y=0,s3=0;
        cin>>n;
        map<ll,ll>m,m2;
        for(i=0; i<n; i++)
        {
            cin>>b[i];
            if(i==0) gcd=b[i];
            else gcd=__gcd(gcd,b[i]);
            s=b[i];
            while(s>1)
            {
                m[a[s]]++;
                s/=a[s];
            }
            // m[s]++;
        }
        set<ll>st;
        for(i=0; i<n; i++)
        {
            cin>>c[i];
            s2=__gcd(b[i],c[i]);
            s2=(b[i]*c[i])/s2;
            while(s2>1)
            {
                if(m[a[s2]]==0)
                {
                    x=1;
                    break;
                }
                s2/=a[s2];
            }
            //cout<<s2<<"  "<<a[s2]<<endl;
            //if(m[s2]==0) x=1;
            if(b[i]>c[i] && y==0)
            {
                if(b[i]%c[i]) y=1;
                else st.insert(b[i]/c[i]);
                s3=b[i]/c[i];
            }
            else if(b[i]<=c[i] && y==0)
            {
                if(c[i]%b[i]) y=1;
                else st.insert(c[i]/b[i]);
                s3=c[i]/b[i];
            }
        }
        if(x==0) cout<<"Yes ";
        else cout<<"No ";
        if(y==0 )
        {
            if(st.size()==0) cout<<"Yes\n";
            else if (st.size()==1 && gcd%s3==0)cout<<"Yes\n";
            else cout<<"No\n";
        }
        else cout<<"No\n";
    }
    return 0;
}
