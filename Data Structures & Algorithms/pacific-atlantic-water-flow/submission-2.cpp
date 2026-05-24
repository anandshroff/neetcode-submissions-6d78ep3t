class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>&vis){
        vis[row][col] = true;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        
            for(int d=0; d<4;d++){
                int nrow = row + dx[d];
                int ncol = col + dy[d];

                if(nrow >= 0 && ncol >= 0 && nrow<heights.size() && ncol<heights[0].size()
                    && !vis[nrow][ncol] && heights[nrow][ncol] >= heights[row][col]){
                        dfs(nrow, ncol, heights, vis);
                    }
            }
        
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>>paci(row, vector<bool>(col,false));
        vector<vector<bool>>atlan(row, vector<bool>(col, false));
      
        for(int i = 0; i<col; i++){
            dfs(0, i, heights, paci);
            dfs(row-1, i, heights, atlan);
        }
        for(int i=0; i<row;i++){
            dfs(i, 0, heights, paci);
            dfs(i, col-1, heights, atlan);
        }

        vector<vector<int>>res;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(paci[i][j] && atlan[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};
