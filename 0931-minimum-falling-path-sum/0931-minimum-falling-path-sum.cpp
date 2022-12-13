class Solution {
public:
    int solveRec(int row, int col, vector<vector<int>>& matrix){
        
        if(row<0 || row>=matrix.size() || col<0 || col>=matrix[0].size()){
            return 1e8;
        }
        if(row == 0){
            return matrix[row][col];
        }
        
        int up = matrix[row][col] + solveRec(row-1, col, matrix);
        int upLeft = matrix[row][col] + solveRec(row-1, col-1, matrix);
        int upRight = matrix[row][col] + solveRec(row-1, col+1, matrix);
        
        return min({up, upLeft, upRight});
    }
    
    int solveMem(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        
        if(row<0 || row>=matrix.size() || col<0 || col>=matrix[0].size()){
            return 1e8;
        }
        if(row == 0){
            return matrix[row][col];
        }
        if(dp[row][col] != -1) return dp[row][col];
        
        int up = matrix[row][col] + solveMem(row-1, col, matrix, dp);
        int upLeft = matrix[row][col] + solveMem(row-1, col-1, matrix, dp);
        int upRight = matrix[row][col] + solveMem(row-1, col+1, matrix, dp);
        
        return dp[row][col] = min({up, upLeft, upRight});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int res = INT_MAX;
        int n = matrix.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0; i<n; i++){
            res = min(res, solveMem(n-1, i, matrix, dp));
        }
        
        return res;
    }
};