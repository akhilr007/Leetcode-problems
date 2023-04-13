class NumMatrix {
    
    int[][] cum_matrix;
    public NumMatrix(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        
        cum_matrix = new int[n][m];
        
        cum_matrix[0][0] = matrix[0][0];
        for(int col=1; col<m; col++){
            cum_matrix[0][col] = cum_matrix[0][col-1] + matrix[0][col];
        }
        
        for(int row=1; row<n; row++){
            cum_matrix[row][0] = cum_matrix[row-1][0] + matrix[row][0];
        }
        
        for(int row=1; row<n; row++){
            for(int col=1; col<m; col++){
                
                cum_matrix[row][col] = matrix[row][col] + cum_matrix[row-1][col] + cum_matrix[row][col-1] - cum_matrix[row-1][col-1];
            }
        }
    }
    
    public int sumRegion(int startRow, int startCol, int endRow, int endCol) {
        
        if(startRow == 0 && startCol == 0){
            return cum_matrix[endRow][endCol];
        }
        else if(startRow == 0){
            return cum_matrix[endRow][endCol] - cum_matrix[endRow][startCol-1];
        }
        else if(startCol == 0){
            return cum_matrix[endRow][endCol] - cum_matrix[startRow-1][endCol];
        }
        else {
            return cum_matrix[endRow][endCol] - cum_matrix[startRow-1][endCol] - cum_matrix[endRow][startCol-1] + cum_matrix[startRow-1][startCol-1];
        }
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */