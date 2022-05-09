class Solution {
public:
    int mx;
    map<int,int> rep,cnt;
    int Find(int n){
        return (rep[n]==n?n:rep[n]=Find(rep[n]));
    }
    void joint(int u,int v){
        u=Find(u);
        v=Find(v);
        if(u!=v){
            if(cnt[u]>=cnt[v]){
                cnt[u]+=cnt[v];
                mx=max(mx,cnt[u]);
                rep[v]=u;
            }
            else{
                cnt[v]+=cnt[u];
                mx=max(mx,cnt[v]);
                rep[u]=v;
            }
        }
    }
    int longestConsecutive(vector<int>& nums) {
         rep.clear();cnt.clear();
         mx=0;
         if((int)nums.size())mx=1;
         for(int i:nums){
             rep[i]=i;
             cnt[i]=1;
         }   
         for(int i:nums){
             if(cnt[i-1]>0){
                 joint(i-1,i);
             }
             if(cnt[i+1]>0){
                 joint(i+1,i);
             }
         }
         return mx;
    }
};