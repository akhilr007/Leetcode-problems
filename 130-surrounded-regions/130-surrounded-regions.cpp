class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board){
        
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c] != 'O'){
            return;
        }
        
        board[r][c] = 'T';
        dfs(r-1, c, board);
        dfs(r, c-1, board);
        dfs(r+1, c, board);
        dfs(r, c+1, board);
    }
    
    void solve(vector<vector<char>>& board) {
        
        int ROWS = board.size();
        int COLS = board[0].size();
        
        // 1. capture the unsurrounded regions
        for(int r=0; r<ROWS; r++){
            for(int c=0; c<COLS; c++){
                if(board[r][c] == 'O' && (r == 0 || r == ROWS-1 || c == 0 || c==COLS-1)){
                    dfs(r, c, board);
                }
            }
        }
        
        // 2. capture the surrounded regions
        for(int r=0; r<ROWS; r++){
            for(int c=0; c<COLS; c++){
                if(board[r][c] == 'O') board[r][c] = 'X';
            }
        }
        
        // 3. uncapture the unsurrounded regions
        for(int r=0; r<ROWS; r++){
            for(int c=0; c<COLS; c++){
                if(board[r][c] == 'T') board[r][c] = 'O';
            }
        }
    }
};