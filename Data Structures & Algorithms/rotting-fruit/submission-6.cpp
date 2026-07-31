class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        int fresh = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                fresh++;
            }
            
        }

        int dx[4] = {0,1,0,-1};
        int dy[4] = {-1, 0, 1, 0};
        int minTime = 0;
        int steps = 0;
        while(!q.empty() && fresh>0){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto [row, col] = q.front();
                q.pop();

                for(int d=0; d<4; d++){
                    int r = row + dx[d];
                    int c = col + dy[d];

                    if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == 1){
                        grid[r][c] = 2;
                        q.push({r,c});
                        fresh--;
                    }
                }
            }
            steps++;
        }
        
        return fresh == 0?steps:-1;
    }
};
