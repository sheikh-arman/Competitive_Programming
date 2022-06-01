/*
    Sk arman Hossain
    University of Barisal

    Problem : LeetCode-> 646. Maximum Length of Pair Chain
    Solution : Dynamic Programming
 */

class Solution
{
public:
    int dp[200000];
    int lis(int pos,vector<pair<int,int>>& pairs)
    {
        if(dp[pos]!=-1)
        {
            return dp[pos];
        }
        int siz=pairs.size();
        int ans=0;
        for(int j=pos+1; j<siz; j++)
        {
            if(pairs[j].first>pairs[pos].second)
            {
                ans=max(ans,lis(j,pairs));
            }
        }
        dp[pos]=ans+1;
        return dp[pos];
    }
    int findLongestChain(vector<vector<int>>& pairs)
    {
        vector<pair<int,int>>V;
        int siz1=pairs.size();
        for(int i=0;i<siz1;i++){
            V.push_back({pairs[i][0],pairs[i][1]});
        }
        sort(V.begin(),V.end());
        int siz=V.size();
        for(int i=0; i<siz; i++)dp[i]=-1;
        int ans=0;
        for(int i=0; i<siz; i++)
        {
            ans=max(ans,lis(i,V));
        }
        return ans;
    }
};
