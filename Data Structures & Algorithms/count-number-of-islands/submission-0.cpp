class Solution {
    private:
    void bfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&grid ){
        queue<pair<int,int>>q;
        vis[row][col] = 1;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        while(!q.empty()){
            int nrow = q.front().first;
            int ncol = q.front().second;
            q.pop();
            for(int d = 0; d<4; d++)
            {
                int x = nrow + dx[d];
                int y = ncol + dy[d];

                if(x>=0 && y >= 0 && x<n && y<m && vis[x][y] == 0
                    && grid[x][y] == '1'){
                        vis[x][y] = 1;
                        q.push({x,y});
                    }
            }
            
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int count = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){ 
                    count++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return count;
    }
};
