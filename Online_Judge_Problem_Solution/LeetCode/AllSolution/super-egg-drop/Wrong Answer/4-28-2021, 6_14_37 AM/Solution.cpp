// https://leetcode.com/problems/super-egg-drop

class Solution {
public:
    int superEggDrop(int k, int n) {
        int ans=1;
        //if(n%2!=0)n--;
        for(int i=1;i<=n;i++){
            int num=i,cnt=0,tm_k=k;
            int left=1,right=n;
            int ck=0;
            while(left<=right&&tm_k>1){
                int mid=(left+right)/2;
                if(mid>num){
                    tm_k--;
                    right=mid-1;
                    ck=1;
                }
                else{
                    left=mid+1;
                }
                ck=0;
                cnt++;
            } 
            if(i==right&&ck)cnt-=1;
            cnt+=i-left+1;
            //cout<<i<<" "<<cnt<<" \n";
            ans=max(ans,cnt);
        }
        return ans;
    }
};