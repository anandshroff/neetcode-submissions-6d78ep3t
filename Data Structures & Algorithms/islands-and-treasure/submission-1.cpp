class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>>q;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            dist++;
            
            for(int i=0; i<size;i++){ 
                auto [nrow, ncol] = q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int r = nrow + dx[d];
                    int c = ncol + dy[d];

                    if(r>=0 && c>=0 && r<row && c<col && grid[r][c] == INT_MAX){
                        q.push({r,c});
                        grid[r][c] = dist;
                    }
                }
            } 
        }
    }
};
