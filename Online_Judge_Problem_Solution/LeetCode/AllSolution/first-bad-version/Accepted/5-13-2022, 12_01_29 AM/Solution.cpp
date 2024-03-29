// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int len=n;
        int left=1,right=len;
        int ans=-1;
        while(left<=right){
            int mid=left+((right-left)/2);
            if(isBadVersion(mid)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};