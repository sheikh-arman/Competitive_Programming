// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution
{
public:
    typedef long long int ll ;
#define N 400
    ll dp[N+10][N+10];
    ll day[10]= {1,7,30};
    ll cost[10];
    ll ar[N+10],n;
    ll ticket_cost(ll i,ll current_fill)
    {
        if(i>=n)
        {
            return dp[i][current_fill]=0;
        }
        if(dp[i][current_fill]!=-1)
        {
            return dp[i][current_fill];
        }
        ll ans1=LONG_MAX;
        ll ans2=LONG_MAX;
        ll ans3=LONG_MAX;
        if(current_fill<ar[i])
        {
            ans1=cost[0]+ticket_cost(i+1,ar[i]);
        }
        else
        {
            ans1=ticket_cost(i+1,current_fill);
        }
        if(current_fill<ar[i])
        {
            ans2=cost[1]+ticket_cost(i+1,ar[i]+6);
        }
        else
        {
            ans2=ticket_cost(i+1,current_fill);
        }
        if(current_fill<ar[i])
        {
            ans3=cost[2]+ticket_cost(i+1,ar[i]+29);
        }
        else
        {
            ans3=ticket_cost(i+1,current_fill);
        }
        return  dp[i][current_fill]=min(ans1,min(ans2,ans3));
        // return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        n=days.size();
        cost[0]=costs[0];
        cost[1]=costs[1];
        cost[2]=costs[2];
        for(ll i=0; i<n; i++)
        {
            ar[i]=days[i];
        }
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=ar[n-1]+33; j++)
            {
                dp[i][j]=-1;
            }
        }
        ll ans=ticket_cost(0,0);
        return (int)ans;
    }
};