class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;

        if (board[r][c] != 'O')
            return;

        // Mark boundary-connected O as safe
        board[r][c] = '#';

        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;

        m = board.size();
        n = board[0].size();

        // Mark all O's connected to the boundary
        for (int r = 0; r < m; r++) {
            dfs(board, r, 0);
            dfs(board, r, n - 1);
        }

        for (int c = 0; c < n; c++) {
            dfs(board, 0, c);
            dfs(board, m - 1, c);
        }

        // Capture surrounded regions
        // and restore safe regions
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                else if (board[r][c] == '#')
                    board[r][c] = 'O';
            }
        }
    }
};