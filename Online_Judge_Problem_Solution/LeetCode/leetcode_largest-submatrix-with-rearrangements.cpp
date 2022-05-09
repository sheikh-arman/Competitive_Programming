class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int ar[n+2][m+2];
        for(int i=0;i<m;i++){
            ar[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    ar[i][j]=0;
                }
                else{
                    ar[i][j]=ar[i-1][j]+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>V;
            for(int j=0;j<m;j++){
                if(ar[i][j])
                V.push_back(ar[i][j]);
            }
            sort(V.begin(),V.end());
            int siz=V.size();
            for(int j=0;j<siz;j++){
                int node=siz-j;
                ans=max(ans,node*V[j]);
            }
        }
        return ans;
    }
};