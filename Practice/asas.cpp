#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        for(int i=m-1; i>=0; i--)
        {
            s1+=s2[i];
        }
        int cnt=0;
        for(int i=0; i<(n+m)-1; i++)
        {
            if(s1[i]==s1[i+1])
            {
                cnt++;
            }
        }
        if(cnt>1)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
        }
    }




}

