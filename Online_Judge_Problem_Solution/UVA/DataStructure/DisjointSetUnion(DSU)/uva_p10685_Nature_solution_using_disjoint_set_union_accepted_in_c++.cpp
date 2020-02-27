/*
    Sk arman Hossain
    University of Barisal

    Problem name :uva_p10685_Nature
    Algorithm :Disjoint set union(dsu)
 */

#include<bits/stdc++.h>
using namespace std;
int rep[5010];
void initial(int n)
{
    for(int i=0; i<=n; i++)
    {
        rep[i]=i;
    }
}
int find_representative(int node)
{
    if(rep[node]==node)
    {
        return node;
    }
    else
    {
        rep[node]=find_representative(rep[node]);
        return rep[node];
    }
}
void union_node(int nodex,int nodey)
{
    int u=find_representative(nodex);
    int v=find_representative(nodey);
    if(u!=v)
    {
        rep[u]=v;
    }
}
int main()
{
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    int tcase=1,n,d;
    while(scanf("%d%d",&n,&d))
    {
        memset(rep,0,sizeof(rep));
        if(n==0&&d==0)break;
        map<string,int>m;
        map<int,int>ans;
        string s,s2;
        initial(n);
        int Max=0;
        //while(getchar() != '\n');
        for(int i=0; i<n; i++)
        {
            cin>>s;
            m[s]=i;
        }
        for(int i=0; i<d; i++)
        {
            cin>>s>>s2;
            int a=m[s],b=m[s2];
            union_node(a,b);
        }
        for(int i=0;i<n;i++){
            int u=find_representative(i);
            ans[u]++;
            if(ans[u]>Max)
                Max=ans[u];
        }
        printf("%d\n",Max);

    }
///*****************************  ALHAMDULILLAH  *****************************/
}


