class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>, int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        int time = 0;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        while(!q.empty()){
            auto [p, t] = q.front();
            auto [row, col] = p;
            q.pop();
            for(int i = 0; i<4; i++){
                int nx = row + dx[i];
                int ny = col + dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]
                   && grid[nx][ny] == 1){
                    q.push({{nx, ny}, t+1});
                    vis[nx][ny] = 2;
                   } 
            }
        time = max(time, t);
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};
