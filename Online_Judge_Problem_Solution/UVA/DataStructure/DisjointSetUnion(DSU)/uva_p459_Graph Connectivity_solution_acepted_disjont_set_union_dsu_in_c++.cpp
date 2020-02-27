/*
    Sk arman Hossain
    University of Barisal

    Problem name :uva_p459_Graph Connectivity
    Algorithm :Disjoint set union(dsu)
 */

#include<bits/stdc++.h>
using namespace std;
int rep[30];
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
    int tcase=1;
    char s[10],x;
    scanf("%d\n",&tcase);
    for(int test=1; test<=tcase; test++)
    {
        char ch;
        scanf("%c",&ch);
        int n=ch-'A';
        initial(n);
        while(getchar() != '\n');
        while(gets(s))
        {
            if(s[0]=='\0')
                break;
            int a=s[0]-'A';
            int b=s[1]-'A';
            union_node(a,b);
        }
        set<int>se;
        for(int i=0; i<=n; i++)
        {
            int u=find_representative(i);
            se.insert(u);
        }
        int ans=se.size();
        printf("%d\n",ans);
        if(test<tcase)
            puts("");
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


