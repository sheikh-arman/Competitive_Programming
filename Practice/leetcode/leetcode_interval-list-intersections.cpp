class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList)
    {
        int sizfirst=firstList.size();
        int sizsecond=secondList.size();
        int left=0,right=0;
        vector<vector<int>> ans;
        while(left<sizfirst&&right<sizsecond)
        {
            int firstx=firstList[left][0];
            int firsty=firstList[left][1];

            int secondx=secondList[right][0];
            int secondy=secondList[right][1];

            if(firstx>secondy||secondx>firsty)
            {
                if(firsty<secondy)
                {
                    left++;
                }
                else if(firsty>secondy)
                {
                    right++;
                }
            }
            else
            {
                int mi=max(firstx,secondx);
                int ma=min(firsty,secondy);
                vector<int>V;
                V.push_back(mi);
                V.push_back(ma);
                ans.push_back(V);
                if(firsty<secondy)
                {
                    left++;
                }
                else if(firsty>secondy)
                {
                    right++;
                }
                else
                {
                    left++;
                    right++;
                }
            }
        }
        return ans;
    }
};
