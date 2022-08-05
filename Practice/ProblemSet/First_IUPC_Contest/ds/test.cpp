class Solution
{
public:
    int candy(vector<int>& ratings)
    {

        int n=ratings.size();
        int ar[n];
        int rev[n];
        for(int i=0; i<n; i++)
        {
            ar[i]=rev[i]=0;
        }
        int cnt=1;
        for(int i=0; i<n; i++)
        {
            if(i>0)
            {
                if(ar[i]>ar[i-1])
                {
                    cnt++;
                }
                else
                {
                    cnt=1;
                }
            }
            ar[i]=cnt;
        }
        cnt=1;
        rev[n-1]=1;
        for(int i=n-2; i>=0; i--)
        {
            if(rev[i]>rev[i+1])
            {
                cnt++;
            }
            else
            {
                cnt=1;
            }
            rev[i]=cnt;
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            ans+=max(ar[i],rev[i]);
        }
        return ans;
    }
};
