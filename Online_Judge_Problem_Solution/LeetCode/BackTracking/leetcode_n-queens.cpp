class Solution {
public:
    int mat[10][10];
    bool isSafe(int i,int j,int n)
    {
        for(int k=0; k<n; k++)
        {
            if(k!=i)
            {
                if(mat[k][j]==1)return false;
            }
        }
        for(int k=0; k<n; k++)
        {
            if(k!=j)
            {
                if(mat[i][k]==1)return false;
            }
        }
        int numi=i-1,numj=j-1;
        while(numi>=0&&numj>=0)
        {
            if(mat[numi][numj]==1)return false;
            numi--;
            numj--;
        }
        numi=i+1;
        numj=j+1;
        while(numi<n&&numj<n)
        {
            if(mat[numi][numj]==1)return false;
            numi++;
            numj++;
        }
        numi=i-1;
        numj=j+1;
        while(numi>=0&&numj<n)
        {
            if(mat[numi][numj]==1)return false;
            numi--;
            numj++;
        }
        numi=i+1;
        numj=j-1;
        while(numi<n&&numj>=0)
        {
            if(mat[numi][numj]==1)return false;
            numi++;
            numj--;
        }
        return true;
    }
    vector<vector<string>>V;
    int backtracking(int i,int n)
    {
        if(i>=n)
        {
            string s;
            vector<string>tm;
            for(int j=0; j<n; j++)
            {
                s.clear();
                for(int k=0; k<n; k++)
                {
                    if(mat[j][k]){
                        s+='Q';
                    }
                    else{
                        s+='.';
                    }
                }
               tm.push_back(s);
            }
            V.push_back(tm);
            return 1;
        }
        int ans=0;
        for(int j=0; j<n; j++)
        {
            if(isSafe(i,j,n))
            {
                mat[i][j]=1;
                ans+=backtracking(i+1,n);
                mat[i][j]=0;
            }
        }
        return ans;
    }
    vector<vector<string>> solveNQueens(int n) {
        int ans=backtracking(0,n);
        return V;
    }
};
