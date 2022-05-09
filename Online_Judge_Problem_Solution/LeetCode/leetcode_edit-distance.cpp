/*
    Sk arman Hossain
    University of Barisal

    Problem: divide array into k sub array of equal sum
    Solution : bitmask dp
 */
class Solution
{
public:
    typedef long long int ll;
    ll dp[1000][1000],len1,len2;
    string s1,s2;
    ll edit_distance(ll i,ll j)
    {
        if(i>=len1||j>=len2)
        {
            return dp[i][j]=max(len1-i,len2-j);
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        ll ans1=LONG_MAX,ans2=LONG_MAX,ans3=LONG_MAX;
        if(s1[i]==s2[j])
        {
            ans1=edit_distance(i+1,j+1);
        }
        else
        {
            ans2=1+edit_distance(i+1,j+1);
            ans3=1+edit_distance(i+1,j);
            ans1=1+edit_distance(i,j+1);
        }
        return dp[i][j]=min(ans1,min(ans2,ans3));
    }
    int minDistance(string word1, string word2)
    {
        len1=word1.size();
        len2=word2.size();
        s1=word1;
        s2=word2;
        for(ll i=0; i<=len1; i++)
        {
            for(ll j=0; j<=len2; j++)
            {
                dp[i][j]=-1;
            }
        }
        ll ans=edit_distance(0,0);
        return ans;
    }
};
