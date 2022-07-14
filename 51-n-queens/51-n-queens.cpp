class Solution {
public:
    void solve(vector<vector<char>>& board, int row, int n, vector<bool>& cols, vector<bool>& pdiagonals, vector<bool>& rdiagonals, vector<vector<string>>& result){
        
        if(row == n){
            
            vector<string> v;
            for(int i=0; i<board.size(); i++){
                string s = "";
                for(int j=0; j<board[0].size(); j++){
                    s += board[i][j];
                }
                v.push_back(s);
            }
            
            result.push_back(v);
            return;
        }
        
        for(int col=0; col<n; col++){
            if(cols[col] == false && pdiagonals[row+col] == false && rdiagonals[row-col+n-1] == false){
                board[row][col] = 'Q';
                
                cols[col] = true;
                pdiagonals[row + col] = true;
                rdiagonals[row - col + n - 1] = true;
                
                solve(board, row+1, n, cols, pdiagonals, rdiagonals, result);
                
                cols[col] = false;
                pdiagonals[row + col] = false;
                rdiagonals[row - col + n - 1] = false;
                
                board[row][col] = '.';
             }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<char>> board(n, vector<char> (n, '.'));
        vector<vector<string>> result;
        
        vector<bool> cols(n, false);
        vector<bool> pdiagonals(2*n-1, false);
        vector<bool> rdiagonals(2*n-1, false);
        
        solve(board, 0, n, cols, pdiagonals, rdiagonals, result);
        return result;
    }
};