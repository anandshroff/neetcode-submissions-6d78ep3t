class Solution {
private:
    int bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>grid){
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        q.push({row, col});
        vis[row][col] = 1;
        int count = 1;
        while(!q.empty()){
            auto [nrow, ncol] = q.front();
            q.pop();

            for(int d = 0; d<4; d++){
                int x = nrow + dx[d];
                int y = ncol + dy[d];

                if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y] == 1)
                {
                    count++;
                    q.push({x,y});
                    vis[x][y] = 1;
                }
            }
        }
        return count;

    }    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int maxArea = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    maxArea = max(maxArea, bfs(i, j, vis, grid));
                }
            }
        }
        return maxArea;
    }
};
