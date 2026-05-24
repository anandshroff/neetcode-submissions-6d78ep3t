class Solution {
private:
    void bfs(queue<pair<int,int>>&q, vector<vector<int>>& heights, vector<vector<bool>>&vis){

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            vis[row][col] = true;
            for(int d=0; d<4;d++){
                int nrow = row + dx[d];
                int ncol = col + dy[d];

                if(nrow >= 0 && ncol >= 0 && nrow<heights.size() && ncol<heights[0].size()
                    && !vis[nrow][ncol] && heights[nrow][ncol] >= heights[row][col]){
                        q.push({nrow, ncol});
                    }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>>paci(row, vector<bool>(col,false));
        vector<vector<bool>>atlan(row, vector<bool>(col, false));
        queue<pair<int,int>>pacQ, atlQ;
        for(int i = 0; i<col; i++){
            pacQ.push({0, i});
            atlQ.push({row-1, i});
        }
        for(int i=0; i<row;i++){
            pacQ.push({i, 0});
            atlQ.push({i, col-1});
        }

        bfs(pacQ, heights, paci);
        bfs(atlQ, heights, atlan);

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
