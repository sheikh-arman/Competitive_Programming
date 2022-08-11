// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int>V[30];
        int n=s.size();
        for(int i=0;i<n;i++){
            V[s[i]-'a'].push_back(i);
        }
        n=words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int m=words[i].size();
            int pre=-1;
            int ck=1;
            for(int j=0;j<m;j++){
                int word=words[i][j]-'a';
                int pos=lower_bound(V[word].begin(),V[word].end(),pre+1)-V[word].begin();
                if(pos>=((int)V[word].size())){
                    ck=0;break;
                }
                if(V[word][pos]<=pre){
                    ck=0;break;
                }
                pre=V[word][pos];
            }
            ans+=ck;
        }
        return ans;
    }
};