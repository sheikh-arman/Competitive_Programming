#include<bits/stdc++.h>
using namespace std;
const int MAX =200004;
struct info
{
    int tup[2], indx; ///tup[0] = prev rank, tup[1] = new rank
    bool operator<(const info &a)const
    {
        return tup[0] != a.tup[0]? tup[0] < a.tup[0] : tup[1] < a.tup[1];
    }
} arr[MAX];
int Rank[20][MAX], LCP[MAX], step;
string text;
void build_suffix_array(void)
{
    int n = text.size(), jump;
    for(int j = 0; j < n; j++)
    {
        Rank[0][j] = text[j]; ///rank suffixes according to 1st char
        memset(arr[j].tup, 0,sizeof(arr[j].tup));
    }
    for(step = 1, jump = 1; jump <= n; step++, jump <<= 1)
    {
        for(int j = 0; j <=n; j++)
        {
            arr[j].indx = j;
            arr[j].tup[0] = Rank[step - 1][j]; /// what i was in prev step
            arr[j].tup[1] = j + jump < n? Rank[step - 1][j + jump] : -1;
        }
        sort(arr, arr + n);
        Rank[step][arr[0].indx] = 0;
        for(int j = 1; j < n; j++)
            Rank[step][arr[j].indx] = arr[j].tup[0] == arr[j - 1].tup[0] &&
                                      arr[j].tup[1] == arr[j - 1].tup[1] ? Rank[step][arr[j - 1].indx] : j;
    }
}
int pos,ma;
void build_LCP_array(void)
{
    LCP[0] = 0;
    int n = text.size(), i, j, id1, id2;
    for(i = 1; i < n; i++)
    {
        id1 = arr[i - 1].indx;
        id2 = arr[i].indx;
        LCP[i] = 0;
        for(j = step - 1; j >= 0; j--)
            if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2])
            {
                LCP[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
    }
    ma=0;
    for(i = 1; i < n; i++)
    {
        int half=(n/2)-1;
        if((arr[i-1].indx<half&&arr[i].indx>half)||(arr[i-1].indx>half&&arr[i].indx<half))
        {
            if(LCP[i]>ma)
            {
                ma=LCP[i];
                pos=min(arr[i-1].indx,arr[i].indx);
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    pos=10000000;
    string s1,s2;
    cin>>s1>>s2;
    text=s1;
    text+='$';
    text+=s2;
    text+='#';
    build_suffix_array();
    build_LCP_array();
    s2.clear();
    for(int i=pos; i<(pos+ma)&&i<n; i++)s2+=s1[i];
    cout<<s2<<"\n";
    return 0;
}


