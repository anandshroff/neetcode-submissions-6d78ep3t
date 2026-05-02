class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n;i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int dist = 0;
        while(!q.empty()){
            dist++;
            int size = q.size();
            for(int i=0; i<size; i++){
                auto [row, col] = q.front();
                q.pop();
                for(int d = 0; d<4; d++){
                    int nx = row + dx[d];
                    int ny = col + dy[d];
                    if(nx>=0 && nx<n && ny>=0 && ny<m 
                        && grid[nx][ny] == 2147483647){
                            grid[nx][ny] = dist;
                            q.push({nx,ny});
                        }
                }
            }
        }
    }
};
