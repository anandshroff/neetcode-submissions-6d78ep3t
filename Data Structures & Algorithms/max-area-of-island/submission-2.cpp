class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>>&vis, int &area){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int i=0; i<4;i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0
                    && grid[nrow][ncol] == 1){
                        area++;
                        dfs(nrow, ncol, grid, vis, area);
                    }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>>vis(row, vector<int>(col, 0));

        int maxArea = 0;
        
        for(int i = 0; i<row;i++){
            for(int j = 0; j<col; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    int area = 1;
                    dfs(i, j, grid, vis, area);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};
