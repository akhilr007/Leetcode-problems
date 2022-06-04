class Solution {
public:
    void solve(vector<vector<char>>& board, int row, int n, vector<bool>& cols, vector<bool>& diagonal, vector<bool>& reverseDiagonal, vector<vector<string>>& res){
        
        if(row == n){
            vector<string> v;
            for(int i=0; i<n; i++){
                string s="";
                for(int j=0; j<n; j++){
                    s += board[i][j];
                }
                v.push_back(s);
            }
            
            res.push_back(v);
            
            return;
        }
        
        for(int col=0; col<n; col++){
            if(cols[col] == false && diagonal[row+col]==false && 
               reverseDiagonal[row-col+n-1] == false)
            {
                board[row][col] = 'Q';
                
                cols[col]=true;
                diagonal[row+col]=true;
                reverseDiagonal[row-col+n-1]=true;
                
                solve(board, row+1, n, cols, diagonal, reverseDiagonal, res);
                
                cols[col]=false;
                diagonal[row+col]=false;
                reverseDiagonal[row-col+n-1]=false;
                
                board[row][col] = '.';
                
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<char>> board(n, vector<char>(n , '.'));
        vector<vector<string>> res;
        
        vector<bool> cols(n, false);
        vector<bool> diagonal(2*n-1, false);
        vector<bool> reverseDiagonal(2*n-1, false);
        
        solve(board, 0, n, cols, diagonal, reverseDiagonal, res);
            
        return res;
    }
};