class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        
        int n = mat.length;
        int m = mat[0].length;
        
        int[] res = new int[n*m];
        
        int i=0;
        int row = 0, col = 0;
        boolean up = true;
        
        while(row < n && col < m){
            
            if(up){
                while(row > 0 && col < m-1){
                    res[i++] = mat[row][col];
                    row--;
                    col++;
                }
                res[i++] = mat[row][col];
                if(col == m-1){
                    row++;
                }
                else{
                    col++;
                }
            }
            else{
                while(col > 0 && row < n-1){
                    res[i++] = mat[row][col];
                    row++;
                    col--;
                }
                res[i++] = mat[row][col];
                if(row == n-1){
                    col++;
                }
                else{
                    row++;
                }
            }
            
            up = !up;
        }
        return res;
    }
}