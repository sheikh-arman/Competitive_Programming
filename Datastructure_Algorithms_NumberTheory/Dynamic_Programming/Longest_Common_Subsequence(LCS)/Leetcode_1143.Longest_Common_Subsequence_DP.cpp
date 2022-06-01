/*
    Sk arman Hossain
    University of Barisal

    Problem: 1143. Longest Common Subsequence
    Solution :  dp
 */
class Solution
{
public:
    typedef long long int ll;
    ll dp[1000][1000],len1,len2;
    string s1,s2;
    ll lcs(ll i,ll j)
    {
        if(i>=len1||j>=len2)
        {
            return dp[i][j]=0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        ll ans1=LONG_MIN,ans2=LONG_MIN,ans3=LONG_MIN;
        if(s1[i]==s2[j])
        {
            ans1=1+lcs(i+1,j+1);
        }
        else
        {
            ans2=lcs(i,j+1);
            ans3=lcs(i+1,j);
        }
        return dp[i][j]=max(ans1,max(ans2,ans3));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        len1=text1.size();
        len2=text2.size();
        s1=text1;
        s2=text2;
        for(ll i=0; i<=len1; i++)
        {
            for(ll j=0; j<=len2; j++)
            {
                dp[i][j]=-1;
            }
        }
        ll ans=lcs(0,0);
        return ans;
    }
};
