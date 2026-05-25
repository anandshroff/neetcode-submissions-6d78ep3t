class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>&vis){
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int d=0; d<4; d++){
            int r = row + dx[d];
            int c = col + dy[d];

            if(r>=0 && c>=0 && r<n && c<m && board[r][c] == 'O' && !vis[r][c]){
                dfs(r, c, board, vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>>vis(rows, vector<int>(cols, 0));

        for(int i=0; i<cols; i++){
            if(!vis[0][i] && board[0][i] == 'O')
                dfs(0, i, board, vis);

            if(!vis[rows-1][i] && board[rows-1][i] == 'O')
                dfs(rows-1, i, board, vis);
        }
        for(int i=0; i<rows; i++){
            if(!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0, board, vis);

            if(!vis[i][cols-1] && board[i][cols-1] == 'O')
                dfs(i, cols-1, board, vis);
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
