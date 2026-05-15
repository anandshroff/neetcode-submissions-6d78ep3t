class Solution {
private: 
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, int &p){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int d = 0; d<4; d++){
            int nr = row + dx[d];
            int nc = col + dy[d];
            if(nr>=0 && nc>=0 && nr<n && nc<m ){
                if(grid[nr][nc] == 0){
                    p++;
                }
                else if(!vis[nr][nc])
                dfs(nr, nc, grid, vis, p);
            }
            else{
                    p++;
                
            }
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row, col;
        row = grid.size();
        col = grid[0].size();
        int p = 0;

        vector<vector<int>>vis(row, vector<int>(col, 0));

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    dfs(i, j, grid, vis, p);
                }
            }
        }
        return p;
    }
};