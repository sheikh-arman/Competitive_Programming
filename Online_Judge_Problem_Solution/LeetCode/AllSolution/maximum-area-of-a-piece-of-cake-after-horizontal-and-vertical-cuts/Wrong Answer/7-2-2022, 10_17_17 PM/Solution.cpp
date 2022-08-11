// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long hor=0,ver=0,pre=0,ans;
        int n=horizontalCuts.size();
        for(int i=0;i<n;i++){
            hor=max(hor,horizontalCuts[i]-pre);
            pre=horizontalCuts[i];
        }
        hor=max(hor,(long long)(w-pre));
        n=verticalCuts.size();
        pre=0;
        for(int i=0;i<n;i++){
            ver=max(ver,(long long)(verticalCuts[i]-pre));
            pre=verticalCuts[i];
        }
        ver=max(ver,(long long)(h-pre));
        ans=ver*hor;
        ans%=1000000007;
        return (int)ans;
    }
};