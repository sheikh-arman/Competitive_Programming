// https://leetcode.com/problems/maximal-rectangle

class Solution
{
    typedef long long int ll;
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        ll mat[210][210];
        ll cum_sum[210][210];
        int x=1,y=1;
        ll n,m;
        for(vector<char>i:matrix)
        {
            y=1;
            for(char j:i)
            {
                if(j=='1')
                {
                    mat[x][y]=1;
                }
                else mat[x][y]=-1000000;
                y++;
            }
            m=y-1;
            x++;
        }
        n=x-1;
//        for(ll i=1; i<=n; i++)
//        {
//            for(ll j=1; j<=m; j++)
//            {
//                cout<<mat[i][j]<<" ";
//            }
//            cout<<"\n";
//        }
        for(ll i=0; i<=n; i++)cum_sum[i][0]=0;
        for(ll j=1; j<=m; j++)
        {
            for(ll i=1; i<=n; i++)
            {
                cum_sum[i][j]=cum_sum[i-1][j]+mat[i][j];
            }
        }
        ll ans=0;
        for(ll i=1; i<=n; i++)
        {
            for(ll j=i; j<=n; j++)
            {
                ll sum=0;
                for(ll k=1; k<=m; k++)
                {
                    ll val=cum_sum[j][k]-cum_sum[i-1][k];
                    sum+=val;
                    ans=max(sum,ans);
                    if(sum<0)sum=0;
                }
            }
        }
        return ans;
    }
};