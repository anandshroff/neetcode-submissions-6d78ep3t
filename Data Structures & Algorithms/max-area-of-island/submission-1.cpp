class Solution {
private:
    int dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>grid){
        
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        vis[row][col] = 1;
        int count = 1;
       
            for(int d = 0; d<4; d++){
                int x = row + dx[d];
                int y = col + dy[d];
                if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y] == 1)
                {
                    vis[x][y] = 1;
                    count = count + dfs(x, y, vis, grid);
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
                    maxArea = max(maxArea, dfs(i, j, vis, grid));
                }
            }
        }
        return maxArea;
    }
};
