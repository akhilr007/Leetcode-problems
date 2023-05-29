class Solution {
    public void swap(int i, int j, int[][] matrix){
        
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
    }
    
    public void reverse(int row, int[][] matrix){
        
        int i=0;
        int j=matrix.length-1;
        
        while(i<j){
            
            int temp = matrix[row][i];
            matrix[row][i] = matrix[row][j];
            matrix[row][j] = temp;
            
            i++;
            j--;
        }
    }
    
    public void rotate(int[][] matrix) {
        
        int n = matrix.length;
        
        // transpose the matrix
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(i, j, matrix);
            }
        }
        
        // revere the row;
        for(int i=0; i<n; i++){
            
            reverse(i, matrix);
        }
    }
}