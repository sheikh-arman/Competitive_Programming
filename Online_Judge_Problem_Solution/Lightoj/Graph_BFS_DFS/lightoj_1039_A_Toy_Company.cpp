/*
  Sk arman Hossain
  University of Barisal

 Problem name : 1039 - A toy company
 Algorithm : BFS
*/

#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define PR pair<int,int>
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
#define YES printf("YES\n")
#define NO printf("NO\n")
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
map<string,int>m,ans;
void CLEAR()
{
    m.clear();
    ans.clear();
}
int bfs(string start,string dis)
{
    queue<string>q;
    ans[start]=0;
    q.push(start);
    while(!q.empty())
    {
        string tmp=q.front();
        q.pop();
        if(tmp==dis)
            {
                return ans[tmp];
            }
        for(int i=0; i<3; i++)
        {
            string s;
            s=tmp;
            int val=tmp[i]-'a';
            val++;
            if(val>('z'-'a'))
                val=0;
            string st;
            st=(char)(val+'a');
            s.replace(s.begin()+i,s.begin()+(i+1),st);
            if(s==dis)
            {
                return ans[tmp]+1;
            }
            if(m.count(s)==0&&ans.count(s)==0)
            {
                ans[s]=ans[tmp]+1;
                q.push(s);
            }
            s.clear();st.clear();
            s=tmp;
            val=tmp[i]-'a';
            val--;
            if(val<0)
                val='z'-'a';

            st=(char)(val+'a');
            s.replace(s.begin()+i,s.begin()+(i+1),st);
            if(s==dis)
            {
                return ans[tmp]+1;
            }
            if(m.count(s)==0&&ans.count(s)==0)
            {
                ans[s]=ans[tmp]+1;
                q.push(s);
            }
        }
    }
    return -1;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    int tcase=1;
    sf(tcase);
    for(int test=1; test<=tcase; test++)
    {
        CLEAR();
        string start,dis;
        cin>>start>>dis;
        int n;
        sf(n);
        for(int i=0; i<n; i++)
        {
            string s1,s2,s3;
            cin>>s1>>s2>>s3;
            int l1=s1.size(),l2=s2.size(),l3=s3.size();
            for(int j=0; j<l1; j++)
            {
                for(int k=0; k<l2; k++)
                {
                    for(int l=0; l<l3; l++)
                    {
                        string s;
                        s+=s1[j];
                        s+=s2[k];
                        s+=s3[l];
                        if(m.count(s)==0)
                            m[s]=1;
                        //cout<<s<<endl;
                    }
                }
            }
        }
         if(m.count(start)||m.count(dis))
        {
            printf("Case %d: %d\n",test,-1);
            continue;
        }

        else
        {
            int result=bfs(start,dis);
            printf("Case %d: %d\n",test,result);
        }
        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
