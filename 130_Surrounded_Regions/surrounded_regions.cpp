class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() < 3 || board[0].size() < 3) return;

        int m = board[0].size(), n = board.size();
        for(int i = 0; i < n; ++i){
            if (board[i][0] == 'O'){
                boundaryDFS(board, i, 0);
            }
            if (board[i][m - 1] == 'O') {
                boundaryDFS(board, i, m-1);
            }
        }
        for (int i = 1; i < m - 1; ++i) {
            if(board[0][i] == 'O') {
                boundaryDFS(board, 0, i);
            }
            if (board[n - 1][i] == 'O') {
                boundaryDFS(board, n - 1, i);
            }
        }

        for (int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                board[i][j] = (board[i][j] == '*') ? 'O' : 'X';
            }
        }
    }

    void boundaryDFS(vector<vector<char> > &board, int i, int j) {
        if (i < 0 || i > board.size() - 1 || j <0 || j > board[0].size() - 1)
            return;
        if (board[i][j] == 'O')
            board[i][j] = '*';
        if (i > 1 && board[i-1][j] == 'O')
            boundaryDFS(board, i-1, j);
        if (i < board.size() - 2 && board[i+1][j] == 'O')
            boundaryDFS(board, i+1, j);
        if (j > 1 && board[i][j-1] == 'O')
            boundaryDFS(board, i, j-1);
        if (j < board[i].size() - 2 && board[i][j+1] == 'O' )
            boundaryDFS(board, i, j+1);
    }
};