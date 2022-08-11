// https://leetcode.com/problems/candy

class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans=1,pre=1,cnt=1;
        int n=ratings.size();
        for(int i=1;i<n;i++){
            if(ratings[i]<ratings[i-1]){
                if(pre==1){
                    ans+=1;
                    ans+=cnt;
                }
                else{
                    pre=1;
                    ans+=pre;
                }
                cnt++;
            }
            else if(ratings[i]>ratings[i-1]){
                pre+=1;
                ans+=pre;
                cnt=1;
            }
            else{
                pre=1;
                ans+=pre;
                cnt=1;
            }
        }
        return ans;
    }
};