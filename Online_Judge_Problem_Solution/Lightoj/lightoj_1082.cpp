#include<bits/stdc++.h>
#define mx 100001
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int arr[mx];
int tree[mx * 4];
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = min(tree[Left] , tree[Right]);
    //return tree[node];
}
int query(int node, int b, int e, int i, int j)
{
    if (b > j || e < i)
        return INT_MAX;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return min(p1 , p2);
}
int main()
{
    //;
    int t,cnt=0;
    scanf("%d",&t);
    while(t--){
            memset(arr,0,sizeof(arr));
            memset(tree,0,sizeof(tree));
    int n,q,a,b;
    //cin >> n>> q;
    scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++){
            //cin>>arr[i];
            scanf("%d",&arr[i]);
        }
    init(1, 1, n);
    printf("Case %d:\n",++cnt);
    for(int i=0;i<q;i++){
        //cin>>a>>b;
        scanf("%d%d",&a,&b);
        int x=query(1,1,n,a,b);
        printf("%d\n",x);
       }
    }

    return 0;
}
