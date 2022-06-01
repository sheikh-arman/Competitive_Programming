#include<bits/stdc++.h>
#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d %d",&n,&m)
#define pb push_back
typedef long long int ll;
using namespace std;
int main()
{

    int t,n,m,cnt=0;
    sf(t);
    while(t--)
    {
        vector<int>v,v2;
        int ar[800]={0};
        sff(n,m);
        string s[305];
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
            for(int j=0;j<m;j++){
                if(s[i][j]=='1'){
                    v.pb(i);
                    v2.pb(j);
                }
            }
        }
        cnt=v.size();
        int up=cnt/2;
        for(int i=0;i<up;i++){
                int temp=up;
            for(int j=i+1,k=cnt-1;j<=k;j++,k--){
                int x=abs(v[i]-v[j])+abs(v2[i]-v2[j]);
                ar[x]++;
                if(k>j){
                x=abs(v[i]-v[k])+abs(v2[i]-v2[k]);ar[x]++;
                }
                if(temp+j<cnt){
                    x=abs(v[temp]-v[temp+j])+abs(v2[temp]-v2[temp+j]);ar[x]++;
                    if(k>j&&temp+k<cnt){
                        x=abs(v[temp]-v[temp+k])+abs(v2[temp]-v2[temp+k]);ar[x]++;
                    }
                }

            }
        }
        for(int i=1;i<(m+n-2);i++){
            printf("%d ",ar[i]);
        }
        printf("%d\n",ar[m+n-2]);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
