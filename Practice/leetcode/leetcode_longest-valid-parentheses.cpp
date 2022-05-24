class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int ans=0,current=0,prev=0;
        stack<pair<char,int>>stk;
        vector<int>siz,pos;
        for(int i=0; s[i]!='\0'; i++)
        {
            if(s[i]=='(')
            {
                stk.push({s[i],i});
            }
            else
            {
                if(stk.size()>0)
                {
                    pair<char,int> pa=stk.top();
                    stk.pop();
                    siz.push_back((i-pa.second)+1);
                    pos.push_back(i);
                }
            }
        }
        int si=siz.size();
        if(si>0)
        {
            int pre=pos[si-1]-siz[si-1];
            ans=siz[si-1];
            current=ans;
            for(int i=si-2; i>=0; i--)
            {
                if(pos[i]>pre)
                {
                    continue;
                }
                if(pos[i]==pre)
                {
                    current+=siz[i];
                    pre=pos[i]-siz[i];
                    ans=max(ans,current);
                }
                else
                {
                    pre=pos[i]-siz[i];
                    current=siz[i];
                    ans=max(ans,current);
                }
            }
        }
        return ans;
    }
};
