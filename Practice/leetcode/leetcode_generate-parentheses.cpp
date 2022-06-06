class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        int val=pow(2,n*2);
        vector<string>V;
        for(int i=0; i<val; i++)
        {
            int cnt=0,total=0;
            int num=i;
            while(num)
            {
                total++;
                if(num%2!=0)cnt++;
                num/=2;
            }
            if(total==n*2&&cnt==n)
            {
                num=i;
                stack<int>stk;
                int ck=1;
                while(num)
                {
                    int mod=num%2;
                    num/=2;
                    if(mod==0)
                    {
                        stk.push(0);
                    }
                    else
                    {
                        if(stk.empty())
                        {
                            ck=0;
                            break;
                        }
                        else
                        {
                            stk.pop();
                        }
                    }
                }
                if(stk.size())
                {
                    ck=0;
                }
                if(ck)
                {
                    num=i;
                    string s;
                    while(num)
                    {
                        int mod=num%2;
                        num/=2;
                        if(mod==0)
                        {
                            s+='(';
                        }
                        else
                        {
                            s+=')';
                        }
                    }
                    V.push_back(s);
                }
            }

        }
        return V;
    }
};
