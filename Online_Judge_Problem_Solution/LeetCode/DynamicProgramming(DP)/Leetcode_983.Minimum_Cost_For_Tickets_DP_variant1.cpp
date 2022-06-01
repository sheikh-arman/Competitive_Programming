/*
    Sk arman Hossain
    University of Barisal

    Problem : Leetcode_983.Minimum_Cost_For_Tickets
    Solution : Dynamic Programming(Recursive)
 */
class Solution
{
public:
    typedef long long int ll ;
#define N 400
    ll dp[N+10];
ll day[10]={1,7,30};
ll cost[10];
ll ar[N+10],n;
ll ticket_cost(ll i){
    if(i>365){
            return dp[i]=0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    ll ans1=LONG_MAX;
    ll ans2=LONG_MAX;
    ll ans3=LONG_MAX;
    if(ar[i]){
        ans1=cost[0]+ticket_cost(i+1);
        ans2=cost[1]+ticket_cost(i+7);
        ans3=cost[2]+ticket_cost(i+30);
    }
    else{
        ans1=ticket_cost(i+1);
    }
    return  dp[i]=min(ans1,min(ans2,ans3));
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
            ar[days[i]]=1;
        }
        for(ll i=0;i<=366;i++){
                dp[i]=-1;
        }
        ll ans=ticket_cost(1);
        return (int)ans;
    }
};

