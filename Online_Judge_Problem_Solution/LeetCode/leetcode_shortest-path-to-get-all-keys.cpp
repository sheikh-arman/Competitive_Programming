/*
    Sk arman Hossain
    University of Barisal

    Problem : 864. Shortest Path to Get All Keys
    Dificulty: Hard
    Solution : BFS + Bitmask DP
 */
class Solution
{
public:
    int shortestPathAllKeys(vector<string>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        int key=0;
        int startx,starty;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]>='a'&&grid[i][j]<='z')
                {
                    int val=grid[i][j]-'a';
                    key=max(key,val);
                }
                if(grid[i][j]=='@')
                {
                    startx=i;
                    starty=j;
                }
            }
        }
        int mem[n+10][m+10][(1<<key+1)+10];
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                for(int k=0; k<(1<<key+1)+5; k++)
                {
                    mem[i][j][k]=-1;
                }
            }
        }
        int ans=999999;
        queue<pair<pair<int,int>,int>>qu;
        qu.push({{startx,starty},0});
        int dx[]= {-1,1,0,0};
        int dy[]= {0,0,-1,1};
        grid[startx][starty]='.';
        mem[startx][starty][0]=0;
        while(!qu.empty())
        {
            pair<pair<int,int>,int> parent=qu.front();
            qu.pop();
            int x=parent.first.first;
            int y=parent.first.second;
            int mask=parent.second;
            if(mask==(1<<(key+1))-1)
            {
                ans=min(ans,mem[x][y][mask]);
                continue;
            }
            for(int i=0; i<4; i++)
            {
                int childx=x+dx[i];
                int childy=y+dy[i];
                if(childx>=0&&childx<n&&childy>=0&&childy<m)
                {
                    if(grid[childx][childy]!='#')
                    {
                        if(grid[childx][childy]=='.')
                        {
                            if(mem[childx][childy][mask]==-1)
                            {
                                mem[childx][childy][mask]=mem[x][y][mask]+1;
                                qu.push({{childx,childy},mask});
                            }
                            else
                            {
                                if(mem[childx][childy][mask]>mem[x][y][mask]+1)
                                {
                                    mem[childx][childy][mask]=mem[x][y][mask]+1;
                                    qu.push({{childx,childy},mask});
                                }
                            }
                        }
                        else
                        {
                            if(grid[childx][childy]>='a'&&grid[childx][childy]<='z')
                            {
                                int val=grid[childx][childy]-'a';
                                int new_mask=mask|(1<<val);
                                if(mem[childx][childy][new_mask]==-1)
                                {
                                    mem[childx][childy][new_mask]=mem[x][y][mask]+1;
                                    qu.push({{childx,childy},new_mask});
                                }
                                else
                                {
                                    if(mem[childx][childy][new_mask]>mem[x][y][mask]+1)
                                    {
                                        mem[childx][childy][new_mask]=mem[x][y][mask]+1;
                                        qu.push({{childx,childy},new_mask});
                                    }
                                }
                            }
                            else
                            {
                                int val=grid[childx][childy]-'A';
                                int ck=(mask&(1<<val));
                                if(ck)
                                {
                                    if(mem[childx][childy][mask]==-1)
                                    {
                                        mem[childx][childy][mask]=mem[x][y][mask]+1;
                                        qu.push({{childx,childy},mask});
                                    }
                                    else
                                    {
                                        if(mem[childx][childy][mask]>mem[x][y][mask]+1)
                                        {
                                            mem[childx][childy][mask]=mem[x][y][mask]+1;
                                            qu.push({{childx,childy},mask});
                                        }
                                    }
                                }

                            }
                        }
                    }
                }
            }
        }
        if(ans==999999)ans=-1;
        return ans;
    }
};
