class Solution {
    void dfs(int row, int col, vector<vector<char>>&board){
        board[row][col] = '#';

        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};

        for(int d = 0; d<4; d++){
            int r = row + dx[d];
            int c = col + dy[d];

            if(r>=0 && c>=0 && r<board.size() && c<board[0].size()
                && board[r][c] == 'O'){
                    dfs(r, c, board);
                }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n;i++){
            if(board[i][0] == 'O'){
                dfs(i, 0, board);
            }
            if(board[i][m-1] == 'O'){
                dfs(i,m-1, board);
            }
        }

        for(int i=0;i<m;i++){
            if(board[0][i] == 'O'){
                dfs(0,i,board);
            }
            if(board[n-1][i] == 'O'){
                dfs(n-1,i,board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == '#')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
