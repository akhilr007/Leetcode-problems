class Solution {
    public void rotate(int[][] matrix) {
        
        for(int i=0; i<matrix.length; i++){
            for(int j=i+1; j<matrix[0].length; j++){
                swap(matrix, i, j);
            }
        }
        
        for(int r=0; r<matrix.length; r++){
            
            int i=0, j=matrix[0].length-1;
            
            while(i < j){
                
                swap(matrix, r, i, j);
                i++;
                j--;
            }
        }
    }
    
    private void swap(int[][] matrix, int r, int i, int j){
        
        int temp = matrix[r][i];
        matrix[r][i] = matrix[r][j];
        matrix[r][j] = temp;
    }
    
    private void swap(int[][] matrix, int i, int j){
        
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
    }
}