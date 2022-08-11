class Solution
{
public:
    int mirrorReflection(int p, int q)
    {
        int qq=q;
        int ck=0;
        while(q<p)
        {
            q+=qq;
            ck=1-ck;
        }
        if(q!=p)
        {
            return 0;
        }
        else
        {
            if(ck)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }
    };
