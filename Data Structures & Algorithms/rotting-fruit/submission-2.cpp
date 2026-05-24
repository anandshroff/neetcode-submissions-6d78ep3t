class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<pair<int, int>, int>>q;
        int t = 0;
        vector<vector<int>>vis(row, vector<int>(col, 0));

        for(int i=0; i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] ==2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while(!q.empty()){
            auto [edge, time] = q.front();
            auto [nr, nc] = edge;
            q.pop();

            for(int d=0;d<4;d++){
                int r = nr + dx[d];
                int c = nc + dy[d];

                if(r>=0 && c >= 0 && r<row && c<col && vis[r][c] != 2 && grid[r][c] == 1){
                    q.push({{r,c}, time+1});
                    vis[r][c] = 2;
                }
            }
        t = max(time, t);
        }
        for(int i=0; i<row; i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1 && vis[i][j] != 2){
                    return -1;
                }
            }
        }
        return t;
    }
};
