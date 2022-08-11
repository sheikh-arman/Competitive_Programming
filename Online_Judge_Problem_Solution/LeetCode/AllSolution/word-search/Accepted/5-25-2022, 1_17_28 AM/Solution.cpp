// https://leetcode.com/problems/word-search

class Solution {
public:
    int dx[5]={0,0,1,-1};
    int dy[5]={1,-1,0,0};
    string s;
    int n,m;
    int mem[10][10];
    bool dp(int x,int y,int cnt, vector<vector<char>>& board){
        if(cnt>=s.size()){
            return 1;
        }
        int ans=0;
        mem[x][y]=1;
        for(int i=0;i<4;i++){
            int tm_x=x+dx[i];
            int tm_y=y+dy[i];
            if(tm_x>=0&&tm_x<n&&tm_y>=0&&tm_y<m){
                if(mem[tm_x][tm_y]==0){
                    if(board[tm_x][tm_y]==s[cnt]){
                        mem[tm_x][tm_y]=1;
                        ans|=dp(tm_x,tm_y,cnt+1,board);
                        mem[tm_x][tm_y]=0;
                    }
                }
            }
        }
        mem[x][y]=0;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        s=word;
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mem[i][j]=0;
            }
        }
        int ans=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans==0){
                    if(board[i][j]==s[0]){
                        ans|=dp(i,j,1,board);
                    }
                }
            }
        }
        //cout<<s<<" "<<n<<" "<<m<<" x\n";
        return ans;
    }
    
};