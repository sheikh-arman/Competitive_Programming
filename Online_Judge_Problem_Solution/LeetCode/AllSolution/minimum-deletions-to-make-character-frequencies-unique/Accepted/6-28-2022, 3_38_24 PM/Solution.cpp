// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique

class Solution {
public:
    int minDeletions(string s) {
        int ar[30];
        for(int i=0;i<26;i++){
            ar[i]=0;
        }
        for(int i=0;s[i]!='\0';i++){
            ar[s[i]-'a']++;
        }
        vector<pair<int,int>>V;
        for(int i=0;i<26;i++){
            if(ar[i]>0){
                V.push_back({ar[i],i});
            }
        }
        
        sort(V.begin(),V.end());
        int n=V.size();
        int pre=V[n-1].first,ans=0;
        for(int i=n-2;i>=0;i--){
            pre--;
            if(V[i].first>pre){
                pre=max(pre,0);
                ans+=V[i].first-pre;
            }
            else{
                pre=V[i].first;
            }
            
        }
        return ans;
    }
};