class Solution {
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>&vis, queue<pair<int,int>>&q){
        int n = heights.size();
        int m = heights[0].size();
        int dx[4] = {0,1,0,-1};
        int dy[4] = {-1,0,1,0};

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            vis[row][col] = true;
            for(int d=0; d<4; d++){
                int r = row + dx[d];
                int c = col + dy[d];

                if(r>=0 && r<n && c >=0 && c<m && !vis[r][c] 
                && heights[r][c] >= heights[row][col]){
                    q.push({r,c});
                    
                }
            }
        }

    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>>pac(n, vector<bool>(m, false));
        vector<vector<bool>>atl(n, vector<bool>(m, false));
        queue<pair<int,int>>pacQ, atlQ;

        for(int i=0;i<n;i++){
            pacQ.push({i,0});
            atlQ.push({i,m-1});
        }

        for(int i=0;i<m;i++){
            pacQ.push({0,i});
            atlQ.push({n-1,i});
        }

        bfs(heights, pac, pacQ);
        bfs(heights, atl, atlQ);

        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
