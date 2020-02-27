
/*
    Sk arman Hossain
    University of Barisal

    Problem name :uva_p459_Graph Connectivity
    Algorithm :Disjoint set union(dsu)
 */

#include<stdio.h>
#include<string.h>
int rep[30];
int ck[30];
void initial(int n)
{
    for(int i=0; i<=n; i++)
    {
        rep[i]=i;
        ck[i]=0;
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

        memset(ck,0,sizeof(ck));
       // memset(ck,0,sizeof(ck));
        gets(s);
        int n=s[0]-'A';
        initial(n);
        while(gets(s))
        {
            if(s[0]=='\0')
                break;
            int a=s[0]-'A';
            int b=s[1]-'A';
            union_node(a,b);
        }
        for(int i=0; i<=n; i++)
        {
            int u=find_representative(i);
            ck[u]=1;
        }
        int ans=0;
        for(int i=0;i<28;i++)
        {
            if(ck[i])
                ans++;
        }

        printf("%d\n",ans);
        if(test<tcase)
            puts("");
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


