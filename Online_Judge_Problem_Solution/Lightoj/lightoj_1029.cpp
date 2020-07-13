/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution : minimum spanning tree(kruskal)
 */
#include<bits/stdc++.h>
using namespace std;
int rep[110];
int ans1,ans2;
int fin(int n)
{
    return (rep[n]==n?n:rep[n]=fin(rep[n]));
}
void joint(int u,int v,int ck,int val)
{
    int a=fin(u);
    int b=fin(v);
    if(a!=b)
    {
        rep[a]=b;
        if(ck==0)
        {
            ans1+=val;
        }
        else
        {
            ans2+=val;
        }
    }
}
int main()
{
    int tcase;
    scanf("%d",&tcase);
    for(int test=1; test<=tcase; test++)
    {
        int u,v,w,n;
        ans1=0;
        ans2=0;
        scanf("%d",&n);
        vector< pair<pair<int,int>,int>>V1;
        while(1)
        {
            scanf("%d%d%d",&u,&v,&w);
            if(!u&&!v&&!w)
            {
                break;
            }
            V1.push_back({{w,u},v});
        }
        sort(V1.begin(),V1.end());
        int siz=V1.size();
        for(int i=0;i<=n;i++)rep[i]=i;
        for(int i=0; i<siz; i++)
        {
            joint(V1[i].first.second,V1[i].second,0,V1[i].first.first);
        }
        for(int i=0;i<=n;i++)rep[i]=i;
        for(int i=siz-1; i>=0; i--)
        {
            joint(V1[i].first.second,V1[i].second,1,V1[i].first.first);
        }
        int ans=ans1+ans2;
        if(ans%2==0)
        {
            printf("Case %d: %d\n",test,ans/2);
        }
        else
        {
            printf("Case %d: %d/2\n",test,ans);
        }
    }
}
