class Solution
{
public:
    int maxProduct(vector<string>& words)
    {
        int siz=words.size();
        int ans=0;
        int n=siz;
        for(int i=0; i<siz-1; i++)
        {
            int ar1[30],ar2[30];
            for(int j=0; j<26; j++)
            {
                ar1[j]=ar2[j]=0;
            }
            for(int j=0; words[i][j]!='\0'; j++)
            {
                ar1[words[i][j]-'a']=1;
            }
            for(int j=i+1; j<n; j++)
            {
                for(int k=0; k<26; k++)
                {
                    ar2[k]=0;
                }
                for(int k=0; words[j][k]!='\0'; k++)
                {
                    ar2[words[j][k]-'a']=1;
                }
                int ck=1;
                for(int k=0; k<26; k++)
                {
                    if(ar1[k]==1&&ar2[k]==1)
                    {
                        ck=0;
                        break;
                    }
                }
                if(ck)
                {
                    ans=max(ans,(int)words[i].size()*(int)words[j].size());
                }
            }
        }
        return ans;
    }
};
