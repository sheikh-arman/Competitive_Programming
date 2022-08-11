// https://leetcode.com/problems/furthest-building-you-can-reach

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int>st;
        int sum=0,pos=0;
        int n=heights.size();
        for(int i=1;i<n;i++){
            if(heights[i]>heights[i-1]){
                st.insert(heights[i]-heights[i-1]);
                if((int)st.size()>ladders){
                    sum+=*st.begin();
                    st.erase(st.begin());
                }
                if(sum>bricks){
                    break;
                }
            }
            pos=i;
        }
        return pos;
    }
};