// https://leetcode.com/problems/candy

class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans=1,pre=1;
        int n=ratings.size();
        for(int i=1;i<n;i++){
            if(ratings[i]<ratings[i-1]){
                if(pre==1){
                    ans+=2;
                }
                else{
                    pre=1;
                    ans+=pre;
                }
            }
            else if(ratings[i]>ratings[i-1]){
                pre+=1;
                ans+=pre;
            }
            else{
                pre=1;
                ans+=pre;
            }
        }
        return ans;
    }
};