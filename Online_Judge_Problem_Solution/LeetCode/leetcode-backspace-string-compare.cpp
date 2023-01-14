// https://leetcode.com/problems/backspace-string-compare

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int sizs=s.size()-1;
        int sizt=t.size()-1;
        int cnts=0,cntt=0;
        int ck=1;
        while(sizs>=0&&sizt>=0)
        {
           // cout<<" hi \n";
            while(sizs>=0)
            {
                if(s[sizs]=='#')
                {
                    cnts++;
                    sizs--;
                }
                else
                {
                    if(cnts>0)
                    {
                        cnts--;
                        sizs--;
                    }
                    else{
                        break;
                    }
                }
            }
            while(sizt>=0)
            {
                if(t[sizt]=='#')
                {
                    cntt++;
                    sizt--;
                }
                else
                {
                    if(cntt>0)
                    {
                        cntt--;
                        sizt--;
                    }
                    else{
                        break;
                    }
                }
            }
            if(cnts==0&&cntt==0)
            {
                if(sizs>=0&&sizt>=0)
                {
                    if(s[sizs]!='#'&&t[sizt]!='#')
                    {
                        if(s[sizs]!=t[sizt])
                        {
                            ck=0;
                            break;
                        }
                        else
                        {
                            sizs--;
                            sizt--;
                        }
                    }
                }
            }

        }
       while(sizs>=0)
            {
                if(s[sizs]=='#')
                {
                    cnts++;
                    sizs--;
                }
                else
                {
                    if(cnts>0)
                    {
                        cnts--;
                        sizs--;
                    }
                    else{
                        break;
                    }
                }
            }
         while(sizt>=0)
            {
                if(t[sizt]=='#')
                {
                    cntt++;
                    sizt--;
                }
                else
                {
                    if(cntt>0)
                    {
                        cntt--;
                        sizt--;
                    }
                    else{
                        break;
                    }
                }
            }
        if(sizt>=0||sizs>=0)
        {
            ck=0;
        }
        if(ck)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};