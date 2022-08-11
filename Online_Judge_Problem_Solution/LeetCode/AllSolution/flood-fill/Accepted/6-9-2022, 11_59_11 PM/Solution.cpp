// https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int save=image[sr][sc];
        if(save==newColor){
            return image;
        }
        while(!q.empty()){
            int u=q.front().first;
            int v=q.front().second;
            image[u][v]=newColor;
            q.pop();
            for(int i=0;i<4;i++){
                int cu=u+dx[i];
                int cv=v+dy[i];
                if(cu<n&&cu>=0&&cv<m&&cv>=0){
                    if(image[cu][cv]==save){
                        q.push({cu,cv});
                    }
                }
            }
        }
        return image;
    }
};