class Solution{
public:
    void dfs(int i, int j, vector<vector<char>>& board){

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] == 'V' || board[i][j] == 'X'){
            return;
        }

        board[i][j] = 'V';
        dfs(i-1, j, board);
        dfs(i, j-1, board);
        dfs(i+1, j, board);
        dfs(i, j+1, board);

    }

    void solve(vector<vector<char>>& board){

        int n=board.size();
        int m=board[0].size();

        // first row
        for(int j=0; j<m; j++){
            if(board[0][j] == 'O'){
                dfs(0, j, board);
            }
        }

        // last row
        for(int j=0; j<m; j++){
            if(board[n-1][j] == 'O'){
                dfs(n-1, j, board);
            }
        }

        // first col
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O'){
                dfs(i, 0, board);
            }
        }

        // last col
        for(int i=0; i<n; i++){
            if(board[i][m-1] == 'O'){
                dfs(i, m-1, board);
            }
        }

        // mark all the remaining O's with X
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

        // mark all the V's to O's
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'V'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};