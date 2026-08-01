class Solution {
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>&vis){
        vis[row][col] = true;
        int n = heights.size();
        int m = heights[0].size();
        int dx[4] = {0,1,0,-1};
        int dy[4] = {-1,0,1,0};

        for(int d=0; d<4; d++){
            int r = row + dx[d];
            int c = col + dy[d];

            if(r>=0 && r<n && c >=0 && c<m && !vis[r][c] 
            && heights[r][c] >= heights[row][col]){
                dfs(r,c, heights, vis);
            }
        }

    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>>pac(n, vector<bool>(m, false));
        vector<vector<bool>>atl(n, vector<bool>(m, false));

        for(int i=0;i<n;i++){
            dfs(i,0, heights, pac);
            dfs(i,m-1, heights, atl);
        }

        for(int i=0;i<m;i++){
            dfs(0,i, heights, pac);
            dfs(n-1,i, heights, atl);
        }

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
