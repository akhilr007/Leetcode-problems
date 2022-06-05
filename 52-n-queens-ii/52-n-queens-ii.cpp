class Solution {
public:
    
    bool isSafe(vector<bool>& cols, vector<bool>& reverseDiagonal, vector<bool>& diagonal, int row, int col){
        
        if(cols[col] == true){
            return false;
        }

        if(diagonal[row + col] == true){
            return false;
        }
        
        if(reverseDiagonal[row-col+cols.size()] == true){
            return false;
        }
        
        return true;
    }
    
    void solve(vector<vector<char>>& board, int row, vector<vector<string>>& ans,
        vector<bool>& cols, vector<bool>& diagonal, vector<bool>& reverseDiagonal){
        
        if(row == board.size()){
            vector<string> v;
            for(int i=0; i<board.size(); i++){
                string s="";
                for(int j=0; j<board.size(); j++){
                    s += board[i][j];
                }
                v.push_back(s);
            }
            ans.push_back(v);
            return;
        }
        
        for(int col=0; col<board.size(); col++){
            
            if(isSafe(cols, reverseDiagonal, diagonal, row, col)){
                board[row][col] = 'Q';
                
                cols[col] = true;
                diagonal[row+col] = true;
                reverseDiagonal[row-col+board.size()] = true;
                
                solve(board, row+1, ans, cols, diagonal, reverseDiagonal);
                
                board[row][col] = 'Q';
                cols[col] = false;
                diagonal[row+col] = false;
                reverseDiagonal[row-col+board.size()] = false;
                
                board[row][col] = '.';
            }
        }
        
    }
    
    int totalNQueens(int n) {
        
        vector<vector<char>> board(n, vector<char> (n, '.'));
        
        vector<vector<string>> ans;
        
        vector<bool> cols(n, false);
        vector<bool> diagonal(2*n-1, false);
        vector<bool> reverseDiagonal(2*n-1, false);
        solve(board, 0, ans, cols, diagonal, reverseDiagonal);
        
        int res = ans.size();
        return res;
    }
};