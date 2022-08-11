// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int sol(vector<int>& height){
        int ans=0;
        vector<pair<int,int> >V;
        int n=height.size();
        for(int i=0;i<n;i++){
            V.push_back({height[i],i});
           // cout<<height[i]<<" ";
        }
        sort(V.begin(),V.end());
        int ar[10010];for(int i=0;i<=10000;i++)ar[i]=0;
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
            //cout<<i<<" "<<ar[height[i]]<<" "<<abs(i-ar[height[i]])*height[i]<<" \n";
        }
        return ans;
    }
    int maxArea(vector<int>& height) {
        int ans=0;
        ans=sol(height);
       // cout<<ans<<" x\n";
        reverse(height.begin(),height.end());
        int ans2=sol(height);
        //cout<<ans2<<" x\n";
        ans=max(ans,ans2);
        return ans;
    }
};