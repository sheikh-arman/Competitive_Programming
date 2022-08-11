// https://leetcode.com/problems/super-egg-drop

class Solution {
public:
    int superEggDrop(int k, int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int num=i,cnt=0;
            int left=1,right=n;
            while(left<=right&&k>1){
                int mid=(left+right)/2;
                if(mid>num){
                    k--;
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
                cnt++;
            }
            if(left<right){
                cnt+=right-left+1;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};