// https://leetcode.com/problems/search-suggestions-system

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> ans;
        int left=0,right=products.size()-1;
        int n=searchWord.size();
       // for(int i=0;i<products.size();i++){
           // cout<<products[i]<<" x\n";
        //}
        for(int i=0;i<n;i++){
            while(left<=right){
                if(products[left].size()<=i){
                    left+=1;
                }
                else{
                    if(products[left][i]!=searchWord[i]){
                        left++;
                    }
                    else{
                        break;
                    }
                }
            }
            while(left<=right){
                if(products[right].size()<=i){
                    right-=1;
                }
                else{
                    if(products[right][i]!=searchWord[i]){
                        right--;
                    }
                    else{
                        break;
                    }
                }
            }
            //cout<<left<<" "<<right<<" t\n";
            int tm_right=3;
            vector<string>V;
            for(int j=left;j<=right&&tm_right>0;j++){
                V.push_back(products[j]);
                tm_right--;
            }
            ans.push_back(V);
        }
        return ans;
    }
};