// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int sol(vector<int>& height){
        int ans=0;
        vector<pair<int,int> >V;
        int n=height.size();
        for(int i=0;i<n;i++){
            V.push_back({height[i],i});
            
        }
        sort(V.begin(),V.end());
        
        int ar[10010];ar[n]=0;
        int ma=0;
        for(int i=0;i<n;i++){
            ar[V[i].first]=V[i].second;
        }
        for(int i=V[n-1].first;i>=0;i--){
            ma=max(ma,ar[i]);
            ar[i]=ma;
        }
        for(int i=0;i<n;i++){
            ans=max(ans,abs(i-ar[height[i]])*height[i]);
           // cout<<i<<" "<<ans<<" ";
        }
        return ans;
    }
    int maxArea(vector<int>& height) {
        int ans=0;
        ans=sol(height);
       // cout<<ans<<" x\n";
        reverse(height.begin(),height.end());
        ans=max(ans,sol(height));
        //cout<<sol(height)<<" x\n";
        return ans;
    }
};