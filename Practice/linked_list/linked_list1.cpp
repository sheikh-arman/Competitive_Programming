#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define sf(n) scanf("%lld",&n);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define nl cout<<"\n";
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
#define MAX 2000010
#define T(n) printf("test : %d\n",n);
struct node
{
    int roll;
    node *next;
};
node *root=NULL;
void append(int roll)
{
    if(root==NULL)
    {
        root=new node();
        root->roll=roll;
        root->next=NULL;
    }
    else
    {
        node *current_node=root;
        while(current_node->next!=NULL)
        {
            current_node=current_node->next;
        }
        node *new_node=new node();
        new_node->roll=roll;
        new_node->next=NULL;
        current_node->next=new_node;
    }
}
void delete_node(int roll)
{
    node *current_node=root;
    node *previous_node=NULL;
    while(current_node->roll!=roll)
    {
        previous_node=current_node;
        current_node=current_node->next;
    }
    if(current_node==root)
    {
        node *temp=root;
        root=root->next;
        delete(temp);
    }
    else
    {
        previous_node->next=current_node->next;
        delete(current_node);
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        int a[5];
        for(int i=0; i<5; i++)
        {
            printf("%u\n",&(a[i]));
        }

    }
    return 0;
}




