class Solution {
    void better(int[][] matrix){
        
        int n = matrix.length;
        int m = matrix[0].length;
        
        int[] row = new int[n];
        int[] col = new int[m];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(row[i] == 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    
    void optimal(int[][] matrix){
        
        int n = matrix.length;
        int m = matrix[0].length;
        
        // col = row[0] -> matrix[0][..]
        // row = col[0] -> matrix[..][0]
        
        int col0 = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(matrix[i][j] == 0){
                    
                    // mark the ith row
                    matrix[i][0] = 0;
                    
                    // mark the col
                    if(j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }
        
        for(int i=1; i<n; i++){
            
            for(int j=1; j<m; j++){
                
                if(matrix[i][j] != 0){
                    
                    if(matrix[i][0] == 0 || matrix[0][j] == 0){
                        
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        
        if(matrix[0][0] == 0){
            for(int j=0; j<m; j++)
                matrix[0][j] = 0;
        }
        
        if(col0 == 0){
            for(int i=0; i<n; i++){
                matrix[i][0] = 0;
            }
        }
    }
    
    public void setZeroes(int[][] matrix) {
        optimal(matrix);
    }
}