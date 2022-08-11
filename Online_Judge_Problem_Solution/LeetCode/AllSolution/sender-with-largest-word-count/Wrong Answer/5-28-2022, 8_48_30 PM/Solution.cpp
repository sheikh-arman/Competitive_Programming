// https://leetcode.com/problems/sender-with-largest-word-count

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n=messages.size();
        map<string,int>mp;
        for(int i=0;i<n;i++){
            int siz=messages[i].size();
            mp[senders[i]]+=siz;
        }
        vector<pair<int,string>>V;
        for(int i=0;i<n;i++){
            if(mp[senders[i]]!=-1){
                V.push_back({mp[senders[i]],senders[i]});
                 mp[senders[i]]=-1;
            }
        }
        sort(V.begin(),V.end());
        n=V.size();
        return V[n-1].second;
    }
};