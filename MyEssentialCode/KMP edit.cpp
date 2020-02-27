#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define mp pair<ll,ll>
#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d %d",&n,&m)
#define sfl(n) scanf("%lld", &n)
#define sfu(n) scanf("%llu", &n)
#define sffl(n, m) scanf("%lld %lld",&n,&m)
#define pfn(n) printf("%d\n",n)
#define pf(n) printf("%d ",n)
#define pfl(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define pb push_back
#define pi 3.1415926536
#define vst(v) sort(v.begin(),v.end())
#define fori(n) for(int i=0;i<n;i++)
int dx[]= {0,0,1,1};
int dy[]= {1,1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<int>v,v2,v3;
vector<int> :: iterator it1,it2;
#define MAX 10000
int failure[MAX];
void build_failure_function(string pattern, int m)
{
    failure[0] = 0;
    failure[1] = 0;
    for(int i = 2; i <= m; i++)
    {
        int j = failure[i - 1];
        while(true)
        {
            if(pattern[j] == pattern[i - 1])
            {
                failure[i] = j + 1;
                break;
            }
            if(j == 0)
            {
                failure[i] = 0;
                break;
            }
            j = failure[j];
        }
    }
}
bool kmp(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    build_failure_function(pattern, m);
    int i = 0;
    int j = 0;
    while(true)
    {
        if(j == n)
        {
            return false;
        }
        if(text[j] == pattern[i])
        {
            i++;
            j++;
            if(i == m)
            {
                return true;
            }
        }
        else
        {
            if (i == 0)
            {
                j++;
            }
            else
            {
                i = failure[i];
            }
        }
    }
    return false;
}
int main ()
{
    string s1,s2;
    s1="arman";
    s2="armn";
    if(kmp(s1,s2)==1)
    {
        printf("YES\n");
    }
    else
        printf("NO\n");

    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}

