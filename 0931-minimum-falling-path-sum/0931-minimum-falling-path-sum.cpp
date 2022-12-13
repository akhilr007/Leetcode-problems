class Solution {
public:
    // time complexity -> O(n * 3^n)
    // space complexity -> O(n)
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
    
    // time complexity -> O(n * 3*n*m)
    // space complexity -> O(n*m)
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
    
    int solveTab(vector<vector<int>>& matrix, int n){
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // for row = 0 copy same values of matrix in dp
        for(int i=0; i<n; i++){
            dp[0][i] = matrix[0][i];
        }
        
        for(int row=1; row<n; row++){
            for(int col=0; col<n; col++){
                
                int up=1e8, upLeft=1e8, upRight=1e8;
                if(row-1>=0) up = matrix[row][col] + dp[row-1][col];
                if(row-1>=0 && col-1>=0) upLeft = matrix[row][col] + dp[row-1][col-1];
                if(row-1>=0 && col+1<n) upRight = matrix[row][col] + dp[row-1][col+1]; 
                
                dp[row][col] = min({up, upLeft, upRight});
            }
        }
        
        int res = INT_MAX;
        for(int i=0; i<n; i++){
            res = min(res, dp[n-1][i]);
        }
        
        return res;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        return solveTab(matrix, n);
    }
};