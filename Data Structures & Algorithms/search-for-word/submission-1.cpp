class Solution {
    bool dfs(int row, int col, vector<vector<char>>& board, int i, string &word){
        int n = board.size();
        int m = board[0].size();
        
        if(i == word.size())
            return true;
        char temp = board[row][col];
        board[row][col] = '#';
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int d = 0; d<4; d++){
            int nrow = row + dx[d];
            int ncol = col + dy[d];

            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && board[nrow][ncol] == word[i]){
                if(dfs(nrow, ncol, board, i+1, word)){
                    board[row][col] = temp;
                    return true;
                }
            }
        }
        board[row][col] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(dfs(i, j, board, 1, word)) return true;
                }
            }
        }
        return false;
    }
};
